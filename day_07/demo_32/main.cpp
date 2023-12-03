#include <iostream>

using namespace std;

//多参数函数模版
template<typename T1, class T2>

void Swap(T1 &a, T2 &b) {
    T1 tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 1, b = 2;
    double c = 1.1, d = 2.2;
    Swap(a, b);
    Swap(c, d);
    Swap(a, c);
    return 0;
}