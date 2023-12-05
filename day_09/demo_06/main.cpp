#include <iostream>
#include <string>
#include <vector>

using namespace std;

//17. 电话号码的字母组合
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        //映射表
        const string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string current;//存储当前字母组合

        backtrack(digits, 0, mapping, current, result);
        return result;
    }

private:
    //回溯函数
    void backtrack(string digits, int index, const string mapping[], string &current, vector<string> &result) {
        //当字母组合长度等于字符串的长度，表示这趟组合完毕了
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        //取当前字母对应的字符串
        int digit = digits[index] - '0';
        const string letters = mapping[digit];
        for (auto e: letters) {
            //把当前字母加入到组合字母
            current.push_back(e);
            //递归进入下一个字符串
            backtrack(digits, index + 1, mapping, current, result);
            current.pop_back();//换下一个字母来组合
        }
    }

};

int main() {
    Solution s;
    string s1("234");
    s.letterCombinations(s1);
    return 0;
}
