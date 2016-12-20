cmake_minimum_required(VERSION 3.6)
project(Alex)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp graph.cpp graph.h Boruvka.cpp Boruvka.h)
add_executable(Alex ${SOURCE_FILES})