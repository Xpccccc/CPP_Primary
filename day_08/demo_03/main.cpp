
//387. 字符串中的第一个唯一字符
class Solution {
public:
    int firstUniqChar(string s) {
        int alpha[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            alpha[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (alpha[s[i] - 'a'] == 1) {
                return i;
            }
        }
        //不存在
        return -1;
    }
};