#include "Parser.h"

#include <string>

using namespace std;

Parser::Parser() {
    this->str = "";
}

void Parser::setVector() {
    Parser::vect = {};
}

void Parser::setStr(std::string str) {
    this->str = str;
}

void Parser::toLowerConverte() {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

void Parser::addToken(string lex) {
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i].lexeme == lex) {
            vect[i].numb++;
            return;
        }
    }
    token_t token = {lex, 1};
    vect.push_back(token);
}

void Parser::createTokens() {
    string lexeme = "";
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' &&
            str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            lexeme += str[i];
        }
        else {
            if (!lexeme.empty()) {
                addToken(lexeme);
            }
            lexeme = "";
        }
    }
}