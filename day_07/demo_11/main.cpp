#include <iostream>

using namespace std;

//初始化列表特性
//每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)，
//构造函数里面可以进行赋值（初始化）（上述三个成员(引用、const成员变量、/没有默认构造函数的自定义类型成员变量)不能在构造函数里面初始化）
class Time {
public:
    Time(int hour, int minute, int second) {
        cout << "Time(int ,int , int )" << endl;
    }

private:
    int _hour;
    int _minute;
    int _second;
};

class Date {
public :
    Date(int year, int month, int day) : _year(year), _month(month), _day(day), _n(year), _x(1), _t(1, 1, 1) {
    }


private :
    int _year; // 年
    int _month; // 月
    int _day; // 日
    int &_n;//引用
    const int _x;//const成员变量
    Time _t;//没有默认构造函数的自定义类型成员变量
};

int main() {
    Date d1(2023, 11, 3);
    return 0;
}