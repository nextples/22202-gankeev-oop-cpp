#include "BitArray.h"
#include <limits.h>
#include <iostream>

#define BITS_IN_LONG (sizeof(unsigned long) * 8)

unsigned long CheckBit(const unsigned long value, const int pos) {
    unsigned long result;
    if ((value & (1 << pos)) == 0) {
        result = 0;
    }
    else {
        result = 1;
    }
    return result;
}

unsigned long SetBit(bool bit, unsigned long value, int pos) {
    if (bit == 1) {
        value =  (value | (1 << pos));
        return value;
    }
    if (bit == 0) {
        value = (value & ~(1 << pos));
        return value;
    }
}

//unsigned long SetZeroToBit(unsigned long value, int position) {
//    return (value & ~(1 << position));
//}
//
//unsigned long SetOneToBit(unsigned long value, int position) {
//    return (value | (1 << position));
//}

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
    bitSize = num_bits;
    if (num_bits % sizeof(unsigned long) == 0) {
        elSize = (int)(num_bits / BITS_IN_LONG);
    }
    else {
        elSize = (int)(num_bits / BITS_IN_LONG + 1);
    }
    array = new unsigned long [elSize];
    array[0] = value;
}

int BitArray::size() {
    return bitSize;
}

void BitArray::swap(BitArray &b) {
    // почему нельз€ просто помен€ть указатели на эти объекты?? в чем смысл? почему в аргументах функции изначально один объект??
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

void BitArray::resize(int newBitSize, bool value) {   //»змен€ет размер массива. ¬ случае расширени€, новые элементы инициализируютс€ значением value.
    int newElSize = 0;
    if (newBitSize % BITS_IN_LONG == 0) {
        newElSize = (int) (newBitSize / BITS_IN_LONG);
    } else {
        newElSize = (int) (newBitSize / BITS_IN_LONG + 1);
    }
    unsigned long *newArray = new unsigned long[newElSize];

    if (newBitSize > bitSize) {
        for (int i = 0; i < bitSize; i++) {
            newArray[i / BITS_IN_LONG] = array[i / BITS_IN_LONG];
        }
        for (int i = bitSize; i < newBitSize; i++) {
            int pos = BITS_IN_LONG - (int) (i % BITS_IN_LONG);
            newArray[i / BITS_IN_LONG] = SetBit(value, newArray[i / BITS_IN_LONG], pos);
        }
    } else {
        for (int i = 0; i < newBitSize; i++) {
            newArray[i / BITS_IN_LONG] = array[i / BITS_IN_LONG];
        }
    }
    delete[] array;
    array = newArray;
    elSize = newElSize;
    bitSize = newBitSize;
}

void BitArray::clear() {
    delete[] array;
    bitSize = 0;
    elSize = 0;
}

void BitArray::push_back(bool bit) {
    if (elSize * BITS_IN_LONG > bitSize) {      //   memory doesn't need to be added
        int pos = BITS_IN_LONG - (bitSize % (int)BITS_IN_LONG) - 1;
        array[bitSize / BITS_IN_LONG] = SetBit(bit, array[bitSize / BITS_IN_LONG], pos);
        bitSize++;
    }
    else {      //   memory need to be added
        resize(bitSize + 1);
        int pos = BITS_IN_LONG - (bitSize % (int)BITS_IN_LONG);
        array[bitSize / BITS_IN_LONG] = SetBit(bit, array[bitSize / BITS_IN_LONG], pos);
    }
}

BitArray &BitArray::operator&=(const BitArray &b) {
    if (bitSize != b.bitSize) {
        cout << "Error: different sizes of arrays! Operation is cancelled" << endl; // ќЅ–јЅќ“ј“№ ќЎ»Ѕ ”!!!
    }
    else {
        for (int i = 0; i < elSize; i++) {
            array[i] = array[i] & b.array[i];
        }
    }
    return (BitArray &) *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    if (bitSize != b.bitSize) {
        cout << "Error: different sizes of arrays! Operation is cancelled" << endl; // ќЅ–јЅќ“ј“№ ќЎ»Ѕ ”!!!
    }
    else {
        for (int i = 0; i < elSize; i++) {
            array[i] = array[i] | b.array[i];
        }
    }
    return (BitArray &) *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    if (bitSize != b.bitSize) {
        cout << "Error: different sizes of arrays! Operation is cancelled" << endl; // ќЅ–јЅќ“ј“№ ќЎ»Ѕ ”!!!
    }
    else {
        for (int i = 0; i < elSize; i++) {
            array[i] = array[i] ^ b.array[i];
        }
    }
    return (BitArray &) *this;
}

void BitArray::to_string () const
{
    string bit_array = "";
    for (int i = 0; i < bitSize; i++)
    {
        unsigned long el = array[i / 32];
        unsigned long mask = 1;
        mask <<= 31 - (i % 32);
        el &= mask;
        if (el)
        {
            bit_array += '1';
        }
        else
        {
            bit_array += '0';
        }
    }
    cout << bit_array;
}

BitArray &BitArray::operator<<=(int shift) {
    if (shift < bitSize) {
        for (int i = 0; i < bitSize - shift; i++) {
            bool bit = CheckBit(array[(i + shift) / BITS_IN_LONG], BITS_IN_LONG - shift - i - 1);
            array[i / BITS_IN_LONG] = SetBit(bit, array[i / BITS_IN_LONG], BITS_IN_LONG - 1 - i);

            this->to_string();
            cout << endl;
        }

        for (int i = bitSize - shift; i < bitSize; i++) {
            int pos = BITS_IN_LONG - (i % (int) BITS_IN_LONG);
            array[i / BITS_IN_LONG] = SetBit(0, array[i / BITS_IN_LONG], pos);

            this->to_string();
            cout << endl;
        }
    }
    else {
        for (int i = 0; i < bitSize; i++) {
            int pos = BITS_IN_LONG - (i % (int)BITS_IN_LONG) - 1;
            array[i / BITS_IN_LONG] = SetBit(0, array[i / BITS_IN_LONG], pos);

            this->to_string();
            cout << endl;
        }
    }
    return *this;
}






