
// 150. 逆波兰表达式求值

class Solution {
public:
    int evalRPN(vector <string> &tokens) {
        stack<int> st;

        int i = 0;
        st.push(stoi(tokens[i++]));
        while (i < tokens.size()) {

            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                switch (tokens[i][0]) {
                    case '+' :
                        st.push(left + right);
                        break;
                    case '-' :
                        st.push(left - right);
                        break;
                    case '*' :
                        st.push(left * right);
                        break;
                    case '/' :
                        st.push(left / right);
                        break;
                }
                i++;
            } else {
                st.push(stoi(tokens[i++]));
            }
        }
        return st.top();
    }
};