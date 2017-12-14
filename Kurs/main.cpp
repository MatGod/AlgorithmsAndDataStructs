#include <iostream>
#include <limits>
#include <time.h>
#include "arr.h"
using namespace std;

int main() {
    srand(time(nullptr));
    char choise;
    do {
        cout << "(1) - Hand initialisation\n"
             << "(2) - Random array\n"
             << "(0) - Exit\n"
             << "Your choise: ";
        choise = cin.get();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        arr A;
        switch (choise) {
            case '1': {
                A.hand_init();
                break;
            }
            case '2': {
                A.rand_init();
                A.print();
                break;
            }
            case '0': {
                break;
            }
            default: {
                cout << "Error\n";
                continue;
            }
        }
        A.lsd_radix_sort();
        A.print();
    } while (choise != '0');
    return 0;
}