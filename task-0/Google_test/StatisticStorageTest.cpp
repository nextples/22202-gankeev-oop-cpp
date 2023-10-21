#include "gtest/gtest.h"
#include "../StatisticStorage.h"


TEST(StatisticStorage, MakeStat1){
    vector<string> inputStr = {"Hello", "it", "is", "test", "message", "Lets", "parse", "it"};
    StatisticStorage statistic(inputStr);
    vector<token_t> freqList = statistic.getFrequency();

    ASSERT_EQ(freqList[0].numb, 2);
    ASSERT_EQ(freqList[0].lexeme, "it");
    ASSERT_EQ(freqList[0].freqProcent, 25);

    ASSERT_EQ(freqList[1].numb, 1);
    ASSERT_EQ(freqList[1].lexeme, "Hello");
    ASSERT_EQ(freqList[1].freqProcent, 12.5);

    ASSERT_EQ(freqList[2].numb, 1);
    ASSERT_EQ(freqList[2].lexeme, "is");
    ASSERT_EQ(freqList[2].freqProcent, 12.5);

    ASSERT_EQ(freqList[3].numb, 1);
    ASSERT_EQ(freqList[3].lexeme, "test");
    ASSERT_EQ(freqList[3].freqProcent, 12.5);

    ASSERT_EQ(freqList[4].numb, 1);
    ASSERT_EQ(freqList[4].lexeme, "message");
    ASSERT_EQ(freqList[4].freqProcent, 12.5);

    ASSERT_EQ(freqList[5].numb, 1);
    ASSERT_EQ(freqList[5].lexeme, "Lets");
    ASSERT_EQ(freqList[5].freqProcent, 12.5);

    ASSERT_EQ(freqList[6].numb, 1);
    ASSERT_EQ(freqList[6].lexeme, "parse");
    ASSERT_EQ(freqList[6].freqProcent, 12.5);
}

TEST(StatisticStorage, MakeStat2){
    vector<string> inputStr = {"abcd", "abc", "abcd", "abcd"};
    StatisticStorage statistic(inputStr);
    vector<token_t> freqList = statistic.getFrequency();

    ASSERT_EQ(freqList[0].numb, 3);
    ASSERT_EQ(freqList[0].lexeme, "abcd");
    ASSERT_EQ(freqList[0].freqProcent, 75);

    ASSERT_EQ(freqList[1].numb, 1);
    ASSERT_EQ(freqList[1].lexeme, "abc");
    ASSERT_EQ(freqList[1].freqProcent, 25);
}