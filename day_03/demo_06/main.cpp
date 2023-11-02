#include <iostream>

using namespace std;
//this指针
class Date {
public:
    void Init(int year, int month, int day) { //void Init( Date* const this, int year, int month, int day)
        _year = year;
        _month = month;
        _day = day;
        //this->_year = year;
        //this->_month = month;
        //this->_day = day;
    }

    void Print() { // void Print( Date* const this)  -- this不能改变，*this可以
        cout << _year << "-" << _month << "-" << _day << endl;
        //cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
    }

private:
    int _year;// 年
    int _month;// 月
    int _day;// 日
};

//this指针
int main() {
    Date d1, d2;
    d1.Init(2022, 1, 11);
    //d1.Init(&d1, 2022, 1, 11);
    d2.Init(2022, 1, 12);
    d1.Print();
    //d1.Print(&d1);
    d2.Print();
    return 0;
}

