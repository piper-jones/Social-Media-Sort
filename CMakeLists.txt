cmake_minimum_required(VERSION 3.26)
project(Social_Media_Sort)

set(CMAKE_CXX_STANDARD 17)

add_executable(Social_Media_Sort main.cpp
        Post.cpp
        Post.h
        gui.cpp
        read.cpp)
