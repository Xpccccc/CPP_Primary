#include <iostream>

using namespace std;

// 类里面的operator==
class Date {

public:
    Date(int year = 1900, int month = 1, int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }

    //干脆重载成成员函数。
    //bool operator==(const Date* this,const Date &d2)
    //隐含了this
    bool operator==(const Date &d2) {
        return this->_year == d2._year
               && _month == d2._month
               && _day == d2._day;
    }

private:
    int _year;
    int _month;
    int _day;
};


void Test() {
    Date d1(2018, 9, 26);
    Date d2(2018, 9, 27);
    cout << (d1 == d2) << endl;//流插入运算符优先级比重载的运算符 == 高 ，所以加括号提升优先级
    //d1 == d2 --> d1.operator==(d2)
    cout << d1.operator==(d2) << endl;//相当于d1.operator==(&d1,d2);
}

// ==运算符重载成成员函数
int main() {
    Test();
    return 0;
}
