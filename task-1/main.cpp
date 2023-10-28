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
    for (int i = 0; i < 113; i++) {
        array.push_back(0);
        //array2.push_back((rand() + 1) % 2);
    }
//
//    array2 = array << 2;
//
    array.to_string();
    cout << endl;
    array.set(111, 1);
    array.to_string();
    cout << endl;
    array.set();
    array.to_string();
    cout << endl;
//    array2.to_string();


    return 0;
}
