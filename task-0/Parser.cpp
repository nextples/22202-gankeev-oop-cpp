#include "Parser.h"

#include <string>

using namespace std;

string toLowerConverte(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
    return str;
}

Parser::Parser(bool mode) {
    str = "";
    vect = {};
    this->mode = mode;
}

Parser::Parser(string str, bool mode) {
    this->str = str;
    vect = {};
    this->mode = mode;
}

vector<string> & Parser::parseString() {
    if (mode == INSENS_CASE) {
        str = toLowerConverte(str);
    }

    string lexeme = "";
    for (int i = 0; i < str.length() + 1; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' &&
            str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            lexeme += str[i];
        }
        else {
            if (!lexeme.empty()) {
                vect.push_back(lexeme);
            }
            lexeme = "";
        }
    }
    return vect;
}