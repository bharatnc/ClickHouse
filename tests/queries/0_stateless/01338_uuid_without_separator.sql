SELECT toUUID('417ddc5de5564d2795dda34d84e46a50');
SELECT toUUID('417ddc5d-e556-4d27-95dd-a34d84e46a50');

DROP TABLE IF EXISTS t_uuid;

SET allow_table_engine_tinylog=1;

CREATE TABLE t_uuid (x UInt8, y UUID, z String) ENGINE = TinyLog;

INSERT INTO t_uuid VALUES (1, '417ddc5de5564d2795dda34d84e46a50', 'Example 1');
INSERT INTO t_uuid VALUES (2, '417ddc5d-e556-4d27-95dd-a34d84e46a51', 'Example 2');

SELECT * FROM t_uuid ORDER BY x ASC;
DROP TABLE IF EXISTS t_uuid;
