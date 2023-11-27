#include <iostream>

using namespace std;

//友元类
class Time {
    friend class Date;  // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
    Time(int hour = 0, int minute = 0, int second = 0)
            : _hour(hour), _minute(minute), _second(second) {}

private:
    int _hour;
    int _minute;
    int _second;

};

class Date {
public:
    Date(int year = 1900, int month = 1, int day = 1)
            : _year(year), _month(month), _day(day) {}

    void SetTimeOfDate(int hour, int minute, int second) {
        // 直接访问时间类私有的成员变量
        _t._hour = hour;
        _t._minute = minute;
        _t._second = second;
    }

private:
    int _year;
    int _month;
    int _day;
    Time _t;
};