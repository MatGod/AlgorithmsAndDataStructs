//
// Created by MatGod on 14.12.2017.
//

#ifndef KURS_RADIX_TEST_H
#define KURS_RADIX_TEST_H


class radix_test
{
    const int bit; // bit position [0..31] to examine
public:
    radix_test(int offset) : bit(offset) {} // constructor

    bool operator()(int value) const // function call operator
    {
        if (bit == 31) // sign bit
            return value < 0; // negative int to left partition
        else
            return !(value & (1 << bit)); // 0 bit to left partition
    }
};


#endif //KURS_RADIX_TEST_H
