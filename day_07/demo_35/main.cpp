#include <iostream>

using namespace std;

//对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而不会从该模板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模板
// 专门处理int的加法函数
int Add(int left, int right) {
    return left + right;
}

// 通用加法函数
template<class T1, class T2>
T1 Add(T1 left, T2 right) {
    return left + right;
}

int main() {
    Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
    Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
    return 0;
}
