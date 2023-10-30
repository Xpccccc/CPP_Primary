#include <iostream>

using namespace std;

class Time {
public:
    Time() {
        cout << "Time()" << endl;
        _hour = 0;
        _minute = 0;
        _second = 0;
    }

private:
    int _hour;
    int _minute;
    int _second;
};


class Date {
private:
    // 基本类型(内置类型)
    int _year;
    int _month;
    int _day;
    // 自定义类型
    Time _t;
};

//基本类型(内置类型)和自定义类型调用默认构造函数
//基本类型(内置类型)调用自己的默认构造函数， 自定义类型调用它的类的默认构造函数（如果没有默认构造函数就需要用到初始化列表）
int main() {
    Date d;
    return 0;
}
