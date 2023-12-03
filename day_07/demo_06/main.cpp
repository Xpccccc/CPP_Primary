#include <iostream>

using namespace std;

//权限只能缩小或者平移，不能变大
class Date {
public:

    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

    bool operator==(const Date &d) {
        return _year == d._year && _month == d._month && _day == d._day;
    }

private:
    int _year; // 非const变量
    int _month;
    int _day;
    const int y = 1; // const变量
};

int main() {
    const Date d1(2022, 1, 1);
    const Date d2(2022, 1, 2);
    //int ret = d1 == d2;//报错，这里const对象传给this，this的类型是Date* const而不是 const Date* ，因为*this才是对象，this是指针
    //cout << ret << endl;

    return 0;
}