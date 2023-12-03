#include <iostream>

using namespace std;

//单参数函数模版
template<typename T>

void Swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 1, b = 2;
    Swap(a, b);

    double c = 1.1, d = 2.2;
    Swap(c, d);

    char e = 1, f = 2;
    Swap(e, f);

    return 0;
}