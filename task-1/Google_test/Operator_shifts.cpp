#include "gtest/gtest.h"
#include "../BitArray.h"


using namespace std;

TEST(Operator_shifts, Operator1) {
    BitArray array(10, 120);
    for (int i = 0; i < 32; i++) {
        array.push_back(1/*rand() % 2*/);
    }
    array.to_string();
    //ASSERT_EQ();
}