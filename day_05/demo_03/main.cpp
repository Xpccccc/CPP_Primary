#include <iostream>

using namespace std;

class Date {
public:
    Date(int year, int minute, int day) {
        cout << "Date(int,int,int):" << this << endl;
    }

    Date(const Date &d) {
        cout << "Date(const Date& d):" << this << endl;
    }

    ~Date() {
        cout << "~Date():" << this << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

Date Test(Date d) {
    Date temp(d);
    return temp;//这里不调用拷贝构造函数可能是编译器优化了
}

//拷贝构造函数的使用
int main() {
    Date d1(2023, 10, 25);
    Test(d1);
    return 0;
}
