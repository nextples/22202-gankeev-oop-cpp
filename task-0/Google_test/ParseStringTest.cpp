#include "gtest/gtest.h"
#include "../Parser.h"
#include "string"

TEST(ParseString, SplitByWords1) {
    Parser parser;
    string str = "abc abcd a1b2c3";
    parser.setVector();
    parser.setStr(str);
    parser.toLowerConverte();
    parser.parseString();

    ASSERT_EQ(parser.getVector()->size(), 3);
    ASSERT_EQ(parser.getToken(0).lexeme, "abc");
    ASSERT_EQ(parser.getToken(1).lexeme, "abcd");
    ASSERT_EQ(parser.getToken(2).lexeme, "a1b2c3");
}

TEST(ParseString, SplitByWords2) {
    Parser parser;
    string str = "123 + abcd  \n  \t dcba+12";
    parser.setVector();
    parser.setStr(str);
    parser.toLowerConverte();
    parser.parseString();

    ASSERT_EQ(parser.getVector()->size(), 4);
    ASSERT_EQ(parser.getToken(0).lexeme, "123");
    ASSERT_EQ(parser.getToken(1).lexeme, "abcd");
    ASSERT_EQ(parser.getToken(2).lexeme, "dcba");
    ASSERT_EQ(parser.getToken(3).lexeme, "12");
}

TEST(ParseString, EmptyString) {
    Parser parser;
    string str = "";
    parser.setVector();
    parser.setStr(str);
    parser.toLowerConverte();
    parser.parseString();

    ASSERT_EQ(parser.getVector()->size(), 0);
}

TEST(ParseString, StringWithNoWords) {
    Parser parser;
    string str = "\n \t    \n \t";
    parser.setVector();
    parser.setStr(str);
    parser.toLowerConverte();
    parser.parseString();

    ASSERT_EQ(parser.getVector()->size(), 0);
}