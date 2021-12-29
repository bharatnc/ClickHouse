#include "config_functions.h"

#if USE_H3

#include <Columns/ColumnArray.h>
#include <Columns/ColumnTuple.h>
#include <Columns/ColumnsNumber.h>
#include <Functions/FunctionFactory.h>
#include <Functions/IFunction.h>
#include <DataTypes/DataTypeArray.h>
#include <DataTypes/DataTypeTuple.h>
#include <DataTypes/DataTypesNumber.h>
#include <Functions/FunctionHelpers.h>

#include <h3api.h>
#include <constants.h>

static constexpr size_t MAX_ARRAY_SIZE = 1 << 30;

namespace DB
{
namespace ErrorCodes
{
    extern const int ILLEGAL_TYPE_OF_ARGUMENT;
    extern const int INCORRECT_DATA;
    extern const int ARGUMENT_OUT_OF_BOUND;
    extern const int TOO_LARGE_ARRAY_SIZE;
    extern const int TOO_FEW_ARGUMENTS_FOR_FUNCTION;

}

class FunctionH3CompactCells : public IFunction
{
public:
    static constexpr auto name = "h3CompactCells";
    String getName() const override { return name; }

    static FunctionPtr create(ContextPtr) { return std::make_shared<FunctionH3CompactCells>(); }

    size_t getNumberOfArguments() const override { return 2; }

    bool useDefaultImplementationForConstants() const override { return true; }

    bool isSuitableForShortCircuitArgumentsExecution(const DataTypesWithConstInfo & /*arguments*/) const override { return true; }

    DataTypePtr getReturnTypeImpl(const DataTypes & arguments) const override
    {
        if (arguments.size() < 2)
        {
            throw Exception("Too few arguments", ErrorCodes::TOO_FEW_ARGUMENTS_FOR_FUNCTION);
        }

        /* Function is invoked as: h3CompactCells([h3Index1,...,h3Indexn], numCells)
         * */
        const auto * array_type = typeid_cast<const DataTypeArray *>(arguments[0].get());

        if (!array_type)
            throw Exception(
                ErrorCodes::ILLEGAL_TYPE_OF_ARGUMENT,
                "Illegal type {} of argument {} of function {}. Must be Array<UInt64>",
                arguments[0]->getName(),
                1,
                getName());

        // TODO: validate array

        if (!(WhichDataType(arguments[1].get()).isUInt8()))
            throw Exception(
                ErrorCodes::ILLEGAL_TYPE_OF_ARGUMENT,
                "Illegal type {} of argument {} of function {}. Must be UInt8",
                arguments[1]->getName(),
                2,
                getName());

        return std::make_shared<DataTypeArray>(std::make_shared<DataTypeUInt64>());
    }

    ColumnPtr executeImpl(const ColumnsWithTypeAndName & arguments, const DataTypePtr &, size_t input_rows_count) const override
    {
        const auto * col_h3_indices = arguments[0].column.get();
        const auto * col_num_cells = arguments[1].column.get();

        auto dst = ColumnArray::create(ColumnUInt64::create());
        auto & dst_data = dst->getData();
        auto & dst_offsets = dst->getOffsets();
        dst_offsets.resize(input_rows_count);

        auto current_offset = 0;
        std::vector<H3Index> h3_compacted_indices_vec;

        for (size_t row = 0; row < input_rows_count; ++row)
        {
            const auto uncompacted_indices = checkAndGetColumn<ColumnArray>(col_h3_indices[row]);
            const auto num_cells = col_num_cells->getUInt(row);

            size_t hex_count = maxGridDiskSize(num_cells);

            if (hex_count > MAX_ARRAY_SIZE)
                throw Exception(
                    ErrorCodes::TOO_LARGE_ARRAY_SIZE,
                    "The result of function {} (array of {} elements) will be too large with resolution argument = {}",
                    getName(),
                    toString(uncompacted_indices->size()),
                    toString(uncompacted_indices));

            h3_compacted_indices_vec.resize(hex_count);
            std::cerr << "[INDEX]" << toString(uncompacted_indices) << std::endl;
            auto error_code
                = compactCells(reinterpret_cast<const H3Index *>(uncompacted_indices), h3_compacted_indices_vec.data(), hex_count);
            if (error_code != E_SUCCESS)
                throw "Error";


            dst_data.reserve(dst_data.size() + hex_count);
            for (auto hindex : h3_compacted_indices_vec)
            {
                if (hindex != 0)
                {
                    current_offset++;
                    dst_data.insert(hindex);
                }
            }
            dst_offsets[row] = current_offset;
            h3_compacted_indices_vec.clear();
        }

        return dst;
    }
};

void registerFunctionH3CompactCells(FunctionFactory & factory)
{
    factory.registerFunction<FunctionH3CompactCells>();
}

}

#endif
