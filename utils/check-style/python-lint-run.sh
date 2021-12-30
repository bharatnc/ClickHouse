#!/usr/bin/env bash

# Script uses pyflakes (https://pypi.org/project/pyflakes/) to lint integration test python files.
# This does basic checks for unused headers, unused variables, etc.
# Note: Unlike pylint or flake8, pyflakes ignores stylistic checks but is faster. If stylistic checks
# are needed later, flake8 can be used (it combines pyflakes with style checks against PEP8) in place.

ROOT_PATH=$(git rev-parse --show-toplevel)
TARGET_DIR="$ROOT_PATH/tests/integration/"

# exclude `f-string` initially (ignore lint for SQL strings inside python files) for now.
find $TARGET_DIR -name "*.py" | xargs pyflakes | grep -v "f-string is missing placeholders"
