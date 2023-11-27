#include <iostream>

//const修饰成员变量
class Date {
public:

    void operator++() {
        (this->x)++;
//        (this->y)++;//y是const成员变量，不能修改

    }

private:
    int x; // 非const变量
    const int y = 1; // const变量
};

int main() {
    Date d1;

    return 0;
}
