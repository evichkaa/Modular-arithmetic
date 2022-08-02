cmake_minimum_required(VERSION 3.8)
project(modular_arithmetic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp functions.cpp functions.h)
add_executable(modular_arithmetic ${SOURCE_FILES})