#include <iostream>
#include "BitArray.h"

unsigned long SetZeroToBit(unsigned long value, int position) {
    return (value & ~(1 << position));
}

unsigned long SetOneToBit(unsigned long value, int position) {
    return (value | (1 << position));
}

int main() {
    BitArray array;
    BitArray array2;
    for (int i = 0; i < 11; i++) {
        bool bit = rand() % 2;
        array.push_back(bit);
        array2.push_back(1 - bit);
    }
    array.push_back(1);
    cout << array.to_string() << endl;
    cout << array2.to_string() << endl;

    array &= array2;

    cout << array.to_string() << endl;
    cout << array2.to_string() << endl;
    return 0;
}
