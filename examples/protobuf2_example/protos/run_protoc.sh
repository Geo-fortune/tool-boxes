#!/usr/bin/env bash

set -e

cd "$(dirname "$0")"
echo "Compiling protos in $(pwd)"

protoc -I=. --cpp_out=. *.proto
echo 'Done'
