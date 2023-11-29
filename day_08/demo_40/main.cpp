#include <iostream>

using namespace std;

//string类对象的修改操作

int main() {

    string s1("hello world");
    string s2("no no no");

    //operator+=
    s2 += "hh";
    s2 += 'x';
    s2 += s1;

    //append
    s1.append(1, 'x');
    s1.append("hh");
    s1.append(s2);

    //push_back
    s2.push_back('x');

    //insert
    s1.insert(0, "xx");
    s1.insert(0, 2, 'x');


    //erase
    s1.erase(0, 4);

    //replace
    s1.replace(0, 4, "x");

    //swap
    s1.swap(s2);

    //c_str
    const char *str = s1.c_str();

    //data
    const char *str1 = s1.data();

    string s3("hello world");

    //copy
    char buffer[20] = {0};
    size_t length = s3.copy(buffer, 8, 0);
    buffer[length] = '\0';
    cout << buffer << endl;

    //find
    size_t found1 = s3.find('d', 3);
    cout << found1 << endl;

    size_t found2 = s3.find('f');
    //测试是不是用int表示的-1
    int test = found2;
    cout << found2 << endl;
    cout << test << endl;

    //rfind
    size_t found3 = s3.rfind("ll", 5);
    cout << found3 << endl;

    string s4("hello gun qnd world haha no --skas wcl cb ");

    //find_first_of
    size_t found4 = s4.find_first_of("gunwcqnd", 0);

    while (found4 != std::string::npos) {
        s4[found4] = '*';
        found4 = s4.find_first_of("gunwcqnd", found4 + 1);
    }
    cout << s4 << endl;

    //substr
    string sub_str = s4.substr(0, 9);
    cout << sub_str << endl;

    return 0;
}
