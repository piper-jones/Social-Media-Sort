cmake_minimum_required(VERSION 3.26)
project(Social_Media_Sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(Social_Media_Sort main.cpp
        Post.cpp
        Post.h
        gui.cpp
        read.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include/SFML)
target_link_libraries(Social_Media_Sort sfml-system sfml-window sfml-graphics sfml-audio)


