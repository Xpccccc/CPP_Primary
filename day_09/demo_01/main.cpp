#include <iostream>
#include <string>

static const size_t npos = -1;
using namespace std;

    //HJ1 字符串最后一个单词的长度
int main() {
    string s;
    getline(cin, s);
    size_t pos = s.rfind(' ');
    if (pos == s.size() - 1) {
        pos = s.rfind(' ', pos - 1);
    }
    cout << s.size() - pos - 1 << endl;
}
// 64 位输出请用 printf("%lld")