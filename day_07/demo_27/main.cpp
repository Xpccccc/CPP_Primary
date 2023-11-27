#include <iostream>

using namespace std;

//operator new与operator delete函数
class Date {
public:
    Date() : _year(1), _month(1), _day(1) {
        cout << "Date()" << endl;
    }

    Date(int year, int month, int day) : _year(1), _month(1), _day(1) {
        _year = year;
        _month = month;
        _day = day;
        cout << "Date()" << endl;
    }

    ~Date() {
        cout << "~Date()" << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};


int main() {
    Date *ptr1 = new Date();
    Date *ptr2 = new Date(2, 2, 2);

    //operator new -- 不调用构造函数 和 malloc 基本一样
    Date *ptr6 = (Date *) operator new(sizeof(Date));

    Date *ptr3 = new Date[10]{{1, 2, 2}};

    int a(1);
    free(ptr1);
    delete ptr2;
    delete[] ptr3;
    operator delete(ptr6);
    ptr6 = nullptr;
    return 0;
}

