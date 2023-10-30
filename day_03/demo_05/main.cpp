#include <iostream>

using namespace std;

// 类中既有成员变量，又有成员函数
class A1 {
public:
    void f1() {}

private:
    int _a;
};

// 类中仅有成员函数
class A2 {
public:
    void f2() {}
};

// 类中什么都没有---空类
class A3 {
};

//类对象的存储方式  -- 类的成员变量按结构体的内存对齐存储，类的成员函数存在公共代码区，空类大小为1字节
int main() {
    cout << sizeof(A1) << endl << sizeof(A2) << endl << sizeof(A3) << endl;
    return 0;
}

