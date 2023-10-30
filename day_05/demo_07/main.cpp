#include <iostream>

using namespace std;

//赋值运算符重载的错误写法
class Date {
public:
    Date(int year = 1900, int month = 1, int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }

    int _year;
    int _month;
    int _day;
};

// 赋值运算符重载成全局函数，注意重载成全局函数时没有this指针了，需要给两个参数
Date &operator=(Date &left, const Date &right) {
    if (&left != &right) {
        left._year = right._year;
        left._month = right._month;
        left._day = right._day;
    }
    return left;
}
// 编译失败：
// error C2801: “operator =”必须是非静态成员