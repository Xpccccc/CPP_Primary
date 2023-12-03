#include <iostream>

 using namespace std;

 //面试题：实现一个类，计算程序中创建出了多少个类对象。
 class A {
 public:
     A() { ++_scount; }

     A(const A &t) { ++_scount; }

     ~A() { --_scount; }

     int Sum() {
         GetACount();
         return 0;
     }

     static int GetACount() {
         return _scount;
     }

 private:
     static int _scount;
 };

 int A::_scount = 0;

 int main() {
     cout << A::GetACount() << endl;
     A a1, a2;
     A a3(a1);//拷贝构造函数
     cout << A::GetACount() << endl;
 }