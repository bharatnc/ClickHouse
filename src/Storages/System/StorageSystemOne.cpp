#include <Common/Exception.h>

#include <DataTypes/DataTypesNumber.h>
#include <Processors/Sources/SourceFromSingleChunk.h>
#include <QueryPipeline/Pipe.h>
#include <Storages/System/StorageSystemFactory.h>
#include <Storages/System/StorageSystemOne.h>


namespace DB
{


StorageSystemOne::StorageSystemOne(const StorageID & table_id_)
    : IStorage(table_id_)
{
    StorageInMemoryMetadata storage_metadata;
    storage_metadata.setColumns(ColumnsDescription({{"dummy", std::make_shared<DataTypeUInt8>()}}));
    setInMemoryMetadata(storage_metadata);
}


Pipe StorageSystemOne::read(
    const Names & column_names,
    const StorageSnapshotPtr & storage_snapshot,
    SelectQueryInfo &,
    ContextPtr /*context*/,
    QueryProcessingStage::Enum /*processed_stage*/,
    const size_t /*max_block_size*/,
    const size_t /*num_streams*/)
{
    storage_snapshot->check(column_names);

    Block header{ColumnWithTypeAndName(
            DataTypeUInt8().createColumn(),
            std::make_shared<DataTypeUInt8>(),
            "dummy")};

    auto column = DataTypeUInt8().createColumnConst(1, 0u)->convertToFullColumnIfConst();
    Chunk chunk({ std::move(column) }, 1);

    return Pipe(std::make_shared<SourceFromSingleChunk>(std::move(header), std::move(chunk)));
}

void registerStorageSystemOne(StorageSystemFactory & factory)
{
    auto create_fn = [](const StorageSystemFactory::Arguments & args)
    {
        return std::make_shared<StorageSystemOne>(args.table_id);
    };
    factory.registerSystemStorage("StorageSystemOne", create_fn);
}
}
