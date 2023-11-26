
//415. 字符串相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        string retStr;
        int len1 = num1.size() - 1;
        int len2 = num2.size() - 1;

        int next = 0;//进位
        while (len1 >= 0 || len2 >= 0) {
            //从后往前加，加完插入到新字符串
            int val1 = 0;
            int val2 = 0;//字符串到头了就加0
            if (len1 >= 0) {
                val1 = num1[len1--] - '0';
            }
            if (len2 >= 0) {
                val2 = num2[len2--] - '0';
            }
            int sum = val1 + val2 + next;
            next = sum / 10;
            sum %= 10;
            retStr += sum + '0';
        }
        //最后一次加如果sum大于10，就得再加1
        if (next == 1) {
            retStr += '1';
        }
        reverse(retStr.begin(), retStr.end());
        return retStr;
    }
};