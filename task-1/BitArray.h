#ifndef CPP_LABS_BITARRAY_H
#define CPP_LABS_BITARRAY_H

#include <string>
#include <iostream>
using namespace std;
//� ���� ������ ��� �������� �� ��������� ������ ��������� ���������,
//�� ��� ������ ����������� �� ������� ��������.
class BitArray {
private:
    unsigned long *array;
    int bitSize;
    int elSize;

    bool CheckBit(unsigned long value, int pos) const;

    unsigned long SetBit(bool bit, unsigned long value, int pos) const;


    class Wrapper {
    private:
        unsigned int index;
        BitArray *adrArr;

    public:
        Wrapper(BitArray *BitArray, int ind);

        Wrapper &operator=(bool bit);

        Wrapper &operator=(const Wrapper &other);

        operator bool() const;
    };

public:
    BitArray();

    ~BitArray();

    //������������ ������, �������� �������� ���������� ���.
    //������ sizeof(long) ��� ����� ��������������� � ������� ��������� value.
    explicit BitArray(int bitSize, unsigned long value = 0);

    BitArray(const BitArray &other);

    //���������� �������� ���� ������� ��������.
    void swap(BitArray &b);

    BitArray &operator=(const BitArray &b);

    //�������� ������ �������. � ������ ����������, ����� ��������
    //���������������� ��������� value.
    void resize(int newBitSize, bool value = false);

    //������� ������.
    void clear();

    //��������� ����� ��� � ����� �������. � ������ �������������
    //���������� ����������������� ������.
    void push_back(bool bit);


    //������� �������� ��� ���������.
    //�������� ������ �� �������� ����������� �������.
    //����������� ������� �� �������� ��������� ������� ������ � ������.
    BitArray &operator&=(const BitArray &b);

    BitArray &operator|=(const BitArray &b);

    BitArray &operator^=(const BitArray &b);

    //������� ����� � ����������� ������.
    BitArray &operator<<=(int shift);

    BitArray &operator>>=(int shift);

    BitArray operator<<(int shift) const;

    BitArray operator>>(int shift) const;


    //������������� ��� � �������� pos � �������� bit.
    BitArray &set(int pos, bool bit = true);

    //��������� ������ �������.
    BitArray &set();

    //������������� ��� � �������� pos � �������� false.
    BitArray &reset(int pos);

    //��������� ������ �����.
    BitArray &reset();

    //true, ���� ������ �������� �������� ���.
    bool any() const;

    //true, ���� ��� ���� ������� �����.
    bool none() const;

    //������� ��������
    BitArray operator~() const;

    //������������ ���������� ��������� ���.
    int count() const;


    //���������� �������� ���� �� ������� i.
//    bool operator[](int i) const;
    Wrapper operator[](int i);

    int size() const;

    bool empty() const;

    string to_string() const;

    bool getBit(int ind) const;

};
    //���������� ��������� ������������� �������.

bool operator==(const BitArray & a, const BitArray & b);
bool operator!=(const BitArray & a, const BitArray & b);

BitArray operator&(const BitArray& a, const BitArray& b);
BitArray operator|(const BitArray& a, const BitArray& b);
BitArray operator^(const BitArray& a, const BitArray& b);


#endif //CPP_LABS_BITARRAY_H