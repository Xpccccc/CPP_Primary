#include <iostream>

using namespace std;

//string类对象的常见构造
int main() {
    //构造函数/拷贝构造函数
    string s1;
    cout << s1 << endl;

    string s2("hello");
    cout << s2 << endl;

    string s3(s2);
    cout << s3 << endl;

    string s4(s3, 2, 10);
    cout << s4 << endl;

    string s5("world", 2);
    cout << s5 << endl;

    return 0;
}

