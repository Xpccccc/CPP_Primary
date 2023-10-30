#include <iostream>

using namespace std;

class Date {
public:
    Date(int year = 1900, int month = 1, int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }
    // Date(const Date d)  // 错误写法：编译报错，会引发无穷递归
    Date(const Date &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
private:
    int _year;
    int _month;
    int _day;
};

// 拷贝构造函数得传引用
int main() {
    Date d1;
    Date d2(d1);
    return 0;
}
