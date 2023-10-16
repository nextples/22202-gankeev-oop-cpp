#include <iostream>
#include "FileReader.h"
#include "Parser.h"
#include "StatisticStorage.h"
#include "CSVFileWriter.h"

#include <vector>
using namespace std;

int main() {
    FileReader fileReader("C:\\Users\\User\\CLionProjects\\22202-Gankeev-OOP-CPP\\task-0\\text.txt");
    fileReader.open();

    vector<string> lexemes = {};
    while (fileReader.hasNext()) {
        string str = fileReader.next();
        Parser parser(str, INSENS_CASE);
        vector<string> parsedStr = parser.parse();
        lexemes.insert(lexemes.end(), parsedStr.begin(), parsedStr.end());
    }

    StatisticStorage statistic(lexemes);
    vector<token_t> freqList = statistic.getFrequency();

    CSVFileWriter fileWriter("C:\\Users\\User\\CLionProjects\\22202-Gankeev-OOP-CPP\\task-0\\output.csv");
    fileWriter.open();
    for (int i = 0; i < freqList.size(); i++) {
        fileWriter.writeData(freqList[i].lexeme);
        fileWriter.writeData(freqList[i].numb);
        fileWriter.writeData(to_string(freqList[i].freqProcent).erase(to_string(freqList[i].freqProcent).size()-4) + '%', END_OF_LINE);
    }   // output without 4 last numbers after comma
    fileWriter.close();
    fileReader.close();
    return 0;
}