#include <iostream>
#include "FileReader.h"
#include "Parser.h"
#include "StatisticStorage.h"
#include "CSVFileWriter.h"

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

    StatisticStorage
//    StatisticStorage::sortData(parser);
//    CSVFileWriter fileWriter("C:\\Users\\User\\CLionProjects\\22202-Gankeev-OOP-CPP\\task-0\\output.csv");
//    fileWriter.open();
//    fileWriter.writeData(parser);
//    fileWriter.close();
//    fileReader.close();
    return 0;
}