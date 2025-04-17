cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(PGK2D main.cpp
        Engine.h
        Engine.cpp
        Line.cpp
        Line.h
        Circle.cpp
        Circle.h
        Rectangle.cpp
        Rectangle.h
        Primitive.cpp
        Primitive.h
)
target_link_libraries(PGK2D ${SDL2_LIBRARIES})