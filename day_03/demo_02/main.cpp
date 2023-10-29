#include <iostream>

using namespace std;

class Person {
public:
    void PrintPersonInfo();

private:
    char _name[20] = "xp";//缺省
    char _gender[4] = "man";
    int _age = 23;
};

// 这里需要指定PrintPersonInfo是属于Person这个类域
void Person::PrintPersonInfo() {
    cout << _name << " " << _gender << " " << _age << endl;
}

int main() {
    Person p;
    p.PrintPersonInfo();
    return 0;
}
