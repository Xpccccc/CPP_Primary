#include <iostream>

using namespace std;

//取地址及const取地址操作符重载
class Date {
public :

    Date() : _year(1), _month(1), _day(1) {
        _year = 2;
        _month = 3;
        _day = 4;
    }

    Date *operator&() {
        cout << "operator&()" << endl;
        return this;

    }

    const Date *operator&() const {
        cout << "operator&() const" << endl;
        return this;
    }

private :
    int _year; // 年
    int _month; // 月
    int _day; // 日
};

int main() {
    Date d1, d2;
    const Date d3;
    cout << &d1 << endl << &d2 << endl << &d3 << endl;
    return 0;
}