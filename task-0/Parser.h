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

class StatisticStorage;
class CSVFileWriter;

class Parser {

    friend StatisticStorage;
    friend CSVFileWriter;

private:
    string str;
    vector<token_t> vect;
    void addToken(string lex);
    //    friend void StatisticStorage::sortData(Parser &parser);
public:
    Parser();

    void setVector();

    void setStr(string str);

    void toLowerConverte();

    void createTokens();

};


#endif //CPP_LABS_PARSER_H
