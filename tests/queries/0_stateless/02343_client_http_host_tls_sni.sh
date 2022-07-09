#!/usr/bin/env bash

CURDIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
# shellcheck source=../shell_config.sh
. "$CURDIR"/../shell_config.sh

${CLICKHOUSE_CURL} -sS "${CLICKHOUSE_URL}" -d 'SELECT 1'  -H "Host: clickhouse.com"
${CLICKHOUSE_CURL} -sS -d --resolve 'localhost:8123:127.0.0.1' 'http://localhost:8123?query=SELECT%201' -H "Host: clickhousesni.com"
${CLICKHOUSE_CLIENT} --query "SYSTEM FLUSH LOGS"
${CLICKHOUSE_CLIENT} --query "SELECT http_host FROM system.query_log WHERE http_host LIKE '%clickhouse%' LIMIT 1"
${CLICKHOUSE_CLIENT} --query "SELECT tls_sni FROM system.query_log WHERE http_host LIKE '%clickhousesni%' LIMIT 1"
