#ifndef CPP_LABS_BITARRAY_H
#define CPP_LABS_BITARRAY_H

#include <string>
#include <iostream>
using namespace std;
//В этой задаче для простоты не требуется делать контейнер шаблонным,
//но это вполне допускается по желанию студента.
class BitArray {
private:
    unsigned long *array;
    int bitSize;
    int elSize;

    bool CheckBit(unsigned long value, int pos) const;
    unsigned long SetBit(bool bit, unsigned long value, int pos) const;
public:
    BitArray();
    ~BitArray();

    //Конструирует массив, хранящий заданное количество бит.
    //Первые sizeof(long) бит можно инициализровать с помощью параметра value.
    explicit BitArray(int bitSize, unsigned long value = 0);
    BitArray(const BitArray &other);

    //Обменивает значения двух битовых массивов.
    void swap(BitArray& b);

    BitArray& operator=(const BitArray& b);

    //Изменяет размер массива. В случае расширения, новые элементы
    //инициализируются значением value.
    void resize(int newBitSize, bool value = false);
    //Очищает массив.
    void clear();
    //Добавляет новый бит в конец массива. В случае необходимости
    //происходит перераспределение памяти.
    void push_back(bool bit);


    //Битовые операции над массивами.
    //Работают только на массивах одинакового размера.
    //Обоснование реакции на параметр неверного размера входит в задачу.
    BitArray& operator&=(const BitArray& b);
    BitArray& operator|=(const BitArray& b);
    BitArray& operator^=(const BitArray& b);

    //Битовый сдвиг с заполнением нулями.
    BitArray& operator<<=(int shift);
    BitArray& operator>>=(int shift);
    BitArray operator<<(int shift) const;
    BitArray operator>>(int shift) const;


    //Устанавливает бит с индексом pos в значение bit.
    BitArray& set(int pos, bool bit = true);
    //Заполняет массив истиной.
    BitArray& set();

    //Устанавливает бит с индексом pos в значение false.
    BitArray& reset(int pos);
    //Заполняет массив ложью.
    BitArray& reset();

    //true, если массив содержит истинный бит.
    bool any() const;
    //true, если все биты массива ложны.
    bool none() const;
    //Битовая инверсия
    BitArray operator~() const;
    //Подсчитывает количество единичных бит.
    int count() const;


    //Возвращает значение бита по индексу i.
    bool operator[](int i) const;

    int size() const;
    bool empty() const;

    //Возвращает строковое представление массива.
    string to_string() const;
};

bool operator==(const BitArray & a, const BitArray & b);
bool operator!=(const BitArray & a, const BitArray & b);

BitArray operator&(const BitArray& a, const BitArray& b);
BitArray operator|(const BitArray& a, const BitArray& b);
BitArray operator^(const BitArray& a, const BitArray& b);


#endif //CPP_LABS_BITARRAY_H
