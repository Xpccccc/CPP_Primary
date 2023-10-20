#include <iostream>

using namespace std;

//传统for
void TestFor1() {
    int array[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
        array[i] *= 2;
    for (int *p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
        cout << *p << endl;
}

//新型for
//for循环迭代的范围必须是确定的
//对于数组而言，就是数组中第一个元素和最后一个元素的范围；对于类而言，应该提供begin和end的方法，begin和end就是for循环迭代的范围。
void TestFor2() {
    int array[] = {1, 2, 3, 4, 5};
    for (auto &e: array)
        e *= 2;
    for (auto e: array)
        cout << e << " ";
    return 0;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

