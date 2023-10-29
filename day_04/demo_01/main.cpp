#include <iostream>

using namespace std;

class Date {
public:

//    // 如果用户显式定义了构造函数，编译器将不再生成
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }


    void Print() {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

//默认构造函数
int main() {
    // 将Date类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函数
    // 将Date类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再生成
    // 无参构造函数，放开后报错：error C2512: “Date”: 没有合适的默认构造函数可用
    Date d1;
    return 0;
}