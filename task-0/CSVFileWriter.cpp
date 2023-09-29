#include "CSVFileWriter.h"
#include "Parser.h"
#include "StatisticStorage.h"


using namespace std;

CSVFileWriter::CSVFileWriter(string path) {
    this->path = path;
}

void CSVFileWriter::open() {
    fileCSV.open(path, fstream::in | fstream::out);
}

void CSVFileWriter::writeData(Parser &parser) {

    for (int i = 0; i < parser.vect.size(); i++) {
        fileCSV << parser.vect[i].lexeme << ',' << parser.vect[i].numb << ',' << StatisticStorage::countProcent(parser.vect[i].numb, parser) << '%' << endl;
    }
}

void CSVFileWriter::close() {
    fileCSV.close();
}