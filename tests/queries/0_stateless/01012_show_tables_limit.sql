SET allow_table_engine_tinylog=1;

CREATE TABLE {CLICKHOUSE_DATABASE:Identifier}.test1 (test UInt8) ENGINE = TinyLog;
CREATE TABLE {CLICKHOUSE_DATABASE:Identifier}.test2 (test UInt8) ENGINE = TinyLog;
CREATE TABLE {CLICKHOUSE_DATABASE:Identifier}.test3 (test UInt8) ENGINE = TinyLog;
CREATE TABLE {CLICKHOUSE_DATABASE:Identifier}.test4 (test UInt8) ENGINE = TinyLog;
CREATE TABLE {CLICKHOUSE_DATABASE:Identifier}.test5 (test UInt8) ENGINE = TinyLog;
CREATE TABLE {CLICKHOUSE_DATABASE:Identifier}.test6 (test UInt8) ENGINE = TinyLog;

SELECT '*** Should show 6: ***';
SHOW TABLES FROM {CLICKHOUSE_DATABASE:Identifier};
SELECT '*** Should show 2: ***';
SHOW TABLES FROM {CLICKHOUSE_DATABASE:Identifier} LIMIT 2;
SELECT '*** Should show 4: ***';
SHOW TABLES FROM {CLICKHOUSE_DATABASE:Identifier} LIMIT 2 * 2;

