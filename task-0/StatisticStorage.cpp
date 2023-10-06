#include "StatisticStorage.h"

#include <algorithm>

using namespace std;

bool StatisticStorage::compare(const token_t &a, const token_t &b) {
    return (a.numb > b.numb);
}

void StatisticStorage::sortData(Parser &parser) {
    sort(parser.getVector()->begin(), parser.getVector()->end(), compare);
}

int StatisticStorage::countSum(Parser &parser) {
    sum = 0;
    for (int i = 0; i < parser.getVector()->size(); i++) {
        sum += parser.getToken(i).numb;
    }
    return sum;
}

double StatisticStorage::countProcent(int numb, Parser &parser) {
    StatisticStorage statistic;
    return (double)numb / (double) statistic.countSum(parser) * 100;
}