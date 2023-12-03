#include <iostream>

using namespace std;

//构造函数隐式类型转换
class Date {
public:

    //    Date(int year)
    //            : _year(year) {}

    Date(int year, int month = 1, int day = 1)
            : _year(year), _month(month), _day(day) {}

    Date &operator=(const Date &d) {
        if (this != &d) {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        return *this;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    Date d1(11);

    // 用一个整型变量给日期类型对象赋值
    // 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
    d1 = 2023;//2023先转换为Date类型，然后用2023构造一个无名对象，相当于 d1 =  d2(2023)
    d1 = (2021, 2, 1); //逗号表达式的值是最后一个数值（这里是1） 相当于  d1 =  d3(1)
    d1 = {2021, 2, 1};//相当于 d1 = d4(2021, 2, 1)
    return 0;
}

//class Date {
//public:
//
////    Date(int year)
////            : _year(year) {}
//
//    //这里验证构造函数的隐式类型转换功能  ---  需要隐式类型转换的变量类型必须和构造函数的参数类型匹配
//    Date(int *n) {}
//
//    Date(int year, int month = 1, int day = 1)
//            : _year(year), _month(month), _day(day) {}
//
//    Date &operator=(const Date &d) {
//        if (this != &d) {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    int *p = nullptr;
//    Date d1(2023, 11, 6);
//    d1 = p;//这里p进行隐式类型转换了，先创建一个临时对象，再将临时对象赋值给d1
//
//    int** num = nullptr;
//    //d1 = num;//报错，这里num和构造函数的参数类型不匹配
//    Date d2 = {2023, 11, 6};
//    const Date &d3 = {2023, 11, 6};
//
//    return 0;
//}