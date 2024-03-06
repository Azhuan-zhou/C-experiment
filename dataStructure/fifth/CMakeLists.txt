cmake_minimum_required(VERSION 3.22)
project(fifth)

set(CMAKE_CXX_STANDARD 14)

add_executable(fifth main.cpp
        graph.h
        queue.h
        Bipartite.h
        Dijkstra.h
        )
