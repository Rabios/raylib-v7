cmake_minimum_required(VERSION 3.1)
project(miniz LANGUAGES C)
set(CMAKE_C_STANDARD 99)

add_library(miniz STATIC)
target_sources(miniz
    PRIVATE
   "${CMAKE_CURRENT_SOURCE_DIR}/miniz.c"
   "${CMAKE_CURRENT_SOURCE_DIR}/miniz.h"
)
