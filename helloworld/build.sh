#!/bin/bash

mkdir -p cmake_build
cd cmake_build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make