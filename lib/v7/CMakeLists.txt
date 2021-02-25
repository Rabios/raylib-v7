cmake_minimum_required(VERSION 3.1)
project(v7 LANGUAGES C)
set(CMAKE_C_STANDARD 99)

add_library(v7 STATIC)
target_sources(v7
    PRIVATE
   "${CMAKE_CURRENT_SOURCE_DIR}/v7.c"
   "${CMAKE_CURRENT_SOURCE_DIR}/v7.h"
)
