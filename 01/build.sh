#!/bin/sh

set -x

clang++ \
-g \
-std=c++23 \
-Wall \
-Wpedantic \
-Werror \
main.cc
