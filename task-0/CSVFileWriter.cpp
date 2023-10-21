#include "CSVFileWriter.h"

using namespace std;

CSVFileWriter::CSVFileWriter(string path) {
    this->path = path;
}

void CSVFileWriter::open() {
    fileCSV.open(path, fstream::in | fstream::out | fstream::trunc);
}

void CSVFileWriter::writeData(string str, bool isEOL) {
    if (!isEOL) {
        fileCSV << str << ',';
    }
    else {
        fileCSV << str << endl;
    }
}

void CSVFileWriter::writeData(int numb, bool isEOL) {
    if (!isEOL) {
        fileCSV << numb << ',';
    }
    else {
        fileCSV << numb << endl;
    }
}

void CSVFileWriter::close() {
    fileCSV.close();
}