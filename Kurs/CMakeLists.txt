cmake_minimum_required(VERSION 3.8)
project(Kurs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp radix_test.cpp radix_test.h arr.cpp arr.h)
add_executable(Kurs ${SOURCE_FILES})