#include <iostream>

using namespace std;

//const成员函数内可以调用其它的非const成员函数
class Date {
public:

    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

    bool operator++() {
        (*this)._year++;
    }

    int jj(int x) {
        return ++x;
    }

    bool operator==(const Date &d) const {
        Date a(11, 1, 1);
        ++a;
        int b = 1;
        //int c= jj(this,b);//报错，jj不是const成员函数
        return _year == d._year && _month == d._month && _day == d._day;
    }

private:
    int _year; // 非const变量
    int _month;
    int _day;
    const int y = 1; // const变量
};

int main() {
    Date d1(2022, 1, 1);
    Date d2(2022, 1, 2);
    int ret = d1 == d2;
    cout << ret << endl;

    return 0;
}