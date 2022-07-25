-- Tags: distributed, no-parallel

CREATE DATABASE IF NOT EXISTS shard_0;
CREATE DATABASE IF NOT EXISTS shard_1;
CREATE DATABASE IF NOT EXISTS d;
DROP TABLE IF EXISTS shard_0.test_data;
DROP TABLE IF EXISTS shard_1.test_data;
DROP TABLE IF EXISTS d.test;

CREATE TABLE shard_0.test_data(v UInt64) ENGINE = Memory();
CREATE TABLE shard_1.test_data(v UInt64) ENGINE = Memory();
INSERT INTO shard_0.test_data SELECT * FROM numbers(10);
INSERT INTO shard_1.test_data SELECT * FROM numbers(10);
CREATE TABLE d.test AS shard_0.test_data ENGINE = Distributed(test_cluster_two_shards_different_databases, '', 'test_data');


SELECT DISTINCT (v) FROM d.test WHERE v IN (SELECT test_data.v FROM test_data) GROUP BY v ORDER BY v;

DROP TABLE IF EXISTS shard_0.test_data;
DROP TABLE IF EXISTS d.test;

DROP DATABASE shard_0;
DROP DATABASE shard_1;
DROP DATABASE d;
