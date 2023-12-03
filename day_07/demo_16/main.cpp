#include <iostream>

using namespace std;

//static成员使用规则
class Date {
public:

    //    Date(int year)
    //            : _year(year) {}

    Date(int year, int month = 1, int day = 1)
            : _year(year), _month(month), _day(day) {}


    //static成员函数没有this指针
    static void Show(int n) {
        cout << n << endl;
    }

private:
    int _year;
    int _month;
    int _day;
    static int n;//声明
};

int Date::n = 1;//定义

int main() {
    Date::Show(2);
    return 0;
}