#ifndef CPP_LABS_PARSER_H
#define CPP_LABS_PARSER_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct token_t {
    string lexeme;
    int numb;
};

class Parser {

    //friend StatisticStorage;

public:
    vector<token_t> vect;

private:
    string str;


    void addToken(string lex);
    //    friend void StatisticStorage::sortData(Parser &parser);
public:
    Parser();

    void setVector();

    void setStr(string str);

    void toLowerConverte();

    void createTokens();

    void print();
};


#endif //CPP_LABS_PARSER_H
