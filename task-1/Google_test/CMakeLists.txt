# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests

add_executable(GTest_Constructors Constructors.cpp
        ../BitArray.cpp)

add_executable(GTest_Methods Methods.cpp
        ../BitArray.cpp)

target_link_libraries(GTest_Constructors gtest gtest_main)
target_link_libraries(GTest_Methods gtest gtest_main)
