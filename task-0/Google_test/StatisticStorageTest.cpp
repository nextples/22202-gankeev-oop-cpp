#include "gtest/gtest.h"
#include "../StatisticStorage.h"


TEST(StatisticStorage, CountTokens){
    Parser parser;
    string str = "abcd abcd ab+cd ab";
    parser.setVector();
    parser.setStr(str);
    parser.toLowerConverte();
    parser.parseString();

    ASSERT_EQ(parser.getToken(0).numb, 2);
    ASSERT_EQ(parser.getToken(1).numb, 2);
    ASSERT_EQ(parser.getToken(2).numb, 1);
    ASSERT_EQ(StatisticStorage::countFreqProcent(parser.getToken(0).numb, parser), 40);
    ASSERT_EQ(StatisticStorage::countFreqProcent(parser.getToken(1).numb, parser), 40);
    ASSERT_EQ(StatisticStorage::countFreqProcent(parser.getToken(2).numb, parser), 20);
}