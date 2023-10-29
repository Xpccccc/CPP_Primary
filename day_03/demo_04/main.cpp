#include <iostream>

using namespace std;

class Person {
public:
    void showInfo();

public:
    int _age;
    char *_name;
    char *_sex;
};

void Person::showInfo() {
    cout << this->_age << endl << _name << endl << _sex << endl;
}

void Test() {
    //Person._age = 100;  // 编译失败：error C2059: 语法错误:“.”
    Person man;//实例化一个对象，占用物理空间
    man._age = 10;
    man._name = "hh";
    man._sex = "nan";
    man.showInfo();
}

//类的实例化(对象)
int main() {
    Test();
    return 0;
}
