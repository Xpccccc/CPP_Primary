#include <iostream>

using namespace std;

void Func(int a, int b = 10, int c = 20) { //缺省参数只能从后往前连续设置
    cout << a << " " << b << " " << c << endl;
}

int main() {
    Func(1); // 没有传参时，使用参数的默认值
    Func(10, 20); // 传参时，使用指定的实参
    Func(10, 20,30); // 传参时，使用指定的实参
    return 0;
}