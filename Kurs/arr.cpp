//
// Created by MatGod on 14.12.2017.
//

#include "arr.h"
#include "radix_test.h"
#include <algorithm>
#include <iostream>
using namespace std;

arr::arr() {
    size = 0;
    values = nullptr;
}

arr::arr(const arr &Ar) {
    values = new int[Ar.size];
    size = Ar.size;
    for (int i = 0; i < size; i++) {
        values[i] = Ar.values[i];
    }
}

arr::~arr() {
    if (size > 0) delete values;
}

arr& arr::operator = (const arr &Ar) {
    if (&Ar != this) {
        size = Ar.size;
        for (int i = 0; i < size; i++) {
            this->values[i] = Ar.values[i];
        }
    }
    return *this;
}

void arr::rand_init() {
    size = rand() % 20;
    values = new int[size];
    for (int i = 0; i < size; i++) {
        values[i] = rand();
    }
}

void arr::hand_init() {
    cout << "Введите количество элементов массива: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент №" << i + 1 << ": ";
        cin >> values[i];
    }
}

void arr::lsd_radix_sort()
{
    for (int lsb = 0; lsb < 32; ++lsb)
    {
        std::stable_partition(values, values + size, radix_test(lsb));
    }
}

void msd_radix_sort_inside(int *first, int *last, int msb = 31) {
    if (first != last && msb >= 0)
    {
        int *mid = std::partition(first, last, radix_test(msb));
        msb--;
        msd_radix_sort_inside(first, mid, msb);
        msd_radix_sort_inside(mid, last, msb);
    }
}

void arr::msd_radix_sort() {
    msd_radix_sort_inside(values, values + size);
}

void arr::print() {
    for (int i = 0; i < size; i++) {
        cout << values[i] << ' ';
    }
    cout << endl;
}