#include "FileReader.h"

#include <string>

FileReader::FileReader(string path) {
    this->path = path;
}

bool FileReader::open() {
    file.open(path);
    if (file.is_open()){
        return true;
    }
    return false;
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