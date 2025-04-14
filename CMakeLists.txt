cmake_minimum_required(VERSION 3.30)
project(lab6)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp
        Parser.cpp
        Parser.h
        Bin_heap.h)

target_compile_options(main PRIVATE -fopenmp -g -ggdb -Werror -Wall -pedantic
        -Wnull-dereference -Wextra -Wshadow -Wnon-virtual-dtor
        -finput-charset=UTF-8 -Weffc++)# enable UTF-8 support for GCC
