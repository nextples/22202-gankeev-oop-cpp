#ifndef CPP_LABS_STATISTICSTORAGE_H
#define CPP_LABS_STATISTICSTORAGE_H

#include <vector>
#include <string>

struct token_t {
    string lexeme;
    int numb;
    double freqProcent;
};

using namespace std;

class StatisticStorage {
private:
    vector<string> lexemes;
    vector<token_t> tokens;

    static bool compare(const token_t &a, const token_t &b);

public:
    StatisticStorage(vector<std::string> & lexemes);

    void createTokens();

//    int countSum(Parser &parser);

    void sortData();

    void countFreqProcent();

    void getFrequency();
};


#endif //CPP_LABS_STATISTICSTORAGE_H
