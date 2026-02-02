
cmake_minimum_required(VERSION 3.10)
project(balrog)

add_library(
    balrog
    STATIC
    src/balrog/series.cpp
)
target_include_directories(
    balrog
    PUBLIC
    include
)
