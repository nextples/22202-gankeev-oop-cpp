#ifndef CPP_LABS_FILEREADER_H
#define CPP_LABS_FILEREADER_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileReader {
private:
    string path;
    ifstream file;

public:
    FileReader(string path);

    void open();

    bool hasNext();

    string nextString();

    void close();

};

#endif //CPP_LABS_FILEREADER_H