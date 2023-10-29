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
        array.push_back(rand() % 2);
    }
    array2 = ~array;
    array.to_string();
    cout << endl;
    cout << array.count() << endl;
    array2.to_string();
    cout << endl;
    cout << array2.count() << endl;

    return 0;
}
