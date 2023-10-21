#include "gtest/gtest.h"
#include "../FileReader.h"
#include <fstream>

TEST(FileReader, OpenExistFile){
    FileReader fileReader("C:\\Users\\User\\CLionProjects\\22202-Gankeev-OOP-CPP\\task-0\\text.txt");
    EXPECT_TRUE(fileReader.open());
}

TEST(FileReader, OpenNonExistFile){
    FileReader fileReader("C:\\Users\\User\\CLionProjects\\22202-Gankeev-OOP-CPP\\task-0\\NonExist.txt");
    EXPECT_FALSE(fileReader.open());
}