#include <iostream>

using namespace std;

#include <string>

//125. 验证回文串
class Solution {
public:
    bool isPalindrome(string s) {
        //移除非字母字符
        string str;
        for (auto e: s) {
            //这里注意A-z中间并不全是字符
            if ((e >= 'A' && e <= 'Z') || (e >= 'a' && e <= 'z') || (e >= '0' && e <= '9')) {
                str += tolower(e);
            }
        }
        //验证
        int left = 0;
        int right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution s;
    string s1;
    getline(cin, s1);
    bool ret = s.isPalindrome(s1);
    cout << ret << endl;
    return 0;
}
