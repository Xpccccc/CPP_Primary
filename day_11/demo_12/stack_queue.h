#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

class Date {
public:
    // 获取某年某月的天数
    int GetMonthDay(int year, int month) {
        static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,
                               31};
        int day = days[month];
        if (month == 2
            && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
            day += 1;
        }
        return day;
    }


// 全缺省的构造函数
//声明和定义分离，需要指定类域
    Date(int year, int month, int day) {
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
    Date(const Date &d) {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

// 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
    Date &operator=(const Date &d) {
        if (this != &d) {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        return *this;
    }

// 析构函数
    ~Date() {
//    cout << "~Date()" << endl;
    }

// 日期+=天数  -- 改变原值
    Date &operator+=(int day) {
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
    Date operator+(int day) {
        Date temp(*this);
        temp += day;
        return temp;
    }

// 日期-=天数  --  改变原值
    Date &operator-=(int day) {
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
    Date operator-(int day) {
        Date temp(*this);
        temp -= day;
        return temp;
    }


// 前置++  --  先+1再计算
    Date &operator++() {
        *this += 1;
        return *this;
    }

// 后置++  --  先计算再+1
    Date operator++(int) {
        Date temp(*this);//拷贝构造
        temp += 1;
        return temp;
    }

// 前置--  --  先-1再计算
    Date &operator--() {
        *this -= 1;
        return *this;
    }

// 后置--  --  先计算再-1
    Date operator--(int) {
        Date temp(*this);//拷贝构造
        temp -= 1;
        return temp;
    }


// >运算符重载
    bool operator>(const Date &d) const {
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
    bool operator==(const Date &d) const {
        return _year == d._year && _month == d._month && _day == d._day;
    }

// >=运算符重载
    bool operator>=(const Date &d) const {
        return (*this > d) || (*this == d);
    }

// <运算符重载
    bool operator<(const Date &d) const {
        return !(*this >= d);
    }

// <=运算符重载
    bool operator<=(const Date &d) const {
        return (*this < d) || (*this == d);
    }

// !=运算符重载
    bool operator!=(const Date &d) const {
        return !(*this == d);
    }


// 日期-日期 返回天数
    int operator-(const Date &d) const {
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

    friend ostream &operator<<(ostream &out, Date &d);

private:
    int _year;
    int _month;
    int _day;
};

ostream &operator<<(ostream &out, Date &d) {
    out << d._year << " " << d._month << " " << d._day << endl;
    return out;
}

namespace xp {

    // 仿函数
    template<class T>
    class less {
    public:
        bool operator()(const T x, const T y) {
            return x > y;
        }
    };

    // 类模版偏特化
    template<class T1>
    class less<T1 *> {
    public:
        bool operator()(const T1 *const &x, const T1 *y) {
            return *x > *y;
        }
    };

    template<class T>
    class greater {
    public:
        bool operator()(const T x, const T y) {
            return x < y;
        }
    };

    // 类模版偏特化
    template<class T2>
    class greater<T2 *> {
    public:
        bool operator()(const T2 *x, const T2 *y) {
            return *x < *y;
        }
    };

    template<class T, class Container = vector<T>, class Compare= less<T> >
    class priority_queue {
        //  底层是一个堆
    public:
        // 假设默认是大根堆

        // 向上调整
        void Adjust_up(int child) {
            int parent = (child - 1) / 2;
            Compare com;
            while (child > 0) {
//                if (_con[child] > _con[parent]) {
                if (com(_con[child], _con[parent])) {
                    swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                } else {
                    break;// 调整结束
                }
            }

        }

        // 向下调整
        void Adjust_down(int parent) {
            Compare com;
            // 假设左孩子比右孩子更大
            int child = parent * 2 + 1;
            //如果右孩子存在
            if (child + 1 < _con.size() && com(_con[child + 1], _con[child])) {
                ++child;
            }

            // 此时child是左右孩子值更大的那个
            while (child < _con.size()) {
                if (com(_con[child], _con[parent])) {
                    swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                } else {
                    break;// 调整结束
                }
            }

        }

        void push(const T &val) {
            _con.push_back(val);
            Adjust_up(_con.size() - 1);
        }

        void pop() {
            // 第一个元素和最后一个元素交换
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            Adjust_down(0);
        }

        const T &top() {
            return _con[0];
        }

        size_t size() const {
            return _con.size();
        }

        bool empty() {
            return _con.empty();
        }

    private:
        Container _con;
    };


}
