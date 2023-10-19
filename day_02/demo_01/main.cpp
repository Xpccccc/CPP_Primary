#include <iostream>

using namespace std;

//int &Add(int a, int b) {
//    static int c = a + b;//只初始化一次
//    return c;
//}
//
//int main() {
//    int a = 1;
//    int &b = a;
//
//    cout << &b << endl << &a << endl;
//
//    int c = 2;
//    int d = 3;
//    int &ret = Add(c, d);//这里Add返回来的是c的别名，由于函数调用完后可能会清理栈桢，所以c的空间可能是随机值（但是这个编译器不清，所以c的空间放的值还是5）
//    cout << ret << endl;
//    ret = Add(7, 8);//这里返回的还是c的别名，但是c是在堆区的，所以值不变还是5
//    cout << ret << endl;
//
//    return 0;
//}

//#include <time.h>
//struct A{ int a[10000]; };
//void TestFunc1(A a){}
//void TestFunc2(A& a){}
//void TestRefAndValue()
//{
//    A a;
//    // 以值作为函数参数
//    size_t begin1 = clock();
//    for (size_t i = 0; i < 10000; ++i)
//        TestFunc1(a);
//    size_t end1 = clock();
//    // 以引用作为函数参数
//    size_t begin2 = clock();
//    for (size_t i = 0; i < 10000; ++i)
//        TestFunc2(a);
//    size_t end2 = clock();
//// 分别计算两个函数运行结束后的时间
//    cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//    cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main(){
//    TestRefAndValue();//传引用效率更高
//    return 0;
//}

//int main() {
//    //权限不能放大
//    const int a = 10;
//    //int &b = a;
//    const int &b = a;
//    const int &c = b;
//
//    //权限可以缩小
//    int d = 20;
//    const int &e = d;
//
//    //可以给常数取别名
//    const int &f = 10;
//
//    int i = 1;
//    double j = i;
//    //double &rj = i;
//    const double &rj = i;//i先int提升为double，提升后会有一个常变量记录这个提升后的i（i的原始值不变）,所以必须使用常量来引用
//
//    return 0;
//}

//void Swap(int &a, int &b) {
//    int tmp = a;
//    a = b;
//    b = tmp;
//}
//
//
//int main() {
//    int a = 1, b = 3;
//    cout << a << " " << b << endl;
//
//    Swap(a, b);
//    cout << a << " " << b << endl;
//    return 0;
//}

//int &Add(int a, int b) {
//    static int c = a + b;//只初始化一次
//    return c;
//}
//
//
//int main() {
//    int &ret = Add(1, 2);
//    cout << ret << endl;
//
//    Add(4, 5);
//    cout << ret << endl;
//    return 0;
//}

//#include <time.h>
//struct A{ int a[10000]; };
//A a;
//// 值返回
//A TestFunc1() { return a;}
//// 引用返回
//A& TestFunc2(){ return a;}
//void TestReturnByRefOrValue()
//{
//    // 以值作为函数的返回值类型
//    size_t begin1 = clock();
//    for (size_t i = 0; i < 100000; ++i)
//        TestFunc1();
//    size_t end1 = clock();
//    // 以引用作为函数的返回值类型
//    size_t begin2 = clock();
//    for (size_t i = 0; i < 100000; ++i)
//        TestFunc2();
//    size_t end2 = clock();
//    // 计算两个函数运算完成之后的时间
//    cout << "TestFunc1 time:" << end1 - begin1 << endl;
//    cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main(){
//    TestReturnByRefOrValue();//传引用效率更高
//    return 0;
//}

int main()
{
    int a = 10;
    int& ra = a;
    ra = 20;
    int* pa = &a;
    *pa = 20;
    return 0;
}