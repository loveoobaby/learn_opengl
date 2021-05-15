#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
make
cp camera_base ..
cp camera_keyboard ..
cp camera_class ..