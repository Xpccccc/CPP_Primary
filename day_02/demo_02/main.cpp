#include <iostream>

inline int Add(int a, int b) {
    return a + b;
}

//内联函数，一个函数的代码量如果少于10行（根据编译器而定）则不用开辟栈桢（和C的宏差不多）
int main() {
    int a = 0;
    Add(3,4);
    std::cout << Add(4, 6) << std::endl;
    return 0;
}
