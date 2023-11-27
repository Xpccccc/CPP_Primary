#include <iostream>

using namespace std;

//一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板函数
// 专门处理int的加法函数
int Add(int left, int right) {
    return left + right;
}

// 通用加法函数
template<class T>
T Add(T left, T right) {
    return left + right;
}

int main() {
    Add(1, 2); // 与非模板函数匹配，编译器不需要特化
    Add<int>(1, 2); // 调用编译器特化的Add版本
    return 0;
}
