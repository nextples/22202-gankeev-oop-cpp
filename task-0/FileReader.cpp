#include "FileReader.h"

#include <string>

FileReader::FileReader(string path) {
    this->path = path;
}

void FileReader::open() {
    file.open(path);
}

bool FileReader::hasNext() {
    return !file.eof();
}

string FileReader::nextString() {
    string str = "";
    if (!file.eof()) {
        str = "";
        getline(file, str);
        return str;
    }
    return str;
}

void FileReader::close() {
    file.close();
}