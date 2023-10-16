#include <iostream>


unsigned long SetZeroToBit(unsigned long value, int position) {
    return (value & ~(1 << position));
}

unsigned long SetOneToBit(unsigned long value, int position) {
    return (value | (1 << position));
}

int main() {
//    std::cout << sizeof(unsigned long) << std::endl;
    unsigned long val = 1;
    val = SetOneToBit(val, 0);
    std::cout << val << std::endl;
    val = SetZeroToBit(val, 0);
    std::cout << val << std::endl;
    val = SetOneToBit(val, 1);
    std::cout << val << std::endl;
    val = SetZeroToBit(val, 1);
    std::cout << val << std::endl;
    val = SetOneToBit(val, 2);
    std::cout << val << std::endl;
    val = SetZeroToBit(val, 2);
    std::cout << val << std::endl;

    return 0;
}
