cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pp6calculator)

include_directories(pp6Lib)

add_library(lib SHARED pp6Lib/math.hpp pp6Lib/math.cpp pp6Lib/physics.hpp pp6Lib/physics.cpp pp6Lib/input.hpp pp6Lib/input.cpp)

add_executable(run calc.cpp)

target_link_libraries(run lib)

