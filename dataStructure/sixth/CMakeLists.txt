cmake_minimum_required(VERSION 3.22)
project(sixth)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sixth
        Dijkstra.h
        graph.h
        main.cpp)
