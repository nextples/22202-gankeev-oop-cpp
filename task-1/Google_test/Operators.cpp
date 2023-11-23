#include <gtest/gtest.h>
#include "../BitArray.h"

TEST(Operators, Copy_Operator) {
    BitArray array1;
    BitArray array2;
    int size2 = 500;
    for (int i = 0; i < size2; i++) {
        array2.push_back(rand() % 2);
    }
    array1 = array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size2; i++) {
        ASSERT_EQ(array1[i], array2[i]);
    }
}

TEST(Operators, Bitwise_Operator1_1) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
        array2.push_back(1);
    }
    array1 &= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 1);
    }
}

TEST(Operators, Bitwise_Operator1_2) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
        array2.push_back(1);
    }
    ASSERT_EQ(array1.size(), array2.size());
    array2.set(0, 0);
    array1 &= array2;
    ASSERT_EQ(array1[0], 0);
}

TEST(Operators, Bitwise_Operator1_3) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
        array2.push_back(0);
    }
    array1 &= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Bitwise_Operator1_4) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(1 - bit);
    }
    array1 &= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Bitwise_Operator1_5) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(0);
        array2.push_back(0);
    }
    array1 &= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Bitwise_Operator2_1) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
        array2.push_back(1);
    }
    array1 |= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 1);
    }
}

TEST(Operators, Bitwise_Operator2_2) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
        array2.push_back(1);
    }
    ASSERT_EQ(array1.size(), array2.size());
    array2.set(0, 0);
    array1 |= array2;
    ASSERT_EQ(array1[0], 1);
}

TEST(Operators, Bitwise_Operator2_3) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
        array2.push_back(0);
    }
    array1 |= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 1);
    }
}

TEST(Operators, Bitwise_Operator2_4) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(1 - bit);
    }
    array1 |= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 1);
    }
}

TEST(Operators, Bitwise_Operator2_5) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(0);
        array2.push_back(0);
    }
    array1 |= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Bitwise_Operator3_1) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
        array2.push_back(1);
    }
    array1 ^= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Bitwise_Operator3_2) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
        array2.push_back(1);
    }
    ASSERT_EQ(array1.size(), array2.size());
    array2.set(0, 0);
    array1 ^= array2;
    ASSERT_EQ(array1[0], 1);
}

TEST(Operators, Bitwise_Operator3_3) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
        array2.push_back(0);
    }
    array1 ^= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 1);
    }
}

TEST(Operators, Bitwise_Operator3_4) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(1 - bit);
    }
    array1 ^= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 1);
    }
}

TEST(Operators, Bitwise_Operator3_5) {
    BitArray array1;
    BitArray array2;
    int size = 500;
    for (int i = 0; i < size; i++) {
        array1.push_back(0);
        array2.push_back(0);
    }
    array1 ^= array2;
    ASSERT_EQ(array1.size(), array2.size());
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Shift_Operator1_1) {
    BitArray array1;
    int size = 10;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
    }
    array1 <<= 3;
    for (int i = 0; i < 7; i++) {
        ASSERT_EQ(array1[i], 1);
    }
    ASSERT_EQ(array1[7], 0);
    ASSERT_EQ(array1[8], 0);
    ASSERT_EQ(array1[9], 0);
}

TEST(Operators, Shift_Operator1_2) {
    BitArray array1;
    int size = 10;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
    }
    array1 <<= 9;
    ASSERT_EQ(array1[0], 1);
    for (int i = 1; i < 10; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Shift_Operator1_3) {
    BitArray array1;
    int size = 10;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
    }
    array1 <<= 10;
    for (int i = 1; i < 10; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Shift_Operator1_4) {
    BitArray array1;
    int size = 10;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
    }
    array1 <<= 15;
    for (int i = 1; i < 10; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}
TEST(Operators, Shift_Operator2_1) {
    BitArray array1;
    int size = 10;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
    }
    array1 >>= 3;
    for (int i = 3; i < 10; i++) {
        ASSERT_EQ(array1[i], 1);
    }
    ASSERT_EQ(array1[0], 0);
    ASSERT_EQ(array1[1], 0);
    ASSERT_EQ(array1[2], 0);
}

TEST(Operators, Shift_Operator2_2) {
    BitArray array1;
    int size = 10;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
    }
    array1 >>= 9;
    ASSERT_EQ(array1[9], 1);
    for (int i = 0; i < 9; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Shift_Operator2_3) {
    BitArray array1;
    int size = 10;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
    }
    array1 >>= 10;
    for (int i = 1; i < 10; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Shift_Operator2_4) {
    BitArray array1;
    int size = 10;
    for (int i = 0; i < size; i++) {
        array1.push_back(1);
    }
    array1 >>= 15;
    for (int i = 1; i < 10; i++) {
        ASSERT_EQ(array1[i], 0);
    }
}

