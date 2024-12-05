cmake_minimum_required(VERSION 3.5)

set(This Homework5)
project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)

set(Sources
    homework5.cpp
)

add_library(${This} STATIC ${Sources})