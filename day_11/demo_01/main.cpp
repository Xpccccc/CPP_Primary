#include <iostream>

using namespace std;

//string底层结构，在各编译器下可能不同，CLion里是12+4+4+4

int main() {
    string s1("hhh");
    cout << sizeof(s1) << endl;
    string s2("11111111111111111111111111111111");
    cout << sizeof(s2) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
