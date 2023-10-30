#include <iostream>

using namespace std;

class Date {
public:
    //默认构造函数(无参构造函数)
//    Date() {
//        _year = 1;
//        _month = 1;
//        _day = 1;
//    }
//   //默认构造函数(全缺省构造函数)
//    Date(int year = 1, int month = 1, int day = 1) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }

    //我们没写编译器默认生成的构造函数，对应下面的缺省成员变量，但是如果有构造函数（非默认）存在（你已经定义了自己的构造函数，编译器就不会再自动生成默认构造函数），
    //还想要调用默认构造函数的话，需要声明函数 Date(){}，否则调用默认构造函数编译器会找不到默认构造函数

    void Print() {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    //基本类型(内置类型),这里使用缺省的时候，可以直接使用编译器默认的构造函数，会传值帮它初始化为这个缺省值而不是随机值
    int _year = 1970;
    int _month = 1;
    int _day = 1;
};

// 三个默认构造函数
int main() {
    Date d;
    d.Print();
    return 0;
}
