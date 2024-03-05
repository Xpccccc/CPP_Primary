
// JZ31 栈的压入、弹出序列

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int> &pushV, vector<int> &popV) {
        // write code here

        stack<int> st;
        int pushi = 0;
        int popi = 0;
        while (pushi < pushV.size()) {

            st.push(pushV[pushi++]);

            // 注意st全部出完之后，再访问st.top()就会出问题
            while (!st.empty() && st.top() == popV[popi]) {
                st.pop();
                popi++;
            }

        }

        return popi == popV.size();
    }
};