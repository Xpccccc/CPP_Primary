#include <iostream>

using namespace std;

//string类非成员函数
int main() {

    //operator+
    string s1("hello");
    string s2("world");

    string s3 = s1 + s2;
    cout << s3 << endl;
    string s4 = s1 + 'x';
    cout << s4 << endl;

    //operator==
    bool b = s1 == s2;
    cout << b << endl;

    //swap
    cout << s1 << endl;
    cout << s2 << endl;
    swap(s1, s2);
    cout << s1 << endl;
    cout << s2 << endl;

    //operator>>
    cin >> s1;
    cout << s1 << endl;

    //operator<<
    cout << s2 << endl;

    string s5("hello ynu");
    //getline
    getline(cin, s5);
    cout << s5 << endl;

    return 0;
}

