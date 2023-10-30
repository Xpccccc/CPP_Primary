#include <iostream>

using namespace std;

class Time {
public:
    Time() {
        _hour = 1;
        _minute = 1;
        _second = 1;
    }

    //这里都是自定义类型赋值，其实可以不用自己实现
    Time &operator=(const Time &t) {
        if (this != &t) {
            _hour = t._hour;
            _minute = t._minute;
            _second = t._second;
        }
        return *this;
    }

private:
    int _hour;
    int _minute;
    int _second;
};

class Date {
private:
    // 基本类型(内置类型)
    int _year = 1970;
    int _month = 1;
    int _day = 1;
    // 自定义类型
    Time _t;
};

//赋值运算符的使用
int main() {
    Date d1;
    Date d2;
    d1 = d2;
    return 0;
}
