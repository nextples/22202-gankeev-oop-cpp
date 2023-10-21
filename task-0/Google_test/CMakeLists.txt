# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(GTest_Parse ParseStringTest.cpp
        ../Parser.cpp)

add_executable(GTest_StatisticStorage StatisticStorageTest.cpp
        ../StatisticStorage.cpp)

add_executable(GTest_FileReader FileReaderTest.cpp
        ../FileReader.cpp)

target_link_libraries(GTest_Parse gtest gtest_main)
target_link_libraries(GTest_StatisticStorage gtest gtest_main)
target_link_libraries(GTest_FileReader gtest gtest_main)