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
        ASSERT_EQ(array1.getBit(i), array2Copy.getBit(i));
        ASSERT_EQ(array2.getBit(i), array1Copy.getBit(i));
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
        ASSERT_EQ(array1.getBit(i), array2Copy.getBit(i));
        ASSERT_EQ(array2.getBit(i), array1Copy.getBit(i));
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
            ASSERT_EQ(array.getBit(i), 0);
        }
        else {
            ASSERT_EQ(array.getBit(i), 1);
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
    ASSERT_EQ(array.getBit(0), 1);
    array.push_back(0);
    ASSERT_EQ(array.size(), 2);
    ASSERT_EQ(array.getBit(0), 1);
    ASSERT_EQ(array.getBit(1), 0);
}

TEST(Methods, Set1) {
    BitArray array(32, 0);
    for (int i = 0; i < 32; i++) {
        ASSERT_EQ(array.getBit(i), 0);
    }
    array.set(0, 1);
    ASSERT_EQ(array.getBit(0), 1);
    array.set(1, 1);
    ASSERT_EQ(array.getBit(0), 1);
    ASSERT_EQ(array.getBit(1), 1);
    array.set(1, 0);
    ASSERT_EQ(array.getBit(0), 1);
    ASSERT_EQ(array.getBit(1), 0);
}

TEST(Methods, Set2) {
    BitArray array;
    int size = 32;
    for (int i = 0; i < size; i++) {
        array.push_back(0);
        ASSERT_EQ(array.getBit(i), 0);
    }
    array.set();
    for (int i = 0; i < array.size(); i++) {
        ASSERT_EQ(array.getBit(i), 1);
    }
}

TEST(Methods, Reset1) {
    BitArray array;
    for (int i = 0; i < 32; i++) {
        array.push_back(1);
        ASSERT_EQ(array.getBit(i), 1);
    }
    array.reset(0);
    ASSERT_EQ(array.getBit(0), 0);
    array.reset(1);
    ASSERT_EQ(array.getBit(0), 0);
    ASSERT_EQ(array.getBit(1), 0);
}

TEST(Methods, Reset2) {
    BitArray array;
    int size = 32;
    for (int i = 0; i < size; i++) {
        array.push_back(1);
        ASSERT_EQ(array.getBit(i), 1);
    }
    array.reset();
    for (int i = 0; i < array.size(); i++) {
        ASSERT_EQ(array.getBit(i), 0);
    }
}

TEST(Methods, Any) {
    BitArray array;
    for (int i = 0; i < 250; i++) {
        array.push_back(0);
    }
    ASSERT_EQ(array.any(), 0);
    array.set(201, 1);
    ASSERT_EQ(array.any(), 1);
}

TEST(Methods, None) {
    BitArray array;
    for (int i = 0; i < 250; i++) {
        array.push_back(0);
    }
    ASSERT_EQ(array.none(), 1);
    array.set(152, 1);
    ASSERT_EQ(array.none(), 0);
}

TEST(Methods, Count) {
    BitArray array;
    for (int i = 0; i < 250; i++) {
        array.push_back(0);
    }
    ASSERT_EQ(array.count(), 0);
    array.set(12, 1);
    ASSERT_EQ(array.count(), 1);
    array.set(42, 1);
    ASSERT_EQ(array.count(), 2);
    array.reset();
    ASSERT_EQ(array.count(), 0);
}

TEST(Methods, Size) {
    BitArray array;
    ASSERT_EQ(array.size(), 0);
    for (int i = 0; i < 250; i++) {
        array.push_back(rand() % 2);
    }
    ASSERT_EQ(array.size(), 250);
    array.resize(100);
    ASSERT_EQ(array.size(), 100);
}

TEST(Methods, Empty) {
    BitArray array;
    ASSERT_EQ(array.size(), 0);
    for (int i = 0; i < 250; i++) {
        array.push_back(rand() % 2);
    }
    ASSERT_EQ(array.size(), 250);
    array.resize(100);
    ASSERT_EQ(array.size(), 100);
}

TEST(Methods, To_string) {
    BitArray array;
    for (int i = 0; i < 10; i++) {
        array.push_back(1);
    }
    ASSERT_EQ(array.to_string(), "1111111111");
    array.set(0, 0);
    ASSERT_EQ(array.to_string(), "0111111111");
    array.set(3, 0);
    ASSERT_EQ(array.to_string(), "0110111111");
    array.set(9, 0);
    ASSERT_EQ(array.to_string(), "0110111110");
    array.reset();
    ASSERT_EQ(array.to_string(), "0000000000");
}