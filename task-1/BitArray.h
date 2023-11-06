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

    bool CheckBit(const unsigned long value, const int pos) const;
    unsigned long SetBit(const bool bit, unsigned long value, const int pos) const;
public:
    BitArray();
    ~BitArray();

    //������������ ������, �������� �������� ���������� ���.
    //������ sizeof(long) ��� ����� ��������������� � ������� ��������� value.
    explicit BitArray(int num_bits, unsigned long value = 0);
    BitArray(const BitArray &other);

    //���������� �������� ���� ������� ��������.
    void swap(BitArray& b);

    BitArray& operator=(const BitArray& b); /*https://www.youtube.com/watch?v=nMM98LVJn-U&list=PLQOaTSbfxUtCrKs0nicOg2npJQYSPGO9r&index=97&t=594s*/


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
    BitArray& operator&=(const BitArray& b);
    BitArray& operator|=(const BitArray& b);
    BitArray& operator^=(const BitArray& b);

    //������� ����� � ����������� ������.
    BitArray& operator<<=(int shift);
    BitArray& operator>>=(int shift);
    BitArray operator<<(int shift) const;
    BitArray operator>>(int shift) const;


    //������������� ��� � �������� pos � �������� bit.
    BitArray& set(int pos, bool bit = true);
    //��������� ������ �������.
    BitArray& set();

    //������������� ��� � �������� pos � �������� false.
    BitArray& reset(int pos);
    //��������� ������ �����.
    BitArray& reset();

    //true, ���� ������ �������� �������� ���.
    bool any() const;
    //true, ���� ��� ���� ������� �����.
    bool none() const;
    //������� ��������
    BitArray operator~() const;
    //������������ ���������� ��������� ���.
    int count() const;


    //���������� �������� ���� �� ������� i.
    bool operator[](int i) const;

    int size() const;
    bool empty() const;

    //���������� ��������� ������������� �������.
    string to_string() const;
};

bool operator==(const BitArray & a, const BitArray & b);
bool operator!=(const BitArray & a, const BitArray & b);

BitArray operator&(const BitArray& a, const BitArray& b);
BitArray operator|(const BitArray& a, const BitArray& b);
BitArray operator^(const BitArray& a, const BitArray& b);


#endif //CPP_LABS_BITARRAY_H
