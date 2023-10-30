#include <iostream>

using namespace std;

class Time {
public:
    Time() {
        _hour = 1;
        _minute = 1;
        _second = 1;
    }

    Time(const Time &t) {
        _hour = t._hour;
        _minute = t._minute;
        _second = t._second;
        cout << "Time::Time(const Time&)" << endl;
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

//拷贝构造函数的调用规则
//基本类型(内置类型)调用本类的拷贝构造函数，自定义类型调用它的类的拷贝构造函数
int main() {
    Date d1;
    // 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
    // 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数（浅拷贝）
    Date d2(d1);
    return 0;
}
