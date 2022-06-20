#pragma once

#include <base/sort.h>

#include <Common/HashTable/HashMap.h>
#include <Common/NaNUtils.h>


namespace DB
{
struct Settings;

namespace ErrorCodes
{
    extern const int NOT_IMPLEMENTED;
}

/** Calculates quantile by counting number of occurrences for each value in a hash map.
  *
  * It uses O(distinct(N)) memory. Can be naturally applied for values with weight.
  * In case of many identical values, it can be more efficient than QuantileExact even when weight is not used.
  */
template <typename Value>
struct QuantileApproximateWeighted
{
    struct Int128Hash
    {
        size_t operator()(Int128 x) const
        {
            return CityHash_v1_0_2::Hash128to64({x >> 64, x & 0xffffffffffffffffll});
        }
    };

    using Weight = UInt64;
    using UnderlyingType = NativeType<Value>;
    using Hasher = std::conditional_t<std::is_same_v<Value, Decimal128>, Int128Hash, HashCRC32<UnderlyingType>>;

    /// When creating, the hash table must be small.
    using Map = HashMapWithStackMemory<UnderlyingType, Weight, Hasher, 4>;

    Map map;

    void add(const Value & x)
    {
        /// We must skip NaNs as they are not compatible with comparison sorting.
        if (!isNaN(x))
            ++map[x];
    }

    void add(const Value & x, Weight weight)
    {
        if (!isNaN(x))
            map[x] += weight;
    }

    void merge(const QuantileApproximateWeighted & rhs)
    {
        for (const auto & pair : rhs.map)
            map[pair.getKey()] += pair.getMapped();
    }

    void serialize(WriteBuffer & buf) const
    {
        map.write(buf);
    }

    void deserialize(ReadBuffer & buf)
    {
        typename Map::Reader reader(buf);
        while (reader.next())
        {
            const auto & pair = reader.get();
            map[pair.first] = pair.second;
        }
    }

    /// Get the value of the `level` quantile. The level must be between 0 and 1.
    Value get(Float64 level) const
    {
        size_t size = map.size();

        if (0 == size)
            return std::numeric_limits<Value>::quiet_NaN();

        /// Copy the data to a temporary array to get the element you need in order.
        using Pair = typename std::pair<UnderlyingType, Weight>;
        std::unique_ptr<Pair[]> array_holder(new Pair[size]);
        Pair * array = array_holder.get();

        /// Note: 64-bit integer weight can overflow.
        /// We do some implementation specific behaviour (return approximate or garbage results).
        /// Float64 is used as accumulator here to get approximate results.
        /// But weight can be already overflowed in computations in 'add' and 'merge' methods.
        /// It will be reasonable to change the type of weight to Float64 in the map,
        /// but we don't do that for compatibility of serialized data.

        size_t i = 0;
        Float64 sum_weight = 0;
        for (const auto & pair : map)
        {
            sum_weight += pair.getMapped();
            auto value = pair.getKey();
            auto weight = pair.getMapped();
            array[i] = std::pair(value, weight);
            ++i;
        }

        ::sort(array, array + size, [](const Pair & a, const Pair & b) { return a.first < b.first; });

        Float64 accumulated = 0;

        std::vector<Float64> cum_sum_array;
        std::vector<Float64> sample_weights;
        std::vector<UnderlyingType> values;

        const Pair * it = array;
        const Pair * end = array + size;
        bool first = true;
        while (it < end)
        {
            accumulated += it->second;
            sample_weights.push_back(it->second);
            values.push_back(it->first);

            if (first)
            {
                cum_sum_array.push_back(it->second);
                first = false;
            }
            else
            {
                cum_sum_array.push_back(accumulated);
            }

            ++it;
        }

        if (it == end)
            --it;
        std::vector<Float64> weighted_quantile;


        /// weighted_quantile = cum_sum_arr - (0.5 * sample_weights)
        for (size_t idx = 0; idx < sample_weights.size(); ++idx)
        {
            sample_weights[idx] *= 0.5;
            auto res = cum_sum_array[idx] - sample_weights[idx];
            res /= sum_weight;
            weighted_quantile.push_back(res);
        }

        /// linear interpolation
        UnderlyingType g;

        size_t idx = 0;
        if (level >= weighted_quantile[size - 2])
        {
            idx = size - 2;
        }
        else
        {
            while (level > weighted_quantile[idx + 1])
                idx++;
        }

        Float64 xl = weighted_quantile[idx], xr = weighted_quantile[idx + 1];
        UnderlyingType yl = values[idx], yr = values[idx + 1];

        if (level < xl)
            yr = yl;
        if (level > xr)
            yl = yr;

        auto dydx = (yr - yl) / (xr - xl);
        g = yl + dydx * (level - xl);

        return g;
    }


