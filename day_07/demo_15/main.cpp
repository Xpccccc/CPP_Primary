#include <iostream>

using namespace std;

//explicit关键字使用
class Date {
public:

    // 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
    // explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
//  explicit  Date(int year)
//            : _year(year) {}


    // 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转换作用
    // explicit修饰构造函数，禁止类型转换
    explicit Date(int year, int month = 1, int day = 1)
            : _year(year), _month(month), _day(day) {}

    Date &operator=(const Date &d) {
        if (this != &d) {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        return *this;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    Date d1(11);
    // 用一个整形变量给日期类型对象赋值
    // 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
    //d1 = 2023;//报错，有explicit关键字隐式转换不了
    //d1 = {2023, 11, 6};//同样报错
    // 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了构造函数类型转换的作用
    return 0;
}
