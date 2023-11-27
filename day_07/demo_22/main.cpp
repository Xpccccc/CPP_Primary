#include <iostream>

using namespace std;

//编译器对构造函数的一些优化
class Date {
public:
    //构造函数
    Date(int year, int month = 1, int day = 1) : _year(year), _month(month), _day(day) {
        cout << "Date(int year, int month, int day) " << endl;
    }

    //拷贝构造函数
    Date(Date &d) {
        cout << "Date(Date &d)" << endl;
    }


private:
    int _year;
    int _month;
    int _day;
};

Date func1(Date d) {
    Date tmp = d;
    return tmp;
}

void func2() {
    Date d1(1, 2, 3);
    //构造 + 构造 --> 构造
    Date d2 = d1;
    Date d3 = d2;
}

int main() {
//    Date d1(1999, 11, 14);
//    Date d2(2020,11,14);

    //同一个表达式中 构造 + 拷贝构造 --> 构造
    Date d3 = 1;
    //同一个表达式中 拷贝构造 + 拷贝构造 --> 拷贝构造
    Date d4 = func1(d3);
    func2();
}