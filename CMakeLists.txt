cmake_minimum_required(VERSION 3.26)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 17)

add_executable(task-0 task-0/main.cpp)
add_executable(task-1 task-1/main.cpp
        task-1/BitArray.cpp
        task-1/BitArray.h)