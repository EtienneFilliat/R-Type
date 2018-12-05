#!/bin/sh

mkdir -p build; cd build && conan install .. --build=missing  -s compiler.libcxx=libstdc++11 && cmake -DCMAKE_BUILD_TYPE=Debug .. && cmake --build  . -- -j 3

cp ./r-type_client ..

cp ./r-type_server ..