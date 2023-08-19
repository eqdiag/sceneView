#!/bin/sh

mkdir build
cmake -S . -B build -DASSIMP_INSTALL=NO
cd build
