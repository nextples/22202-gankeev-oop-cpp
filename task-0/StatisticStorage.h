#ifndef CPP_LABS_STATISTICSTORAGE_H
#define CPP_LABS_STATISTICSTORAGE_H

#include "Parser.h"

#include <vector>

class StatisticStorage {
private:
    int sum;

    static bool compare(const token_t &a, const token_t &b);

public:
    int countSum(Parser &parser);

    static void sortData(Parser &parser);

    static double countProcent(int numb, Parser &parser);
};


#endif //CPP_LABS_STATISTICSTORAGE_H
