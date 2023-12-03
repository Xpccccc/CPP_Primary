#include <iostream>

using namespace std;

//string类对象的访问及遍历操作
int main() {
    const string str1("hello ynu");
    string str2("hello ynu");

//    str1[1] = '1';//常量string对象，这里调用的是const char& operator[] (size_t pos) const;
    str2[1] = 'n';
    str2.at(2) = 'y';

    char ch1 = str2.back();
    char ch2 = str2.front();

    string::iterator it2 = str2.begin();
    while (it2 != str2.end()) {
        cout << *it2;
        fflush(stdout);//将缓冲区数据刷新到终端
        it2++;
    }
    cout << endl;

    //const迭代器
    string::const_iterator it1 = str1.begin();
    while (it1 != str1.end()) {
        cout << *it1;
        it1++;
    }
    cout << endl;

    //反向迭代器
    string::reverse_iterator it3 = str2.rbegin();
    while (it3 != str2.rend()) {
        cout << *it3;
        it3++;
    }
    cout << endl;

    //专属/const迭代器
    string::const_iterator it = str1.cbegin();
    while (it != str1.end()) {
        cout << *it;
        it++;
    }
    cout << endl;

    //范围for
    for (auto e: str2) {
        cout << e;
    }
    cout << endl;
    return 0;
}

