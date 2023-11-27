#include <iostream>

using namespace std;

//尽量使用初始化列表初始化，因为不管你是否使用初始化列表，对于自定义类型成员变量，一定会先使用初始化列表初始化
class Time {
public:
    Time(int hour = 0)
            : _hour(hour) {
        cout << "Time()" << endl;
    }

private:
    int _hour;
};

class Date {
public:
    Date(int day) {
        cout << "Date()" << endl;
    }

private:
    int _day;
    Time _t;
};

int main() {
    Date d(1);
}

