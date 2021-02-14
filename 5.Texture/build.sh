#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
cp texture_demo ..

# run target
cd ..
./texture_demo
