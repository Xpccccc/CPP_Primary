#include <iostream>

using namespace std;

//初始化列表
//class Date {
//public :
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//
//private :
//    int _year; // 年
//    int _month; // 月
//    int _day; // 日
//};
//
//int main() {
//    Date d1(2023, 11, 3);
//    return 0;
//}

class Date {
public :
    Date(int year, int month, int day) : _year(year), _month(month), _day(day) {
    }


private :
    int _year; // 年
    int _month; // 月
    int _day; // 日
};

int main() {
    Date d1(2023, 11, 3);
    return 0;
}