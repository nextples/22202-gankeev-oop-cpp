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
        if (array != nullptr) {
            delete[] array;
            array = nullptr;
        }
}

BitArray::BitArray(const BitArray &other) {     // copy constructor
    this->elSize = other.elSize;
    this->bitSize = other.bitSize;
    this->array = new unsigned long [other.elSize];

    for (int i = 0; i < other.elSize; i++) {
        this->array[i] = other.array[i];
    }
}

BitArray::BitArray(int bitSize, unsigned long value) {     // constructor with start value
    assert(bitSize >= 0 && "Constructor: size of array is above zero");
    int newElSize;
    if (bitSize % BITS_IN_LONG == 0) {
        newElSize = (int)(bitSize / BITS_IN_LONG);
    }
    else {
        newElSize = (int)(bitSize / BITS_IN_LONG) + 1;

    }
    array = new unsigned long [bitSize / BITS_IN_LONG];
    this->bitSize = bitSize;
    this->elSize = newElSize;
    for (int i = 0; i < BITS_IN_LONG; i++) {
        bool bit = CheckBit(value, BITS_IN_LONG - i - 1);
        array[i / BITS_IN_LONG] = SetBit(bit, array[i / BITS_IN_LONG], BITS_IN_LONG - i - 1);
    }
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
    assert(bitSize >= 0 && "resize: size of array is above zero");
    int newElSize;
    if (newBitSize % BITS_IN_LONG == 0) {
        newElSize = (int) (newBitSize / BITS_IN_LONG);
    }
    else {
        newElSize = (int) (newBitSize / BITS_IN_LONG + 1);
    }
    auto *newArray = new unsigned long[newElSize];

    if (newBitSize > bitSize) {
        for (int i = 0; i < bitSize; i++) {
            newArray[i / BITS_IN_LONG] = array[i / BITS_IN_LONG];
        }
        for (int i = bitSize; i < newBitSize; i++) {
            int pos = BITS_IN_LONG - (int) (i % BITS_IN_LONG) - 1;
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
    if (array != nullptr) {
        delete[] array;
        array = nullptr;
    }
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
    assert(bitSize == b.bitSize && "operator &=: incorrect size of arrays");
    for (int i = 0; i < elSize; i++) {
        array[i] = array[i] & b.array[i];
    }
    return (BitArray &) *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    assert(bitSize == b.bitSize && "operator |=: incorrect size of arrays");
    for (int i = 0; i < elSize; i++) {
        array[i] = array[i] | b.array[i];
    }
    return (BitArray &) *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    assert(bitSize == b.bitSize && "operator ^=: incorrect size of arrays");
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
    assert(shift >= 0 && "operator <<=: shift is above zero");
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
    assert(shift >= 0 && "operator >>=: shift is above zero");
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
    assert(shift >= 0 && "operator <<: shift is above zero");
    BitArray newArray = *this;
    newArray <<= shift;
    return newArray;
}

BitArray BitArray::operator>>(int shift) const {
    assert(shift >= 0 && "operator >>: shift is above zero");
    BitArray newArray = *this;
    newArray >>= shift;
    return newArray;
}

BitArray &BitArray::set(int pos, bool bit) {
    assert(pos < bitSize && "set: array index out of bounds");
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
    assert(pos < bitSize && "reset: array index out of bounds");
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
    BitArray tmp(b);
    b = *this;
    *this = tmp;
}

BitArray::Wrapper BitArray::operator[](int i) {
    assert(i < this->size() && "operator[]: array index out of bounds");
    return BitArray::Wrapper(this, i);
}

bool BitArray::getBit(int ind) const {
    assert(ind < this->size() && "getBit: array index out of bounds");
    bool bit = CheckBit(array[ind / BITS_IN_LONG], BITS_IN_LONG - (ind % BITS_IN_LONG) - 1);
    return bit;
}

bool operator==(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return false;
    }
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a.getBit(i) != b.getBit(i)) {
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
            if (a.getBit(i) != b.getBit(i)) {
                return true;
            }
        }
        return false;
    }
}

BitArray operator&(const BitArray& a, const BitArray& b) {
    int newArraySize = max(a.size(), b.size());
    BitArray newArray(newArraySize);
    for (int i = 0; i < newArray.size(); i++) {
        if (i < a.size() && i < b.size()) {
            newArray.set(i, a.getBit(i) & b.getBit(i));
        }
        else {
            if (i > a.size()) {
                newArray.set(i, b.getBit(i));
            }
            else {
                newArray.set(i, a.getBit(i));
            }
        }
    }
    return newArray;
}

BitArray operator|(const BitArray& a, const BitArray& b) {
    int newArraySize = max(a.size(), b.size());
    BitArray newArray(newArraySize);
    for (int i = 0; i < newArray.size(); i++) {
        if (i < a.size() && i < b.size()) {
            newArray.set(i, a.getBit(i) | b.getBit(i));
        }
        else {
            if (i > a.size()) {
                newArray.set(i, b.getBit(i));
            }
            else {
                newArray.set(i, a.getBit(i));
            }
        }
    }
    return newArray;
}

BitArray operator^(const BitArray& a, const BitArray& b) {
    int newArraySize = max(a.size(), b.size());
    BitArray newArray(newArraySize);
    for (int i = 0; i < newArray.size(); i++) {
        if (i < a.size() && i < b.size()) {
            newArray.set(i, a.getBit(i) ^ b.getBit(i));
        }
        else {
            if (i > a.size()) {
                newArray.set(i, b.getBit(i));
            }
            else {
                newArray.set(i, a.getBit(i));
            }
        }
    }
    return newArray;
}

BitArray::Wrapper::Wrapper(BitArray *BitArray, int ind) {
    this->adrArr = BitArray;
    this->index = ind;
}

BitArray::Wrapper& BitArray::Wrapper::operator=(bool bit) {
    this->adrArr->set(bit, index);
    return *this;
}

BitArray::Wrapper &BitArray::Wrapper::operator=(const BitArray::Wrapper &other) {
    bool otherBit = other.adrArr->getBit((int)other.index);
    int pos = other.index;
    this->adrArr->set(pos, otherBit);
    return *this;
}

BitArray::Wrapper::operator bool() const {
    return this->adrArr->getBit(this->index);
}