    /// Get the `size` values of `levels` quantiles. Write `size` results starting with `result` address.
    /// indices - an array of index levels such that the corresponding elements will go in ascending order.
    void getMany(const Float64 * levels, const size_t * indices, size_t num_levels, Value * result) const
    {
        size_t size = map.size();

        if (0 == size)
        {
            for (size_t i = 0; i < num_levels; ++i)
                result[i] = Value();
            return;
        }

        /// Copy the data to a temporary array to get the element you need in order.
        using Pair = typename std::pair<UnderlyingType, Weight>;
        std::unique_ptr<Pair[]> array_holder(new Pair[size]);
        Pair * array = array_holder.get();

        size_t i = 0;
        Float64 sum_weight = 0;
        for (const auto & pair : map)
        {
            sum_weight += pair.getMapped();
            auto value = pair.getKey();
            auto weight = pair.getMapped();
            array[i] = std::pair(value, weight);
            ++i;
        }

        ::sort(array, array + size, [](const Pair & a, const Pair & b) { return a.first < b.first; });

        Float64 accumulated = 0;
        std::vector<Float64> cum_sum_array;
        std::vector<Float64> sample_weights;
        std::vector<UnderlyingType> values;

        const Pair * it = array;
        const Pair * end = array + size;
        bool first = true;
        while (it < end)
        {
            accumulated += it->second;
            sample_weights.push_back(it->second);
            values.push_back(it->first);

            if (first)
            {
                cum_sum_array.push_back(it->second);
                first = false;
            }
            else
            {
                cum_sum_array.push_back(accumulated);
            }
            ++it;
        }

        std::vector<Float64> weighted_quantile;

        /// weighted_quantile = cum_sum_arr - (0.5 * sample_weights)
        for (size_t idx = 0; idx < sample_weights.size(); ++idx)
        {
            sample_weights[idx] *= 0.5;
            auto res = cum_sum_array[idx] - sample_weights[idx];
            res /= sum_weight;
            weighted_quantile.push_back(res);
        }

        size_t level_index = 0;

        while (level_index < num_levels)
        {
            /// linear interpolation for every level
            UnderlyingType g;
            auto level = levels[indices[level_index]];
            size_t idx = 0;
            if (level >= weighted_quantile[size - 2])
            {
                idx = size - 2;
            }
            else
            {
                while (level > weighted_quantile[idx + 1])
                    idx++;
            }

            Float64 xl = weighted_quantile[idx], xr = weighted_quantile[idx + 1];
            UnderlyingType yl = values[idx], yr = values[idx + 1];

            if (level < xl)
                yr = yl;
            if (level > xr)
                yl = yr;

            auto dydx = (yr - yl) / (xr - xl);
            g = yl + dydx * (level - xl);

            result[indices[level_index]] = g;
            ++level_index;
        }
    }

    /// The same, but in the case of an empty state, NaN is returned.
    Float64 getFloat(Float64) const
    {
        throw Exception("Method getFloat is not implemented for QuantileApproximateWeighted", ErrorCodes::NOT_IMPLEMENTED);
    }

    void getManyFloat(const Float64 *, const size_t *, size_t, Float64 *) const
    {
        throw Exception("Method getManyFloat is not implemented for QuantileExact", ErrorCodes::NOT_IMPLEMENTED);
    }
};

}
