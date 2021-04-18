#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
cp coordinate ..
cp cube1 ..
cp cube2 ..