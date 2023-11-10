#include <iostream>
#include "BitArray.h"

int main() {
    BitArray array;
    BitArray array2;
    for (int i = 0; i < 3; i++) {
        bool bit = rand() % 2;
        array.push_back(bit);
        array2.push_back(1 - bit);
    }
    cout << array.to_string() << endl;
    cout << array2.to_string() << endl;
    BitArray arrayRes;
    arrayRes = array & array2;
    cout << endl;
    cout << arrayRes.to_string() << endl;

    return 0;
}
