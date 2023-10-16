#ifndef CPP_LABS_PARSER_H
#define CPP_LABS_PARSER_H

#define SENS_CASE 1
#define INSENS_CASE 0

#include <iostream>
#include <string>
#include <vector>

using namespace std;


string toLowerConverte(string str);


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
