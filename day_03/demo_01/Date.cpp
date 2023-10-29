//
// Created by 徐鹏 on 2023/10/27.
//

#include "Date.h"

// 全缺省的构造函数
//声明和定义分离，需要指定类域
Date::Date(int year, int month, int day) {
    if (year >= 0 && (month >= 1 && month <= 12) && (day <= GetMonthDay(year, month))) {
        _year = year;
        _month = month;
        _day = day;
    } else {
        cout << "初始化的日期有误" << endl;
        assert(year >= 0 && (month >= 1 && month <= 12) && (day <= GetMonthDay(year, month)));
    }

}

// 拷贝构造函数
// d2(d1)
Date::Date(const Date &d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

// 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
Date &Date::operator=(const Date &d) {
    if (this != &d) {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    return *this;
}

// 析构函数
Date::~Date() {
//    cout << "~Date()" << endl;
}

// 日期+=天数  -- 改变原值
Date &Date::operator+=(int day) {
    //如果输入的day小于0
    if (day < 0) {
        *this -= -day;
        return *this;
    }
    _day += day;
    //加后的天数大于当月天数的最大值
    while (_day > GetMonthDay(_year, _month)) {
        _day -= GetMonthDay(_year, _month);
        _month++;
        if (_month == 13) {
            _month = 1;
            _year++;
        }
    }
    return *this;
}

// 日期+天数  --  不改变原值
Date Date::operator+(int day) {
    Date temp(*this);
    temp += day;
    return temp;
}

// 日期-=天数  --  改变原值
Date &Date::operator-=(int day) {
    //如果输入的day小于0
    if (day < 0) {
        *this += -day;
        return *this;
    }
    _day -= day;
    while (_day <= 0) {
        _month--;
        if (_month == 0) {
            _year--;
            if (_year == 0) {
                printf("错误\n");
                exit(-1);
            }
            _month = 12;
        }
        _day += GetMonthDay(_year, _month);
    }
    return *this;
}

// 日期-天数  --  不改变原值
Date Date::operator-(int day) {
    Date temp(*this);
    temp -= day;
    return temp;
}


// 前置++  --  先+1再计算
Date &Date::operator++() {
    *this += 1;
    return *this;
}

// 后置++  --  先计算再+1
Date Date::operator++(int) {
    Date temp(*this);//拷贝构造
    temp += 1;
    return temp;
}

// 前置--  --  先-1再计算
Date &Date::operator--() {
    *this -= 1;
    return *this;
}

// 后置--  --  先计算再-1
Date Date::operator--(int) {
    Date temp(*this);//拷贝构造
    temp -= 1;
    return temp;
}


// >运算符重载
bool Date::operator>(const Date &d) {
    if (_year >= d._year) {
        if (_year > d._year)
            return true;
        else {
            //_year == d._year
            if (_month >= d._month) {
                if (_month > d._month)
                    return true;
                else {
                    //_month == d._month
                    if (_day >= d._day) {
                        if (_day > d._day)
                            return true;
                        else
                            return false;
                    }
                }
            }
        }
    }
    return false;
}

// ==运算符重载
bool Date::operator==(const Date &d) {
    return _year == d._year && _month == d._month && _day == d._day;
}

// >=运算符重载
bool Date::operator>=(const Date &d) {
    return (*this > d) || (*this == d);
}

// <运算符重载
bool Date::operator<(const Date &d) {
    return !(*this >= d);
}

// <=运算符重载
bool Date::operator<=(const Date &d) {
    return (*this < d) || (*this == d);
}

// !=运算符重载
bool Date::operator!=(const Date &d) {
    return !(*this == d);
}


// 日期-日期 返回天数
int Date::operator-(const Date &d) {
    //假设第一个参数的日期更大
    int flag = 1;
    int count = 0;
    Date max = *this;
    Date min = d;
    if (*this < d) {
        flag = -1;
        max = d;
        min = *this;
    }
    while (max != min) {
        ++min;
        count++;
    }
    return count * flag;
}
