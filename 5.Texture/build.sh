#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
cp texture_demo ..
cp texture_muti_demo ..