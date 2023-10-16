#include "BitArray.h"
#include <limits.h>

#define BITS_IN_LONG sizeof(unsigned long)*8

unsigned long CheckBit(const int value, const int position) {
    unsigned long result;
    if ((value & (1 << position)) == 0) {
        result = 0;
    }
    else {
        result = 1;
    }
    return result;
}

unsigned long SetZeroToBit(unsigned long value, int position) {
    return (value & ~(1 << position));
}

unsigned long SetOneToBit(unsigned long value, int position) {
    return (value | (1 << position));
}

BitArray::BitArray() {      // create array constructor
    array = nullptr;
    elSize = 0;
    bitSize = 0;
}

BitArray::~BitArray() {     // destructor
        delete[] array;
}

BitArray::BitArray(const BitArray &other) {     // copy constructor
    this->elSize = other.elSize;
    this->bitSize = other.bitSize;
    this->array = new unsigned long [other.elSize];

    for (int i = 0; i < other.elSize; i++) {
        this->array[i] = other.array[i];
    }
}

BitArray::BitArray(int num_bits, unsigned long value) {     // constructor with start value
    array = new unsigned long [num_bits];
    array[0] = value;
    bitSize = num_bits;
    elSize = 1;
}

BitArray::BitArray(int num_bits) {      // constructor without start value
    array = new unsigned long [num_bits];
    bitSize = num_bits;
    if (num_bits % sizeof(unsigned long) == 0) {
        elSize = (int)(num_bits / sizeof(unsigned long));
    }
    else {
        elSize = (int)(num_bits / sizeof(unsigned long) + 1);
    }
}

void BitArray::swap(BitArray &a, BitArray &b) {
    // почему нельзя просто поменять указатели на эти объекты?? в чем смысл? почему в аргументах функции изначально один объект??
}

BitArray & BitArray::operator = (const BitArray &other) {
    if (this->array != nullptr) {
        delete[] array;
    }
    this->elSize = other.elSize;
    this->bitSize = other.bitSize;
    this->array = new unsigned long [other.elSize];

    for (int i = 0; i < other.elSize; i++) {
        this->array[i] = other.array[i];
    }
    return *this;
}

void BitArray::resize(int num_bits, bool value) {   //Изменяет размер массива. В случае расширения, новые элементы инициализируются значением value.
    int newElSize = 0;
    if (num_bits % sizeof(unsigned long) == 0) {
        newElSize = (int)(num_bits / sizeof(unsigned long));
    }
    else {
        newElSize = (int)(num_bits / sizeof(unsigned long) + 1);
    }
    unsigned long *newArray = new unsigned long [newElSize];
    if (newElSize <= elSize) {
        for (int i = 0; i < newElSize; i++) {
            newArray[i] = array[i];
        }
    }
    else {
        for (int i = 0; i < elSize; i++) { //   copy the previous version
            newArray[i] = array[i];
        }
        for (int i = BITS_IN_LONG - (bitSize % BITS_IN_LONG) - 1; i >= 0; i--) {
            if (value) {
                newArray[elSize - 1] = SetOneToBit(newArray[elSize - 1], i);
            }
            else {
                newArray[elSize - 1] = SetZeroToBit(newArray[elSize - 1], i);
            }
        }
        for (int i = elSize; i < newElSize; i++) {
            if (value) {
                newArray[i] = LONG_MAX;
            }
            else {
                newArray[i] = 0;
            }
        }
    }
    delete[] array;
    array = newArray;
    elSize = newElSize;
    bitSize = num_bits;
}

void BitArray::clear() {
    delete[] array;
    bitSize = 0;
    elSize = 0;
}

void BitArray::push_back(bool bit) {
    if (elSize * BITS_IN_LONG - bitSize > 0) {      //   memory doesn't need to be added
        if (bit) {
            array[elSize - 1] = SetOneToBit(array[elSize - 1], BITS_IN_LONG - (bitSize % (int)BITS_IN_LONG) - 1);
            bitSize++;
        }
        else {
            array[elSize - 1] = SetZeroToBit(array[elSize - 1], BITS_IN_LONG - (bitSize % (int)BITS_IN_LONG) - 1);
            bitSize++;
        }
    }
    else {      //   memory need to be added
        resize(bitSize + 1);
        if (bit) {
            array[elSize] = SetOneToBit(array[elSize], BITS_IN_LONG - (bitSize % (int)BITS_IN_LONG) - 1);
            elSize++;
            bitSize++;
        }
        else {
            array[elSize] = SetZeroToBit(array[elSize], BITS_IN_LONG - (bitSize % (int)BITS_IN_LONG) - 1);
            elSize++;
            bitSize++;
        }
    }
}

