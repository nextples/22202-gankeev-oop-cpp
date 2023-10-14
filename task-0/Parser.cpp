#include "Parser.h"

#include <string>

using namespace std;

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

void toLowerConverte(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

//void Parser::addToken(string lex) {
//    for (int i = 0; i < vect.size(); i++) {
//        if (vect[i].lexeme == lex) {
//            vect[i].numb++;
//            return;
//        }
//    }
//    token_t token = {lex, 1};
//    vect.push_back(token);
//}

vector<string> & Parser::parse() {
    if (mode = INSENS_CASE) {
        toLowerConverte(str);
    }

    string lexeme = "";
    for (int i = 0; i < str.length() + 1; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' &&
            str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            lexeme += str[i];
        }
        else {
            if (!lexeme.empty()) {
                //addToken(lexeme);
                vect.push_back(lexeme);
            }
            lexeme = "";
        }
    }
    return vect;
}

//token_t Parser::getToken(int ind) {
//    return vect[ind];
//}
//
//vector<token_t>* Parser::getVector() {
//    return &vect;
//}