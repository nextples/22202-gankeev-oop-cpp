#ifndef CPP_LABS_CSVFILEWRITER_H
#define CPP_LABS_CSVFILEWRITER_H

#include <string>
#include <iostream>
#include <fstream>
#include "Parser.h"

using namespace std;

class CSVFileWriter {
private:
    string path;
    fstream fileCSV;

public:
    CSVFileWriter(string path);

    void open();

    void writeData(Parser &parser);

    void close();
};

#endif //CPP_LABS_CSVFILEWRITER_H
