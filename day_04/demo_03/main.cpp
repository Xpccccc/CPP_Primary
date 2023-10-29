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
    int _year = 1970;
    int _month = 1;
    int _day = 1;
    // 自定义类型
    Time _t;
};

//缺省成员变量
int main() {
    Date d;
    return 0;
}


