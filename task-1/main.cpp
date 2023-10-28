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
    //array.resize(35, 0);
    for (int i = 0; i < 10; i++) {
        array.push_back(rand() % 2);
    }
    array.to_string();
    cout << endl;
    array <<= 3;
    array.to_string();
    cout << endl;
    return 0;
}
