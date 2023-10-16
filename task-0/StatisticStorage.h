#ifndef CPP_LABS_STATISTICSTORAGE_H
#define CPP_LABS_STATISTICSTORAGE_H

#include <vector>
#include <string>

using namespace std;

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

    void createTokens();

    void sortData();

    void countFreqProcent();

public:
    StatisticStorage(vector<std::string> & lexemes);

    vector<token_t> & getFrequency();
};


#endif //CPP_LABS_STATISTICSTORAGE_H
