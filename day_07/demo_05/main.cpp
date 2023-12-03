#include <iostream>

using namespace std;


//  const修饰成员函数
class Date {
public:
    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

    void Print() {
        cout << "Print()" << endl;
        cout << "year:" << _year << endl;
        cout << "month:" << _month << endl;
        cout << "day:" << _day << endl << endl;
    }

    void Print() const {
        cout << "Print()const" << endl;
        cout << "year:" << _year << endl;
        cout << "month:" << _month << endl;
        cout << "day:" << _day << endl << endl;
    }

private:
    int _year; // 年
    int _month; // 月
    int _day; // 日
};

void Test() {
    Date d1(2022, 1, 13);
    d1.Print();//Print()
    const Date d2(2022, 1, 13);//Printf()const
    d2.Print();
}

int main() {
    Test();
    return 0;
}