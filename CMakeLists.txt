cmake_minimum_required(VERSION 3.24)
project(labwork-8-dubstephf)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(bin)
add_subdirectory(lib)

enable_testing()
add_subdirectory(tests)