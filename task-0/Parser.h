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
private:
    string str;
    vector<token_t> vect;
    void addToken(string lex);
public:
    Parser();

    void setVector();

    void setStr(string str);

    void toLowerConverte();

    void createTokens();

    vector<token_t>* getVector();

    token_t getToken(int ind);
};


#endif //CPP_LABS_PARSER_H
