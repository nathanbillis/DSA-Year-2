cmake_minimum_required(VERSION 3.12)
project(Lists C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lists
        arrayList.c
        list.h
        main.c)
