#include <iostream>
#include <string>

using namespace std;

//557. 反转字符串中的单词 III
class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        size_t pt = 0;
        //find没找到会返回-1(无符号，也就是最int大值)
        while (pt < 50000) {
            pt = s.find(' ', left);
            if (pt == s.size() - 1 || pt >= 50000) {// 最后一个字符是空格或者之后没找到' '
                break;
            }
            reverse(s.begin() + left, s.begin() + pt);//逆置pos前面的单词
            left = pt + 1;
        }
        if (pt >= 50000) {
            reverse(s.begin() + left, s.end());//如果是后面没找到' '，说明最后一个单词需要逆置
        }
        return s;
    }
};

int main() {
    Solution so;
    string s;
    int k;
    getline(cin, s);
    string s1 = so.reverseWords(s);
    cout << s1 << endl;
//    string s("hh h");
//    size_t i = s.find(' ', 0);
//    cout << i << endl;
    return 0;
}

