#include "CSVFileWriter.h"
#include "Parser.h"
#include "StatisticStorage.h"


using namespace std;

CSVFileWriter::CSVFileWriter(string path) {
    this->path = path;
}

void CSVFileWriter::open() {
    fileCSV.open(path, fstream::in | fstream::out | fstream::trunc);
}

void CSVFileWriter::writeData(Parser &parser) {

    for (int i = 0; i < parser.getVector()->size(); i++) {
        fileCSV << parser.getToken(i).lexeme << ',' << parser.getToken(i).numb << ',' << StatisticStorage::countFreqProcent(
                parser.getToken(i).numb, parser) << '%' << endl;
    }
}

void CSVFileWriter::close() {
    fileCSV.close();
}