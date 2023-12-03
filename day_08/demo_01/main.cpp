
// 把字符串转换成整数

class Solution {
public:

    long long InvertNum(string str, int len) {
        long long num = 0;
        // 0直接返回
        if (len == 0 && str[len] == '0')
            return 0;
        while (len >= 0) {
            num += (str[len] - '0') * pow(10, str.size() - len - 1);
            //  判断非法
            if (str[len] > '9' || str[len] < '0') {
                return 0;
            }
            len--;
        }
        return num;
    }

    int StrToInt(string str) {
        int flag = 0;//记录非法字符串
        long long ret = 0;
        int len = 0;
        //  确定长度
        if (str[0] == '+' || str[0] == '-') {
            string str1(str, 1, 100); // 只要后面字符
            len = str1.size() - 1;
            ret = InvertNum(str1, len);
        } else {
            string str1(str);
            len = str1.size() - 1;
            ret = InvertNum(str1, len);
        }

        if (str[0] == '-')
            return -ret;
        else
            return ret;
    }

};