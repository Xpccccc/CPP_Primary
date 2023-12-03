#include <iostream>

using namespace std;

//写不写析构函数对于new T[N]在释放空间调用delete的区别
class Date {
public:
    Date() : _year(1), _month(1), _day(1) {
        cout << "Date()" << endl;
    }

    Date(int year, int month, int day) : _year(1), _month(1), _day(1) {
        //        _a = new int[10];
        _year = year;
        _month = month;
        _day = day;
        cout << "Date()" << endl;
    }

    //    ~Date() {
    //        cout << "~Date()" << endl;
    //    }

private:
    //    int* _a;
    int _year;
    int _month;
    int _day;
};


int main() {
    Date *ptr1 = new Date;
    delete ptr1;

    Date *ptr2 = new Date[10];
    // 这里如果不写析构函数(默认成员变量没有开辟空间，如果开辟了空间，必须调用析构函数释放空间，不然会内存泄露)的话就不报错
    // 因为成员变量都是内置类型没有开空间，不需要调用析构函数，也就不需要在前面添加4字节存个数
    delete ptr2;
    return 0;
}