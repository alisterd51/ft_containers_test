#!/usr/bin/env sh

######################################################################
# @author      : anclarma (anclarma@$HOSTNAME)
# @file        : test
# @created     : Monday May 09, 2022 00:40:28 CEST
#
# @description : 
######################################################################

mkdir debug
cd debug
# for intel oneapi:
#  CC=icx CXX=icx
# for clang:
#  CC=clang CXX=clang++
# for gcc:
#  CC=gcc CXX=g++
CC=clang CXX=clang++ cmake ..
cmake --build .
./stack_test
./vector_test
