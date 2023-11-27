#include <iostream>

using namespace std;

//const修饰成员函数
class Date {
public:

    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

    bool operator++() const {
        //(*this)._year++;//const
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

    return 0;
}
