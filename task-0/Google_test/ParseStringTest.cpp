#include "gtest/gtest.h"
#include "../Parser.h"
#include <string>
#include <vector>

using namespace std;

TEST(ParseString, SplitByWords1) {
    string str = "Hello, it is test message! Lets parse it!";

    Parser parser(str, INSENS_CASE);
    vector<string> parsedStr = parser.parseString();

    ASSERT_EQ(parsedStr.size(), 8);
    ASSERT_EQ(parsedStr[0], "hello");
    ASSERT_EQ(parsedStr[1], "it");
    ASSERT_EQ(parsedStr[2], "is");
    ASSERT_EQ(parsedStr[3], "test");
    ASSERT_EQ(parsedStr[4], "message");
    ASSERT_EQ(parsedStr[5], "lets");
    ASSERT_EQ(parsedStr[6], "parse");
    ASSERT_EQ(parsedStr[7], "it");
}

TEST(ParseString, SplitByWords2) {
    string str = "Hello! It is test message! Lets parse it!";

    Parser parser(str, SENS_CASE);
    vector<string> parsedStr = parser.parseString();

    ASSERT_EQ(parsedStr.size(), 8);
    ASSERT_EQ(parsedStr[0], "Hello");
    ASSERT_EQ(parsedStr[1], "It");
    ASSERT_EQ(parsedStr[2], "is");
    ASSERT_EQ(parsedStr[3], "test");
    ASSERT_EQ(parsedStr[4], "message");
    ASSERT_EQ(parsedStr[5], "Lets");
    ASSERT_EQ(parsedStr[6], "parse");
    ASSERT_EQ(parsedStr[7], "it");
}

TEST(ParseString, SplitByNumbers) {
    string str = "64 128 5,12";
    Parser parser(str, INSENS_CASE);
    vector<string> parsedStr = parser.parseString();

    ASSERT_EQ(parsedStr.size(), 4);
    ASSERT_EQ(parsedStr[0], "64");
    ASSERT_EQ(parsedStr[1], "128");
    ASSERT_EQ(parsedStr[2], "5");
    ASSERT_EQ(parsedStr[3], "12");
}

TEST(ParseString, EmptyString) {
    string str = "";
    Parser parser(str, INSENS_CASE);
    vector<string> parsedStr = parser.parseString();

    ASSERT_EQ(parsedStr.size(), 0);
}

TEST(ParseString, StringWithNoWords) {
    string str = "+++\n    \t%%%";
    Parser parser(str, INSENS_CASE);
    vector<string> parsedStr = parser.parseString();

    ASSERT_EQ(parsedStr.size(), 0);
}