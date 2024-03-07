#include "stack_queue.h"

#include <stack>
#include <queue>


void test_stack() {
    stack<int> st;
    st.push(1);
    st.push(3);
    st.push(2);
    st.push(7);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

void test_queue() {
    queue<int, list<int>> q;
    q.push(1);
    q.push(3);
    q.push(2);
    q.push(7);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}


void test_priority_queue() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(7);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;
}

int main() {

    // 使用
    test_stack();
    test_queue();
    test_priority_queue();

    // 实现
//    xp::test_stack1();
//    xp::test_queue1();
//    xp::test_priority_queue1();
    return 0;
}
