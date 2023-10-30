#include <iostream>

using namespace std;

//日期类
class Date {
public:
    //默认构造函数，与下面全缺省成员变量配合使用
    Date() {
    }

    Date(int year, int month, int day) { //你已经定义了自己的构造函数，编译器就不会再自动生成默认构造函数
        _year = year;
        _month = month;
        _day = day;
    }

    // 前置++ 加完原来的值也改变
    // *this就是d1
    Date &operator++() {
        _day += 1;
        return *this;
    }

    Date operator++(int ){ //后置++运算符重载就是这样规定的，参数加个int类型
        Date temp(*this);
        _day += 1;
        return temp;//临时对象，不能引用
    }

private:
    int _year = 1900;
    int _month = 1;
    int _day = 1;
};

//运算符重载之前置++和后置++
int main() {
    Date d1;
    Date d;

    d = ++d1;//d1.operator++(&d1);
    d = d1++;//d1.operator++(&d1,0);
    return 0;
}

