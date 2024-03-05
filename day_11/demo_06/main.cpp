
// 155. 最小栈

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        _st.push(val);

        //  如果_minst为空，先入栈，因为当前这个val肯定是当前最小
        if(_minst.empty() || val <= _minst.top()){
            _minst.push(val);
        }else{
            _minst.push(_minst.top());
        }
    }

    void pop() {
        _st.pop();
        _minst.pop();
    }

    int top() {
        return _st.top();
    }

    int getMin() {
        return _minst.top();
    }

    stack<int> _st; // 栈
    stack<int> _minst; // 栈顶存当前最小值的栈
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */