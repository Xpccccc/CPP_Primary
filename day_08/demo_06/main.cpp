#include <iostream>

using namespace std;

//541. 反转字符串 II
class Solution {
public:
    void reverseK(string &s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseStr(string s, int k) {
        int n = s.length();

        for (int i = 0; i < n; i += 2 * k) {
            // 计算每 2k 个字符的起始和结束索引
            int start = i;
            int end = min(i + k - 1, n - 1);

            // 反转前 k 个字符
            reverseK(s, start, end);
        }

        return s;
    }
};

int main() {
    Solution so;
    string s;
    int k;
    cin >> s >> k;
    string s1 = so.reverseStr(s, k);
    cout << s1 << endl;
    return 0;
}
