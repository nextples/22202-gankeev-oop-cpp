#include "gtest/gtest.h"
#include "../BitArray.h"

#define BITS_IN_LONG (sizeof(unsigned long) * 8)

using namespace std;

TEST(Constructors, BitArray1) {
    BitArray array;
    ASSERT_EQ(array.size(), 0);
}

TEST(Constructors, BitArray2) {
    int size = 320;
    BitArray array(size);
    ASSERT_EQ(array.size(), size);
    for (int i = 0; i < BITS_IN_LONG; i++) {
        ASSERT_EQ(array[i], 0);
    }
}

TEST(Constructors, BitArray3) {
    int size = 320;
    unsigned long value = 175;
    BitArray array(size, value);
    ASSERT_EQ(array.size(), size);
    ASSERT_EQ(array[31], 1);
    ASSERT_EQ(array[30], 1);
    ASSERT_EQ(array[29], 1);
    ASSERT_EQ(array[28], 1);
    ASSERT_EQ(array[27], 0);
    ASSERT_EQ(array[26], 1);
    ASSERT_EQ(array[25], 0);
    ASSERT_EQ(array[24], 1);
}

TEST(Constructors, CopyConstructor) {
    int size = 200;
    BitArray array1;
    for (int i = 0; i < size; i++) {
        array1.push_back(rand() % 2);
    }
    BitArray array2 (array1);
    ASSERT_EQ(array1.size(), 200);
    ASSERT_EQ(array2.size(), 200);
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array2[i], array1[i]);
    }
}