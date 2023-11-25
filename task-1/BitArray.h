#ifndef CPP_LABS_BITARRAY_H
#define CPP_LABS_BITARRAY_H

#include <string>
#include <iostream>
using namespace std;


class BitArray {
private:

    /**
     * array     stores a pointer to a dynamic array of type unsigned long
     *
     * bitSize   store the index of the last bit +1
     *           accessing bits larger than the specified parameter does not guarantee the return of the specified value or leads to a program error
     *
     * elSize   stores directly the number of unsigned long type elements in a dynamic array
     */
    unsigned long *array;
    int bitSize;
    int elSize;


    /**
     *
     * it is used to check a certain bit in a number
     *
     * @param value     a variable of the unsigned long type in which the value of the bit must be checked
     * @param pos       the number of the bit, starting from the lowest (index of the lowest bit = 0), the value of which needs to be checked
     * @return          boolean representation of the checked bit
     */
    bool CheckBit(unsigned long value, int pos) const;

    /**
     *
     * it is used to set a certain bit in a number
     *
     * @param bit       the value of the bit to be put in the number
     * @param value     the number to which the bit will be set
     * @param pos       the number of the bit, starting from the lowest (index of the lowest bit = 0), the value of which needs to be changed
     * @return          the value of the unsigned long type with the changed bit
     */
    unsigned long SetBit(bool bit, unsigned long value, int pos) const;


    /**
    *
    * the implementation of wrapper that is used when index operator is called.
    * we use this wrapper to save the pointer to original BitArray container and later get or set the bit with given index.
    *
    */
    class Wrapper {
    private:
        unsigned int index;
        BitArray *wrapArray;

    public:

        /**
         *
         * Create Wrapper object on index from BitArray
         *
         * @param BitArray      a pointer to an object of the BitArray class, the data from which will be used
         * @param ind           bit index from BitArray
         */

        Wrapper(BitArray *BitArray, int ind);

        /**
         * assignment operator to set new value to the BitArray on chosen index.
         *
         * For example:
         *
         *      array[0] = true;
         *
         * @param bit   new value that we want to set
         * @return      pointer to itself
         */
        Wrapper &operator=(bool bit);

        /**
         * assignment operator to set new value to BitArray from another BitArray
         *
         * For example:
         *
         *      array1[0] = array2[1];
         *
         * @param other     pointer to another BitArray and bit index
         * @return          pointer to itself
         */
        Wrapper &operator=(const Wrapper &other);

        /**
         * type conversion operator from Wrapper to bool
         *
         * @return      bool representation of bit with specified index
         */
        operator bool() const;
    };

public:
    /**
     * Create an empty BitArray with array-pointer = nullptr
     */
    BitArray();

    /**
     * Clear array and memory
     */
    ~BitArray();

    /**
     * constructs an array for storing a given number of bits (bitSize).
     * the first sizeof(long) bits can be initialized using the value parameter
     */
    explicit BitArray(int bitSize, unsigned long value = 0);

    /**
     * copy-constructor
     *
     * @param other     the object on the basis of which the copy will be created
     */
    BitArray(const BitArray &other);

    /**
     * exchanges the values of two BitArrays
     *
     * @param other     BitArray used for exchange
     */
    void swap(BitArray &other);

    /**
     * operator for assigning values of one BitArray to another
     *
     * @param other     array of values from which will be used
     * @return          pointer to updated array
     */
    BitArray &operator=(const BitArray &other);

    /**
     * sets the new size of the array. reduces the amount of allocated memory if the size decreases and allocates additional memory if the array increases
     *
     * @param newBitSize    new size of array
     * @param value         values with which the array will be filled in case of its expansion (by default false)
     */
    void resize(int newBitSize, bool value = false);

    /**
     * clear the array, set array pointer =nullptr
     */
    void clear();

    /**
     * add new element to array increasing the size. also allocates an additional amount of memory, if necessary
     *
     * @param bit       value of new added bit
     */
    void push_back(bool bit);



    /**
     * bitwise operations on arrays (only for arrays of the same size)
     */

    BitArray &operator&=(const BitArray &other);

    BitArray &operator|=(const BitArray &other);

    BitArray &operator^=(const BitArray &other);

    /**
     * bit shift of the array, new values are filled with zeros
     *
     * @param shift     the number by which the array will be shifted
     * @return          pointer to itself
     */
    BitArray &operator<<=(int shift);

    BitArray &operator>>=(int shift);

    BitArray operator<<(int shift) const;

    BitArray operator>>(int shift) const;


    /**
     * sets the bit with getted index to value of bit (by default =true)
     * @return      pointer to itself
     */
    BitArray &set(int ind, bool bit = true);

    /**
     * sets the value of all bits to true
     * @return      pointer to itself
     */
    BitArray &set();

    /**
     * sets the bit with getted index to false.
     *
     * @param ind       index of bit that we want to set to false
     * @return          pointer to itself
     */
    BitArray &reset(int ind);

    /**
     * sets the value of all bits to false
     * @return      pointer to itself
     */
    BitArray &reset();

    /**
     * @return      true, if the array contains a true bit
     */
    bool any() const;

    /**
     * @return      true, if all bits of the array are false
     */
    bool none() const;

    /**
     * the operator of inverting bits in an array
     *
     * @return      new object of class with converted bits
     */
    BitArray operator~() const;

    /**
     * @return      the number of bits equal to 1
     */
    int count() const;


    /**
     *  it is used to process a bit of an array at a given index (to read and to write)
     *
     * @param ind   index of the bit
     * @return      object of Wrapper class with a given index
     *
     * @see Wrapper
     */
    Wrapper operator[](int ind);

    /**
     * @return      the size of array (the index of the last bit -1, the value of which is stored in the array memory)
     */
    int size() const;

    /**
     * @return      true if array size = 0
     */
    bool empty() const;

    /**
     * @return      string representation of array
     */
    string to_string() const;

    /**
     * a simple method for returning the bit value at a given index
     *
     * @param ind   index of the bit whose value will be returned
     * @return      bool representation of the value of the bit
     */
    bool getBit(int ind) const;

};

/**
 * operator of bitwise comparison of arrays
 * @param a     first operand of comparison
 * @param b     second operand of comparison
 * @return      true if the array a is exactly the same as b
 */
bool operator==(const BitArray & a, const BitArray & b);

/**
 * operator of bitwise comparison of arrays
 * @param a     first operand of comparison
 * @param b     second operand of comparison
 * @return      true if array a is different from array b
 */
bool operator!=(const BitArray & a, const BitArray & b);

/**
 * bitwise action operators for arrays (not necessarily of different lengths)
if the arrays have different sizes, then the last bits of the larger array retain their values
 */
BitArray operator&(const BitArray& a, const BitArray& b);
BitArray operator|(const BitArray& a, const BitArray& b);
BitArray operator^(const BitArray& a, const BitArray& b);


#endif //CPP_LABS_BITARRAY_H