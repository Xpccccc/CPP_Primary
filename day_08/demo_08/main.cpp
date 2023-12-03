#include <iostream>

using namespace std;


class Solution {
public:
    //字符串相加
    string addStrings(string num1, string num2) {
        string retStr;
        int len1 = num1.size() - 1;
        int len2 = num2.size() - 1;

        int next = 0;//进位
        while(len1>=0 || len2>=0){
            //从后往前加，加完插入到新字符串
            int val1 = 0;
            int val2 = 0;//字符串到头了就加0
            if(len1 >= 0){
                val1 = num1[len1--]-'0';
            }
            if(len2 >= 0){
                val2 = num2[len2--]-'0';
            }
            int sum = val1 + val2 + next;
            next = sum/10;
            sum %= 10;
            retStr += sum + '0';
        }
        //最后一次加如果sum大于10，就得再加1
        if(next == 1){
            retStr += '1';
        }
        reverse(retStr.begin(),retStr.end());
        return retStr;
    }

    //43. 字符串相乘
    string multiply(string num1, string num2) {
        string retStr("0");
        int len_big = num1.size() - 1;
        int len_small = num2.size() - 1;

        //确定哪个是长的字符串，默认num1为长，num2为短

        string small = num2;
        string big = num1;
        if (len_big < len_small) {
            swap(len_big, len_small);
            small.swap(big);//减少拷贝
        }

        //上大字符串，下小字符串来乘法，
        for (int i = len_small; i >= 0; --i) {
            int next = 0;
            //用tmp记录每次乘出的结果
            string tmp;
            for (int j = len_big; j >= 0; --j) {
                int val_big = big[j] - '0';
                int val_small = small[i] - '0';

                int mul = val_big * val_small + next;
                next = mul / 10;
                mul %= 10;

                tmp += mul + '0';
            }
            if (next >= 1) {
                tmp += '0' + next;
            }
            reverse(tmp.begin(), tmp.end());

            //small字符串每向前移动一位来乘法，按上述计算出的字符串得多加一个0
            tmp += string(len_small - i, '0');

            retStr = addStrings(tmp, retStr);
        }
        //  如果第一个字符为0，则一定为全0，直接返回0
        if(retStr[0] == '0')
            return "0";
        return retStr;
    }
};


int main() {
    Solution so;
    string s1("123");
    string s2("46");
    so.multiply(s1, s2);
}
