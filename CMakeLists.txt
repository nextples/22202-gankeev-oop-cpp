cmake_minimum_required(VERSION 3.26)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_labs task-0/main.cpp
        task-0/FileReader.h
        task-0/FileReader.cpp
        task-0/Parser.h
        task-0/Parser.cpp
        task-0/StatisticStorage.h
        task-0/StatisticStorage.cpp
        task-0/CSVFileWriter.cpp
        task-0/CSVFileWriter.h
)
