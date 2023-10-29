#include <iostream>

using namespace std;

class Date {
public:

    //Date(){} //存在非默认构造函数时候，配合下面缺省成员变量使用
    Date(int year, int month, int day) { //你已经定义了自己的构造函数，编译器就不会再自动生成默认构造函数
        _year = year;
        _month = month;
        _day = day;
    }

    void Print() {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    //基本类型(内置类型),这里使用缺省的时候，可以直接使用编译器默认的构造函数，会传值帮它初始化为这个缺省值而不是随机值
    int _year = 1970;
    int _month = 1;
    int _day = 1;
};

//构造函数的使用
int main() {
    //Date d;//报错，找不到默认构造函数
    //d.Print();
    return 0;
}