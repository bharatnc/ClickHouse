#include <Storages/System/StorageSystemFactory.h>
#include <Storages/System/registerSystemStorages.h>

namespace DB
{
void registerStorageSystemOne(StorageSystemFactory & factory);
void registerStorageSystemNumbers(StorageSystemFactory & factory);
void registerStorageSystemZeros(StorageSystemFactory & factory);
void registerStorageSystemDatabases(StorageSystemFactory & factory);
void registerStorageSystemTables(StorageSystemFactory & factory);
void registerStorageSystemColumns(StorageSystemFactory & factory);
void registerStorageSystemFunctions(StorageSystemFactory & factory);
void registerStorageSystemEvents(StorageSystemFactory & factory);
void registerStorageSystemSettings(StorageSystemFactory & factory);
void registerStorageSystemServerSettings(StorageSystemFactory & factory);
void registerStorageSystemSettingsChanges(StorageSystemFactory & factory);
void registerStorageSystemBuildOptions(StorageSystemFactory & factory);
void registerStorageSystemFormats(StorageSystemFactory & factory);
void registerStorageSystemTableFunctions(StorageSystemFactory & factory);
void registerStorageSystemAggregateFunctionCombinators(StorageSystemFactory & factory);
void registerStorageSystemDataTypeFamilies(StorageSystemFactory & factory);
void registerStorageSystemCollations(StorageSystemFactory & factory);
void registerStorageSystemDatabaseEngines(StorageSystemFactory & factory);
void registerStorageSystemTableEngines(StorageSystemFactory & factory);
void registerStorageSystemContributors(StorageSystemFactory & factory);
void registerStorageSystemUsers(StorageSystemFactory & factory);
void registerStorageSystemRoles(StorageSystemFactory & factory);
void registerStorageSystemGrants(StorageSystemFactory & factory);
void registerStorageSystemRoleGrants(StorageSystemFactory & factory);
void registerStorageSystemCurrentRoles(StorageSystemFactory & factory);
void registerStorageSystemEnabledRoles(StorageSystemFactory & factory);
void registerStorageSystemSettingsProfiles(StorageSystemFactory & factory);
void registerStorageSystemSettingsProfileElements(StorageSystemFactory & factory);
void registerStorageSystemRowPolicies(StorageSystemFactory & factory);
void registerStorageSystemQuotas(StorageSystemFactory & factory);
void registerStorageSystemQuotaLimits(StorageSystemFactory & factory);
void registerStorageSystemQuotaUsage(StorageSystemFactory & factory);
void registerStorageSystemQuotasUsage(StorageSystemFactory & factory);
void registerStorageSystemUserDirectories(StorageSystemFactory & factory);
void registerStorageSystemPrivileges(StorageSystemFactory & factory);
void registerStorageSystemErrors(StorageSystemFactory & factory);
void registerStorageSystemWarnings(StorageSystemFactory & factory);
void registerStorageSystemDataSkippingIndices(StorageSystemFactory & factory);
void registerStorageSystemLicenses(StorageSystemFactory & factory);
void registerStorageSystemTimeZones(StorageSystemFactory & factory);
void registerStorageSystemBackups(StorageSystemFactory & factory);
void registerStorageSystemSchemaInferenceCache(StorageSystemFactory & factory);
void registerStorageSystemDroppedTables(StorageSystemFactory & factory);
void registerStorageSystemScheduler(StorageSystemFactory & factory);
#if defined(__ELF__) && !defined(OS_FREEBSD)
void registerStorageSystemSymbols(StorageSystemFactory & factory);
#endif
#if USE_RDKAFKA
void registerStorageSystemKafkaConsumers(StorageSystemFactory & factory);
#endif
#ifdef OS_LINUX
void registerStorageSystemStackTrace(StorageSystemFactory & factory);
#endif
#if USE_ROCKSDB
void registerStorageSystemRocksDB(StorageSystemFactory & factory);
#endif
#if USE_MYSQL
void registerStorageSystemMySQLBinlogs(StorageSystemFactory & factory);
#endif
void registerStorageSystemParts(StorageSystemFactory & factory);
void registerStorageSystemProjectionParts(StorageSystemFactory & factory);
void registerStorageSystemDetachedParts(StorageSystemFactory & factory);
void registerStorageSystemPartsColumns(StorageSystemFactory & factory);
void registerStorageSystemProjectionPartsColumns(StorageSystemFactory & factory);
void registerStorageSystemDisks(StorageSystemFactory & factory);
void registerStorageSystemStoragePolicies(StorageSystemFactory & factory);
void registerStorageSystemProcesses(StorageSystemFactory & factory);
void registerStorageSystemMetrics(StorageSystemFactory & factory);
void registerStorageSystemMerges(StorageSystemFactory & factory);
void registerStorageSystemMoves(StorageSystemFactory & factory);
void registerStorageSystemMutations(StorageSystemFactory & factory);
void registerStorageSystemReplicas(StorageSystemFactory & factory);
void registerStorageSystemReplicationQueue(StorageSystemFactory & factory);
void registerStorageSystemDDLWorkerQueue(StorageSystemFactory & factory);
void registerStorageSystemDistributionQueue(StorageSystemFactory & factory);
void registerStorageSystemDictionaries(StorageSystemFactory & factory);
void registerStorageSystemModels(StorageSystemFactory & factory);
void registerStorageSystemClusters(StorageSystemFactory & factory);
void registerStorageSystemGraphite(StorageSystemFactory & factory);
void registerStorageSystemMacros(StorageSystemFactory & factory);
void registerStorageSystemReplicatedFetches(StorageSystemFactory & factory);
void registerStorageSystemPartMovesBetweenShards(StorageSystemFactory & factory);
void registerStorageSystemAsynchronousInserts(StorageSystemFactory & factory);
void registerStorageSystemFilesystemCache(StorageSystemFactory & factory);
void registerStorageSystemQueryCache(StorageSystemFactory & factory);
void registerStorageSystemRemoteDataPaths(StorageSystemFactory & factory);
void registerStorageSystemCertificates(StorageSystemFactory & factory);
void registerStorageSystemNamedCollections(StorageSystemFactory & factory);
void registerStorageSystemAsyncLoader(StorageSystemFactory & factory);
void registerStorageSystemUserProcesses(StorageSystemFactory & factory);
void registerStorageSystemJemallocBins(StorageSystemFactory & factory);
void registerStorageSystemS3Queue(StorageSystemFactory & factory);
void registerStorageSystemDashboards(StorageSystemFactory & factory);
void registerStorageSystemViewRefreshes(StorageSystemFactory & factory);
void registerStorageSystemZooKeeper(StorageSystemFactory & factory);
void registerStorageSystemZooKeeperConnection(StorageSystemFactory & factory);
void registerStorageSystemTransactions(StorageSystemFactory & factory);
void registerStorageSystemAsynchronousMetrics(StorageSystemFactory & factory);

void registerSystemStorages()
{
    auto & factory = StorageSystemFactory::instance();

    registerStorageSystemOne(factory);
    registerStorageSystemNumbers(factory);
    registerStorageSystemZeros(factory);
    registerStorageSystemDatabases(factory);
    registerStorageSystemTables(factory);
    registerStorageSystemColumns(factory);
    registerStorageSystemFunctions(factory);
    registerStorageSystemEvents(factory);
    registerStorageSystemSettings(factory);
    registerStorageSystemServerSettings(factory);
    registerStorageSystemSettingsChanges(factory);
    registerStorageSystemBuildOptions(factory);
    registerStorageSystemFormats(factory);
    registerStorageSystemTableFunctions(factory);
    registerStorageSystemAggregateFunctionCombinators(factory);
    registerStorageSystemDataTypeFamilies(factory);
    registerStorageSystemCollations(factory);
    registerStorageSystemDatabaseEngines(factory);
    registerStorageSystemTableEngines(factory);
    registerStorageSystemContributors(factory);
    registerStorageSystemUsers(factory);
    registerStorageSystemRoles(factory);
    registerStorageSystemGrants(factory);
    registerStorageSystemRoleGrants(factory);
    registerStorageSystemCurrentRoles(factory);
    registerStorageSystemEnabledRoles(factory);
    registerStorageSystemSettingsProfiles(factory);
    registerStorageSystemSettingsProfileElements(factory);
    registerStorageSystemRowPolicies(factory);
    registerStorageSystemQuotas(factory);
    registerStorageSystemQuotaLimits(factory);
    registerStorageSystemQuotaUsage(factory);
    registerStorageSystemQuotasUsage(factory);
    registerStorageSystemUserDirectories(factory);
    registerStorageSystemPrivileges(factory);
    registerStorageSystemErrors(factory);
    registerStorageSystemWarnings(factory);
    registerStorageSystemDataSkippingIndices(factory);
    registerStorageSystemLicenses(factory);
    registerStorageSystemTimeZones(factory);
    registerStorageSystemBackups(factory);
    registerStorageSystemSchemaInferenceCache(factory);
    registerStorageSystemDroppedTables(factory);
    registerStorageSystemScheduler(factory);
#if defined(__ELF__) && !defined(OS_FREEBSD)
    registerStorageSystemSymbols(factory);
#endif
#if USE_RDKAFKA
    registerStorageSystemKafkaConsumers(factory);
#endif
#ifdef OS_LINUX
    registerStorageSystemStackTrace(factory);
#endif
#if USE_ROCKSDB
    registerStorageSystemRocksDB(factory);
#endif
#if USE_MYSQL
    registerStorageSystemMySQLBinlogs(factory);
#endif
    registerStorageSystemParts(factory);
    registerStorageSystemProjectionParts(factory);
    registerStorageSystemDetachedParts(factory);
    registerStorageSystemPartsColumns(factory);
    registerStorageSystemProjectionPartsColumns(factory);
    registerStorageSystemDisks(factory);
    registerStorageSystemStoragePolicies(factory);
    registerStorageSystemProcesses(factory);
    registerStorageSystemMetrics(factory);
    registerStorageSystemMerges(factory);
    registerStorageSystemMoves(factory);
    registerStorageSystemMutations(factory);
    registerStorageSystemReplicas(factory);
    registerStorageSystemReplicationQueue(factory);
    registerStorageSystemDDLWorkerQueue(factory);
    registerStorageSystemDistributionQueue(factory);
    registerStorageSystemDictionaries(factory);
    registerStorageSystemModels(factory);
    registerStorageSystemClusters(factory);
    registerStorageSystemGraphite(factory);
    registerStorageSystemMacros(factory);
    registerStorageSystemReplicatedFetches(factory);
    registerStorageSystemPartMovesBetweenShards(factory);
    registerStorageSystemAsynchronousInserts(factory);
    registerStorageSystemFilesystemCache(factory);
    registerStorageSystemQueryCache(factory);
    registerStorageSystemRemoteDataPaths(factory);
    registerStorageSystemCertificates(factory);
    registerStorageSystemNamedCollections(factory);
    registerStorageSystemAsyncLoader(factory);
    registerStorageSystemUserProcesses(factory);
    registerStorageSystemJemallocBins(factory);
    registerStorageSystemS3Queue(factory);
    registerStorageSystemDashboards(factory);
    registerStorageSystemViewRefreshes(factory);
    registerStorageSystemZooKeeper(factory);
    registerStorageSystemZooKeeperConnection(factory);
    registerStorageSystemTransactions(factory);
    registerStorageSystemAsynchronousMetrics(factory);
}

}
