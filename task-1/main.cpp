#include <iostream>
#include "BitArray.h"

int main() {
    BitArray array;
    array.push_back(1);
    array.push_back(0);
    array.push_back(1);
    cout << array.to_string() << endl;

    array[1] = 1;
    array[0] = 0;
    int bit = array[1] & array[0];
    cout << array.to_string() << endl;
    cout << array[0] << endl;
    cout << bit << endl;
    return 0;
}