TEST(Operators, Index_Operatos) {
    BitArray array;
    array.push_back(1);     // 1
    array.push_back(0);     // 2
    array.push_back(0);     // 3
    array.push_back(1);     // 4
    array.push_back(0);     // 5
    array.push_back(1);     // 6
    array.push_back(1);     // 7
    array.push_back(1);     // 8
    array.push_back(0);     // 9
    array.push_back(0);     // 10
    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 0);
    ASSERT_EQ(array[2], 0);
    ASSERT_EQ(array[3], 1);
    ASSERT_EQ(array[4], 0);
    ASSERT_EQ(array[5], 1);
    ASSERT_EQ(array[6], 1);
    ASSERT_EQ(array[7], 1);
    ASSERT_EQ(array[8], 0);
    ASSERT_EQ(array[9], 0);
}

TEST(Operators, Invert_Operator) {
    BitArray array1;
    BitArray array2;
    int size = 100;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(bit);
    }
    ~array1;
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(array1[i], 1 - array2[i]);
    }
}

TEST(Operators, Compare_Operator1) {
    BitArray array1;
    BitArray array2;
    ASSERT_EQ(array1 == array2, 1);
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(bit);
    }
    ASSERT_EQ(array1 == array2, 1);
    array1.set();
    ASSERT_EQ(array1 == array2, 0);
    array2.set();
    array1.resize(100);
    ASSERT_EQ(array1 == array2, 0);
}

TEST(Operators, Compare_Operator2) {
    BitArray array1;
    BitArray array2;
    ASSERT_EQ(array1 != array2, 0);
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(bit);
    }
    ASSERT_EQ(array1 != array2, 0);
    array1.set();
    ASSERT_EQ(array1 != array2, 1);
    array2.set();
    array1.resize(100);
    ASSERT_EQ(array1 != array2, 1);
}

TEST(Operators, BitArraywise_Operator1_1) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(bit);
    }
    arrayRes = array1 & array2;
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] & array2[i]);
    }
}

TEST(Operators, BitArraywise_Operator1_2) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(1 - bit);
    }
    arrayRes = array1 & array2;
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] & array2[i]);
    }
}

TEST(Operators, BitArraywise_Operator1_3) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        if (i < 400) {
            array2.push_back(bit);
        }
    }
    arrayRes = array1 & array2;
    for (int i = 0; i < 400; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] & array2[i]);
    }
    for (int i = 400; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i]);
    }
}

TEST(Operators, BitArraywise_Operator1_4) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        if (i < 400) {
            array2.push_back(1 - bit);
        }
    }
    arrayRes = array1 & array2;
    for (int i = 0; i < 400; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] & array2[i]);
    }
    for (int i = 400; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i]);
    }
}

TEST(Operators, BitArraywise_Operator2_1) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(bit);
    }
    arrayRes = array1 | array2;
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] & array2[i]);
    }
}

TEST(Operators, BitArraywise_Operator2_2) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(1 - bit);
    }
    arrayRes = array1 | array2;
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] | array2[i]);
    }
}

TEST(Operators, BitArraywise_Operator2_3) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        if (i < 400) {
            array2.push_back(bit);
        }
    }
    arrayRes = array1 | array2;
    for (int i = 0; i < 400; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] | array2[i]);
    }
    for (int i = 400; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i]);
    }
}

TEST(Operators, BitArraywise_Operator2_4) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        if (i < 400) {
            array2.push_back(1 - bit);
        }
    }
    arrayRes = array1 | array2;
    for (int i = 0; i < 400; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] | array2[i]);
    }
    for (int i = 400; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i]);
    }
}

TEST(Operators, BitArraywise_Operator3_1) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(bit);
    }
    arrayRes = array1 ^ array2;
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] ^ array2[i]);
    }
}

TEST(Operators, BitArraywise_Operator3_2) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        array2.push_back(1 - bit);
    }
    arrayRes = array1 ^ array2;
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] ^ array2[i]);
    }
}

TEST(Operators, BitArraywise_Operator3_3) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        if (i < 400) {
            array2.push_back(bit);
        }
    }
    arrayRes = array1 ^ array2;
    for (int i = 0; i < 400; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] ^ array2[i]);
    }
    for (int i = 400; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i]);
    }
}

TEST(Operators, BitArraywise_Operator3_4) {
    BitArray array1;
    BitArray array2;
    BitArray arrayRes;
    int size = 500;
    for (int i = 0; i < size; i++) {
        bool bit = rand() % 2;
        array1.push_back(bit);
        if (i < 400) {
            array2.push_back(1 - bit);
        }
    }
    arrayRes = array1 ^ array2;
    for (int i = 0; i < 400; i++) {
        ASSERT_EQ(arrayRes[i], array1[i] ^ array2[i]);
    }
    for (int i = 400; i < size; i++) {
        ASSERT_EQ(arrayRes[i], array1[i]);
    }
}