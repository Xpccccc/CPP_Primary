#include <iostream>

using namespace std;

//new/delete操作内置类型
int main() {
    // 动态申请一个int类型的空间
    int *ptr4 = new int;

    // 动态申请一个int类型的空间并初始化为10
    int *ptr5 = new int(10);

    cout << *ptr5 << endl;
    // 动态申请10个int类型的空间
    int *ptr6 = new int[3];
    // 动态申请10个int类型的空间并初始化前3个
    int *ptr7 = new int[3]{1, 2, 3};
    cout << ptr7[0] << ptr7[1] << ptr7[2] << ptr7[3];

    delete ptr4;
    delete ptr5;
    delete[] ptr6;
    delete[] ptr7;
}
