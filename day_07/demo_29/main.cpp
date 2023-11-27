#include <iostream>

using namespace std;

//定位new
class Date {
public:
    Date() : _year(1), _month(1), _day(1) {
        cout << "Date()" << endl;
    }

    Date(int year, int month, int day) : _year(1), _month(1), _day(1) {
        _year = year;
        _month = month;
        _day = day;
        cout << "Date()" << endl;
    }

    ~Date() {
        cout << "~Date()" << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};


int main() {
    Date *p = (Date *) operator new(sizeof(Date));
    // 不能显式调用构造函数
    // p->Date();
    // 定位new可以显式调用构造函数
    new(p)Date(1, 1, 1);
    p->~Date();

    return 0;
}
