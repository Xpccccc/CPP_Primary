#include <iostream>

using namespace std;

class Date {
public:
    //无参构造函数
    Date() {
        _year = 1;
        _month = 1;
        _day = 1;
    }

    //带参构造函数
    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

    void Print() {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

//Date d1();函数声明

//无参构造函数(默认构造函数)和带参构造函数
int main() {
    Date d1;//调用无参(默认)构造函数
    //为什么不是 Date d1(); ? 因为这和函数的声明的格式冲突了
    d1.Print();
    Date d2(2023, 10, 23);//调用带参构造函数
    d2.Print();
    return 0;
}
