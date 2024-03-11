#include <iostream>

// 仿函数类
class MultiplyBy {
public:
    MultiplyBy(int factor) : _factor(factor) {}

    // 重载函数调用运算符
    int operator()(int x) const {
        return x * _factor;
    }

private:
    int _factor;
};

int main() {
    MultiplyBy multiplyByTwo(2);// 初始化_factor
    MultiplyBy multiplyByFive(5);

    // 使用仿函数   ----   使用()
    std::cout << "Result 1: " << multiplyByTwo(3) << std::endl;    // 输出：6
    std::cout << "Result 2: " << multiplyByFive(4) << std::endl;   // 输出：20

    return 0;
}