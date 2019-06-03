cmake_minimum_required(VERSION 3.9)
project(ms_arraylist C)

set(CMAKE_C_STANDARD 99)

include_directories(inc)

add_executable(ms_arraylist test/test.c src/arraylist.c inc/arraylist.h test/findpos.c)