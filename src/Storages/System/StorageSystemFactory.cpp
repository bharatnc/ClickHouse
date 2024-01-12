#include <Storages/System/StorageSystemFactory.h>

namespace DB
{
void StorageSystemFactory::attach()
{
}

StorageSystemFactory & StorageSystemFactory::instance()
{
    static StorageSystemFactory fact;
    return fact;
}

void StorageSystemFactory::registerSystemStorage(const String & name, CreatorFn creator_fn)
{
    if (!system_storages.emplace(name, std::move(creator_fn)).second)
        throw Exception(ErrorCodes::LOGICAL_ERROR, "SystemStorageFactory: the system storage name '{}' is not unique", name);
}

}
