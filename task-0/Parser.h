#ifndef CPP_LABS_PARSER_H
#define CPP_LABS_PARSER_H

#define SENS_CASE 0
#define INSENS_CASE 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void toLowerConverte(string str);


class Parser {
private:
    bool mode;
    string str;

    //vector<token_t> vect;

    vector<string> vect;

    //void addToken(string lex);

public:
    Parser(bool mode = SENS_CASE);

    Parser(string str, bool mode = SENS_CASE);

    vector<string> & parse();

//    vector<token_t>* getVector();
//
//    token_t getToken(int ind);
};


#endif //CPP_LABS_PARSER_H
