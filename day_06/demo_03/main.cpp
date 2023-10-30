#include <iostream>

#include "Date.h"

//Date类的实现
int main() {
    Date d;
    Date d1(2023, 10, 27);
    Date d2;
    Date d3(2100, 7, 22);

//    d2 += 10;
//    d3 = d2 + 10;
//
//    d2 -= 10;
//    d3 = d2 - 10;

    d1 -= 100;
    d1 -= -100;

    cout << (d1 - d2) << endl;

    return 0;
}
