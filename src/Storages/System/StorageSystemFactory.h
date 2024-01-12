#pragma once

#include <Storages/IStorage.h>

namespace DB
{
class StorageSystemFactory : private boost::noncopyable
{
public:

    static StorageSystemFactory & instance();
    void attach();
    struct Arguments
    {
        const StorageID & table_id;
        bool multi_threaded;
        std::optional<UInt64> limit = std::nullopt;
        UInt64 offset = 0;
    };
    using StoragePtr = std::shared_ptr<IStorage>;
    using CreatorFn = std::function<StoragePtr(const Arguments & args)>;
    using SystemStorages = std::unordered_map<String, CreatorFn>;
    void registerSystemStorage(const String & name, CreatorFn creator_fn);

private:
    SystemStorages system_storages;
};

}
