#include <iostream>

using namespace std;

class Date {
public :
    Date(int year = 1900, int month = 1, int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }

    Date(const Date &d) {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    //Date &operator=(const Date* this, const Date &d)
    Date &operator=(const Date &d) {
        if (this != &d) {//防止自己给自己赋值
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        return *this;//支持连续赋值
    }

private:
    int _year;
    int _month;
    int _day;
};

void Test() {
    Date d1(2018, 9, 26);
    Date d2(2018, 9, 27);
    d1 = d2;//d1 = d2 --> d1.operator=(d2)
    d1.operator=(d2);//相当于 d1.operator=(&d1,d2);
}

// 赋值运算符的重载 -- 只能做成员函数，参数和返回值都必须引用
int main(){
    Test();
    return 0;
}