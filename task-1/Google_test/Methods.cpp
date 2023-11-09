#include "gtest/gtest.h"
#include "../BitArray.h"

TEST(Methods, Swap1) {
    int size = 200;
    BitArray array1;
    BitArray array2;
    for (int i = 0; i < size; i++) {
        array1.push_back(true);
        array2.push_back(true);
    }
    BitArray array1Copy(array1);
    BitArray array2Copy(array2);
    array1.swap(array2);
    ASSERT_EQ(array1.size(), array2Copy.size());
    ASSERT_EQ(array2.size(), array1Copy.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], array2Copy[i]);
        ASSERT_EQ(array2[i], array1Copy[i]);
    }
}

TEST(Methods, Swap2) {
    int size = 200;
    BitArray array1;
    BitArray array2;
    for (int i = 0; i < size; i++) {
        array1.push_back(rand() % 2);
        array2.push_back(1 - rand() % 2);
    }
    BitArray array1Copy(array1);
    BitArray array2Copy(array2);
    array1.swap(array2);
    ASSERT_EQ(array1.size(), array2Copy.size());
    ASSERT_EQ(array2.size(), array1Copy.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], array2Copy[i]);
        ASSERT_EQ(array2[i], array1Copy[i]);
    }
}

TEST(Methods, Resize1) {
    BitArray array;
    ASSERT_EQ(array.size(), 0);
    array.resize(10);
    ASSERT_EQ(array.size(), 10);
    array.resize(2500);
    ASSERT_EQ(array.size(), 2500);
    array.resize(2);
    ASSERT_EQ(array.size(), 2);
    array.resize(5, 1);
    ASSERT_EQ(array.size(), 5);
    for (int i = 0; i < 5; i++) {
        if (i < 2) {
            ASSERT_EQ(array[i], 0);
        }
        else {
            ASSERT_EQ(array[i], 1);
        }
    }
}

TEST(Methods, Clear) {
    BitArray array;
    int size = 100;
    for (int i = 0; i < size; i++) {
        array.push_back(rand() % 2);
    }
    ASSERT_EQ(array.size(), size);
    array.clear();
    ASSERT_EQ(array.size(), 0);
}

TEST(Methods, Push_back) {
    BitArray array;
    ASSERT_EQ(array.size(), 0);
    array.push_back(true);
    ASSERT_EQ(array.size(), 1);
    ASSERT_EQ(array[0], 1);
    array.push_back(0);
    ASSERT_EQ(array.size(), 2);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 0);
}

TEST(Methods, Set1) {
    BitArray array(32, 0);
    for (int i = 0; i < 32; i++) {
        ASSERT_EQ(array[i], 0);
    }
    array.set(0, 1);
    ASSERT_EQ(array[0], 1);
    array.set(1, 1);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 1);
    array.set(1, 0);
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 0);
}

TEST(Methods, Set2) {
    BitArray array;
    int size = 32;
    for (int i = 0; i < size; i++) {
        array.push_back(0);
        ASSERT_EQ(array[i], 0);
    }
    array.set();
    for (int i = 0; i < array.size(); i++) {
        ASSERT_EQ(array[i], 1);
    }
}

TEST(Methods, Reset1) {
    BitArray array;
    for (int i = 0; i < 32; i++) {
        array.push_back(1);
        ASSERT_EQ(array[i], 1);
    }
    array.reset(0);
    ASSERT_EQ(array[0], 0);
    array.reset(1);
    ASSERT_EQ(array[0], 0);
    ASSERT_EQ(array[1], 0);
}

TEST(Methods, Reset2) {
    BitArray array;
    int size = 32;
    for (int i = 0; i < size; i++) {
        array.push_back(1);
        ASSERT_EQ(array[i], 1);
    }
    array.reset();
    for (int i = 0; i < array.size(); i++) {
        ASSERT_EQ(array[i], 0);
    }
}

TEST(Methods, Any) {

}