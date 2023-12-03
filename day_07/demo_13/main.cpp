#include <iostream>

using namespace std;

//成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关。
class A {
public:
    A(int a)
            : _a1(a), _a2(_a1) {}

    void Print() {
        cout << _a1 << " " << _a2 << endl;//a2先声明，但是并没有初始化，
    }

private:
    int _a2;
    int _a1;
};

int main() {
    A aa(1);//1 随机值
    aa.Print();
}