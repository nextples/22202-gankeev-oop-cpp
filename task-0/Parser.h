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

    vector<string> vect;

public:
    Parser(bool mode = SENS_CASE);

    Parser(string str, bool mode = SENS_CASE);

    vector<string> & parseString();

};


#endif //CPP_LABS_PARSER_H
