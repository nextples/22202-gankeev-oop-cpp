#include <iostream>
#include "FileReader.h"
#include "Parser.h"
#include "StatisticStorage.h"
#include "CSVFileWriter.h"

using namespace std;

int main() {
    FileReader fileReader("C:\\Users\\User\\CLionProjects\\22202-Gankeev-OOP-CPP\\task-0\\text.txt");
    fileReader.open();
    Parser parser;
    parser.setVector();
    while (fileReader.hasNext()) {
        string str = fileReader.next();
        parser.setStr(str);
        parser.toLowerConverte();
        parser.createTokens();
    }

    StatisticStorage::sortData(parser);
    CSVFileWriter fileWriter("C:\\Users\\User\\CLionProjects\\22202-Gankeev-OOP-CPP\\task-0\\output.csv");
    fileWriter.open();
    fileWriter.writeData(parser);
    fileWriter.close();
    fileReader.close();
    return 0;
}