#! /bin/bash

# Author: Joseph Lisee <jlisee@gmail.com>
# License: BSD (see LICENSE in root)

#ITERATIONS=10000000000 # ~4.5 seconds
ITERATIONS=1000000000 # ~2 seconds
#ITERATIONS=100000000 # 0.2 seconds

# Build
mkdir -p build
cd build
cmake ..
make -j4
cd ..

# Timing
function bench_prog()
{
    btime=$((time $1 $ITERATIONS) 2>&1 | grep real | awk '{print $2}')
}

# Template
bench_prog ./build/template

echo "TEMPLATE:         $btime"

# Virtual
bench_prog ./build/virtual

echo "VIRTUAL:          $btime"

# Structured
bench_prog ./build/structured

echo "STRUCTURED:       $btime"

# Unity Virtual
bench_prog ./build/unity_virtual

echo "UNITY VIRTUAL:    $btime"

# Unity Structured
bench_prog ./build/unity_structured

echo "UNITY STRUCTURED: $btime"