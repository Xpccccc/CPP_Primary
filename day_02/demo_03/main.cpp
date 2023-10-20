#include <iostream>

using namespace std;

int Add(int a, int b) {
    return a + b;
}

float Add(float a, int b) {
    return a + b;
}

double Add(double a, int b) {
    return a + b;
}

int Add(double a, double b) {
    return a + b;
}

//函数重载
int main() {
    cout << Add(1, 1) << endl;
    cout << Add(1.1f, 1) << endl; //1.1f数据类型为float
    cout << Add(1.1, 1) << endl;//1.1 默认数据类型为double
    cout << Add(1.1, 1.1) << endl;
    std::cout << "Hello, World!" << std::endl;
    int a = 1, b = 0;
    int& c = a;
    int& d = a;
    int& c = b;
    return 0;
}
