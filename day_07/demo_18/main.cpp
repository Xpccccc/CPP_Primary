#include <iostream>

using namespace std;

//友元函数
class Date {
    friend ostream &operator<<(ostream &_cout, const Date &d);

    friend istream &operator>>(istream &_cin, Date &d);

public:
    Date(int year = 1900, int month = 1, int day = 1)
            : _year(year), _month(month), _day(day) {}

private:
    int _year;
    int _month;
    int _day;
};

ostream &operator<<(ostream &_cout, const Date &d) {
    _cout << d._year << "-" << d._month << "-" << d._day;
    return _cout;
}

istream &operator>>(istream &_cin, Date &d) {
    _cin >> d._year;
    _cin >> d._month;
    _cin >> d._day;
    return _cin;
}

int main() {
    Date d;
    cin >> d;
    cout << d << endl;
    return 0;
}
