#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
cp light_pong ..