#include <iostream>

using namespace std;

//函数模版的实例化（含显式实例化和隐式实例化）

template<class T>

T Add(const T &left, const T &right) {
    return left + right;
}

int main() {
    int a1 = 10, a2 = 20;
    double d1 = 10.0, d2 = 20.0;
    Add(a1, a2);//推导出a1，a2是int类型
    Add(d1, d2);//推导出d1，d2是double类型

    /*
    该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
    通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
    编译器无法确定此处到底该将T确定为int 或者 double类型而报错
    注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
    Add(a1, d1);
    */

    // 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
    //1. 用户自己来强制转化
    int a = 1;
    double d = 2.1;
    Add(a, (int) d);

    //2. 使用显式实例化
    int b = 1;
    double c = 2.1;
    Add<int>(b, c);//这里c就被强转化为int类型
    return 0;
}

