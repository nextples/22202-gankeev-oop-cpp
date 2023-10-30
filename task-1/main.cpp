#include <iostream>
#include "BitArray.h"

unsigned long SetZeroToBit(unsigned long value, int position) {
    return (value & ~(1 << position));
}

unsigned long SetOneToBit(unsigned long value, int position) {
    return (value | (1 << position));
}

int main() {
//    cout << sizeof(unsigned long) << endl;
//    cout << ULONG_MAX << endl;
    unsigned long n = 0;
//    cout << SetOneToBit(n, 0) << endl;

    BitArray array;
    BitArray array2;
    for (int i = 0; i < 11; i++) {
        bool bit = rand() % 2;
        array.push_back(bit);
        array2.push_back(bit);
    }
    //array.set(2, false);
    cout << array.to_string() << endl;
    cout << array2.to_string() << endl;
    array.set(10, false);
    cout << array.to_string() << endl;
    cout << array2.to_string() << endl;
    bool cmp = array != array2;
    cout << cmp << endl;
    return 0;
}
