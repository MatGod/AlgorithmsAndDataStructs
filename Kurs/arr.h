//
// Created by MatGod on 14.12.2017.
//

#ifndef KURS_ARR_H
#define KURS_ARR_H


class arr {
    int* values;
    int size;
public:
    arr();
    arr(const arr &Ar);
    ~arr();
    arr& operator = (const arr &Ar);
    void lsd_radix_sort();
    void msd_radix_sort();
    void rand_init();
    void hand_init();
    void print();
};


#endif //KURS_ARR_H
