#include "BitArray.h"
#include <iostream>
#include <cassert>

#define BITS_IN_LONG (sizeof(unsigned long) * 8)

bool BitArray::CheckBit(const unsigned long value, const int pos) const {
    unsigned long result;
    if ((value & (1 << pos)) == 0) {
        result = 0;
    }
    else {
        result = 1;
    }
    return result;
}

unsigned long BitArray::SetBit(const bool bit, unsigned long value, const int pos) const {
    if (bit == 1) {
        value =  (value | (1 << pos));
        return value;
    }
    else {
        value = (value & ~(1 << pos));
        return value;
    }
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

BitArray & BitArray::operator=(const BitArray &other) {
    delete[] array;
    this->elSize = other.elSize;
    this->bitSize = other.bitSize;
    this->array = new unsigned long [other.elSize];

    for (int i = 0; i < other.elSize; i++) {
        this->array[i] = other.array[i];
    }
    return *this;
}

void BitArray::resize(int newBitSize, bool value) {   //�������� ������ �������. � ������ ����������, ����� �������� ���������������� ��������� value.
    int newElSize;
    if (newBitSize % BITS_IN_LONG == 0) {
        newElSize = (int) (newBitSize / BITS_IN_LONG);
    } else {
        newElSize = (int) (newBitSize / BITS_IN_LONG + 1);
    }
    auto *newArray = new unsigned long[newElSize];

    if (newBitSize > bitSize) {
        for (int i = 0; i < bitSize; i++) {
            newArray[i / BITS_IN_LONG] = array[i / BITS_IN_LONG];
        }
        for (int i = bitSize; i < newBitSize; i++) {
            int pos = BITS_IN_LONG - (int) (i % BITS_IN_LONG);
            newArray[i / BITS_IN_LONG] = SetBit(value, newArray[i / BITS_IN_LONG], pos);
        }
    }
    else {
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
    assert(bitSize == b.bitSize && "incorrect size of arrays");
    for (int i = 0; i < elSize; i++) {
        array[i] = array[i] & b.array[i];
    }
    return (BitArray &) *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    assert(bitSize == b.bitSize && "incorrect size of arrays");
    for (int i = 0; i < elSize; i++) {
        array[i] = array[i] | b.array[i];
    }
    return (BitArray &) *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    assert(bitSize == b.bitSize && "incorrect size of arrays");
    for (int i = 0; i < elSize; i++) {
        array[i] = array[i] ^ b.array[i];
    }
    return (BitArray &) *this;
}

string BitArray::to_string() const {
    string strArray = {};
    for (int i = 0; i < bitSize; i++) {
        bool bit = CheckBit(array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
        if (bit) {
            strArray += '1';
        }
        else {
            strArray += '0';
        }
    }
    return strArray;
}



BitArray &BitArray::operator<<=(int shift) {
    assert(shift >= 0 && "shift is above zero");
    if (shift < bitSize) {
        for (int i = 0; i < bitSize - shift; i++) {
            bool bit = CheckBit(array[(i + shift) / BITS_IN_LONG], BITS_IN_LONG - shift - (i % BITS_IN_LONG) - 1);
            array[i / BITS_IN_LONG] = SetBit(bit, array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
        }
        for (int i = bitSize - shift; i < bitSize; i++) {
            int pos = BITS_IN_LONG - (i % (int) BITS_IN_LONG) - 1;
            array[i / BITS_IN_LONG] = SetBit(false, array[i / BITS_IN_LONG], pos);
        }
    }
    else {
        for (int i = 0; i < bitSize; i++) {
            int pos = BITS_IN_LONG - (i % (int)BITS_IN_LONG) - 1;
            array[i / BITS_IN_LONG] = SetBit(false, array[i / BITS_IN_LONG], pos);
        }
    }
    return *this;
}

BitArray &BitArray::operator>>=(int shift) {
    assert(shift >= 0 && "shift is above zero");
    if (shift < bitSize) {
        for (int i = bitSize - 1; i >= shift; i--) {
            bool bit = CheckBit(array[(i - shift) / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) + shift - 1);
            array[i / BITS_IN_LONG] = SetBit(bit, array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
        }
        for (int i = 0; i < shift; i++) {
            int pos = BITS_IN_LONG - (i % (int) BITS_IN_LONG) - 1;
            array[i / BITS_IN_LONG] = SetBit(false, array[i / BITS_IN_LONG], pos);
        }
    }
    else {
        for (int i = 0; i < bitSize; i++) {
            int pos = BITS_IN_LONG - (i % (int)BITS_IN_LONG) - 1;
            array[i / BITS_IN_LONG] = SetBit(false, array[i / BITS_IN_LONG], pos);
        }
    }
    return *this;
}

BitArray BitArray::operator<<(int shift) const {
    assert(shift >= 0 && "shift is above zero");
    BitArray newArray = *this;
    newArray <<= shift;
    return newArray;
}

BitArray BitArray::operator>>(int shift) const {
    assert(shift >= 0 && "shift is above zero");
    BitArray newArray = *this;
    newArray >>= shift;
    return newArray;
}

BitArray &BitArray::set(int pos, bool bit) {
    assert(pos >= bitSize && "array index out of bounds");
    array[pos / BITS_IN_LONG] = SetBit(bit, array[pos / BITS_IN_LONG], BITS_IN_LONG - (pos % BITS_IN_LONG) - 1);
    return *this;
}

BitArray &BitArray::set() {
    for (int i = 0; i < bitSize; i++) {
        array[i / BITS_IN_LONG] = SetBit(true, array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
    }
    return *this;
}

BitArray &BitArray::reset(int pos) {
    assert(pos >= bitSize && "array index out of bounds");
    array[pos / BITS_IN_LONG] = SetBit(false, array[pos / BITS_IN_LONG], BITS_IN_LONG - (pos % BITS_IN_LONG) - 1);
    return *this;
}

BitArray &BitArray::reset() {
    for (int i = 0; i < bitSize; i++) {
        array[i / BITS_IN_LONG] = SetBit(false, array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
    }
    return *this;
}

bool BitArray::any() const {
    for (int i = 0; i < bitSize; i++) {
        bool bit = CheckBit(array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
        if (bit) {
            return true;
        }
    }
    return false;
}

bool BitArray::none() const {
    for (int i = 0; i < bitSize; i++) {
        bool bit = CheckBit(array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
        if (bit) {
            return false;
        }
    }
    return true;
}

BitArray BitArray::operator~() const {
    BitArray newArray = *this;
    for (int i = 0; i < newArray.bitSize; i++) {
        bool bit = CheckBit(array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
        array[i / BITS_IN_LONG] = SetBit(1 - bit, array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
    }
    return newArray;
}

int BitArray::count() const {
    int sum = 0;
    for (int i = 0; i < bitSize; i++) {
        bool bit = CheckBit(array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
        sum += bit;
    }
    return sum;
}

bool BitArray::operator[](int i) const {
    bool bit = CheckBit(array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
    return bit;
}

int BitArray::size() const {
    return bitSize;
}

bool BitArray::empty() const {
    if (bitSize == 0) {
        return true;
    }
    return false;
}


void BitArray::swap(BitArray &b) {
    int newBitSize;
    BitArray tmpArray;
    bool copyThis;
    if (this->bitSize > b.bitSize) {
        newBitSize = this->bitSize;
        copyThis = true;
    } else {
        newBitSize = b.bitSize;
        copyThis = false;
    }

    tmpArray.resize(newBitSize);
    for (int i = 0; i < tmpArray.bitSize; i++) {
        bool bit;
        if (copyThis) {
            bit = CheckBit(this->array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
        } else {
            bit = CheckBit(b.array[i / BITS_IN_LONG], BITS_IN_LONG - (i % BITS_IN_LONG) - 1);
        }
        tmpArray.set(i, bit);
    }
    if (copyThis) {
        this->array = b.array;
        this->elSize = b.elSize;
        this->bitSize = b.bitSize;

        b.array = tmpArray.array;
        b.elSize = tmpArray.elSize;
        b.bitSize = tmpArray.bitSize;
        delete tmpArray.array;
    }
    else {
        b.array = this->array;
        b.elSize = this->elSize;
        b.bitSize = this->bitSize;

        this->array = tmpArray.array;
        this->elSize = tmpArray.elSize;
        this->bitSize = tmpArray.bitSize;
        delete tmpArray.array;
    }
}

bool operator==(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return false;
    }
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
}

bool operator!=(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return true;
    }
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return true;
            }
        }
        return false;
    }
}

BitArray operator&(const BitArray& a, const BitArray& b) {
    assert(a.size() == b.size() && "incorrect size of arrays");
    BitArray newArray(a.size());
    for (int i = 0; i < a.size(); i++) {
        newArray.set(i, a[i] & b[i]);
    }
    return newArray;
}

BitArray operator|(const BitArray& a, const BitArray& b) {
    assert(a.size() == b.size() && "incorrect size of arrays");
    BitArray newArray(a.size());
    for (int i = 0; i < a.size(); i++) {
        newArray.set(i, a[i] | b[i]);
    }
    return newArray;
}

BitArray operator^(const BitArray& a, const BitArray& b) {
    assert(a.size() == b.size() && "incorrect size of arrays");
    BitArray newArray(a.size());
    for (int i = 0; i < a.size(); i++) {
        newArray.set(i, a[i] ^ b[i]);
    }
    return newArray;
}




