#include "StatisticStorage.h"

#include <algorithm>

using namespace std;

bool StatisticStorage::compare(const token_t &a, const token_t &b) {
    return (a.numb > b.numb);
}

void StatisticStorage::sortData(Parser &parser) {
    sort(parser.vect.begin(), parser.vect.end(), compare);
}

int StatisticStorage::countSum(Parser &parser) {
    sum = 0;
    for (int i = 0; i < parser.vect.size(); i++) {
        sum += parser.vect[i].numb;
    }
    return sum;
}

double StatisticStorage::countProcent(int value, Parser &parser) {
    StatisticStorage statistic;
    return (double)value / (double) statistic.countSum(parser)  * 100;
}