
cmake_minimum_required(VERSION 3.10)
project(balrog)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw REQUIRED)

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
target_link_libraries(
    balrog
    PUBLIC
    OpenGL::GL
    GLEW::GLEW
    glfw::glfw
)

add_subdirectory(
    examples
)
