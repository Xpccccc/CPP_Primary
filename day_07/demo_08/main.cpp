#include <iostream>

using namespace std;

//非const成员函数内可以调用其它的const成员函数
class Date {
public:

    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

    bool operator==(const Date &d) const {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    bool operator++() {
        Date aa(2022, 1, 1);
        *this == aa;
        (*this)._year++;
    }

private:
    int _year; // 非const变量
    int _month;
    int _day;
    const int y = 1; // const变量
};