#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
cp glm_demo ..
cd ..
./glm_demo