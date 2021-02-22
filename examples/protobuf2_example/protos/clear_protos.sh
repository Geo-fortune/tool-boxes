#!/usr/bin/env bash

set -e

cd "$(dirname "$0")"
echo "Removing old protos from $(dirname "$0")"

find . -name "*.pb.cc"
find . -name "*.pb.cc" -delete
find . -name "*.pb.h"
find . -name "*.pb.h" -delete


