#include <iostream>

using namespace std;

int main() {
    int a;
    double b;
    char c;
    string d;
    // 可以自动识别变量的类型
    cin >> a;
    cin >> b >> c >> d;
    cout << a << d << endl;
    cout << b << " " << c << endl;
    return 0;
}
