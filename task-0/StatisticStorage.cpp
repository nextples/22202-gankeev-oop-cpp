#include "StatisticStorage.h"

#include <algorithm>
#include <string>
#include <vector>
using namespace std;


bool StatisticStorage::compare(const token_t &a, const token_t &b) {
    return (a.numb > b.numb);
}

StatisticStorage::StatisticStorage(vector<std::string> & lexemes) {
    this->lexemes = lexemes;
    tokens = {};
}

void StatisticStorage::createTokens() {
    for (int i = 0; i < lexemes.size(); i++) {
        bool isAdded = false;
        for (int j = 0; j < tokens.size(); j++) {
            if (lexemes[i] == tokens[j].lexeme) {
                tokens[j].numb++;
                isAdded = true;
                break;
            }
        }
        if (isAdded) {
            continue;
        }
        else {
            token_t token = {lexemes[i], 1, 0};
            tokens.push_back(token);
        }
    }
}

void StatisticStorage::sortData() {
    sort(tokens.begin(), tokens.end(), compare);
}

void StatisticStorage::countFreqProcent() {
    int amountWords = 0;
    for (int i = 0; i < tokens.size(); i++) {
        amountWords += tokens[i].numb;
    }
    for (int i = 0; i < tokens.size(); i++) {
        tokens[i].freqProcent = (double)tokens[i].numb / amountWords * 100;
    }
}

vector<token_t> & StatisticStorage::getFrequency() {
    createTokens();
    sortData();
    countFreqProcent();
    return tokens;
}




