#include <iostream>
//
//int main() {
//    int a = 1;
//    auto b = &a;
//    auto c = a;
//    auto d = b;
//    std::cout << typeid(a).name() << std::endl << typeid(b).name() << std::endl << typeid(c).name() << std::endl
//              << typeid(d).name() << std::endl;
//    return 0;
//}

//#include <string>
//#include <map>
//
//int main() {
//    std::map<std::string, std::string> m{{"apple",  "苹果"},
//                                         {"orange", "橙子"},
//                                         {"pear",   "梨"}};
//    std::map<std::string, std::string>::iterator it = m.begin();
//    //auto it = m.begin();
//
//    while (it != m.end()) {
//        //....
//    }
//    const int **p = nullptr;
//    return 0;
//}

using namespace std;

//int main() {
//    int x = 10;
//    auto a = &x;
//    auto *b = &x;
//    auto &c = x;
//    cout << typeid(a).name() << endl;
//    cout << typeid(b).name() << endl;
//    cout << typeid(c).name() << endl;
//    *a = 20;
//    *b = 30;
//    c = 40;
//    return 0;
//}

//void TestAuto()
//{
//    auto a = 1, b = 2;
//    //auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
//}

////auto不能用来声明数组
//void TestAuto() {
//    int a[] = {1, 2, 3};
//    auto b[] = {4，5，6};
//}
//
//// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
//void TestAuto(auto a)
//{
//    //考虑一个问题，如果这个函数定义了，但是没调用，那么auto推导的类型是什么？所以肯定不行吧
//}