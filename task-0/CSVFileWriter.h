#ifndef CPP_LABS_CSVFILEWRITER_H
#define CPP_LABS_CSVFILEWRITER_H

#include <string>
#include <iostream>
#include <fstream>

#define END_OF_LINE true

using namespace std;

class CSVFileWriter {
private:
    string path;
    fstream fileCSV;

public:
    CSVFileWriter(string path);

    void open();
    void close();

    void writeData(string str, bool isEOL = false);
    void writeData(int numb, bool isEOL = false);
};

#endif //CPP_LABS_CSVFILEWRITER_H
