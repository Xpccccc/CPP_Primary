//
// Created by 徐鹏 on 2024/3/7.
//

#ifndef DEMO_10_STACK_QUEUE_H
#define DEMO_10_STACK_QUEUE_H

#endif //DEMO_10_STACK_QUEUE_H


#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>


using namespace std;



// 容器适配器 stack queue priority_queue使用及模拟实现
namespace xp {
    template<class T, class Container = deque<T>>
    class stack {
    public:

        void push(const T &val) {
            _con.push_back(val);
        }

        void pop() {
            _con.pop_back();
        }

        const T &top() {
            return _con.back();
        }

        size_t size() const {
            return _con.size();
        }

        bool empty() {
            return _con.empty();
        }


    private:
        Container _con; // 内置类型 ，不用自己构造析构
    };

    template<class T, class Container= deque<T>>
    class queue {
    public:

        void push(const T &val) {
            _con.push_back(val);
        }

        void pop() {
            _con.pop_front();
        }

        const T &back() {
            return _con.back();
        }

        const T &front() {
            return _con.front();
        }

        bool empty() {
            return _con.empty();
        }

        size_t size() const {
            return _con.size();
        }

    private:
        Container _con; // 内置类型 ，不用自己构造析构
    };

    // 仿函数
    template<class T>
    class less {
    public:
        bool operator()(const T x, const T y) {
            return x > y;
        }
    };

    template<class T>
    class greater {
    public:
        bool operator()(const T x, const T y) {
            return x < y;
        }
    };

    template<class T, class Container = vector<T>, class Compare= less<T> >
    class priority_queue {
        //  底层是一个堆
    public:
        // 假设默认是大根堆

        // 向上调整
        void Adjust_up(int child) {
            int parent = (child - 1) / 2;
            Compare com;
            while (child > 0) {
//                if (_con[child] > _con[parent]) {
                if (com(_con[child], _con[parent])) {
                    swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                } else {
                    break;// 调整结束
                }
            }

        }

        // 向下调整
        void Adjust_down(int parent) {
            Compare com;
            // 假设左孩子比右孩子更大
            int child = parent * 2 + 1;
            //如果右孩子存在
            if (child + 1 < _con.size() && com(_con[child + 1], _con[child])) {
                ++child;
            }

            // 此时child是左右孩子值更大的那个
            while (child < _con.size()) {
                if (com(_con[child], _con[parent])) {
                    swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                } else {
                    break;// 调整结束
                }
            }

        }

        void push(const T &val) {
            _con.push_back(val);
            Adjust_up(_con.size() - 1);
        }

        void pop() {
            // 第一个元素和最后一个元素交换
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            Adjust_down(0);
        }

        const T &top() {
            return _con[0];
        }

        size_t size() const {
            return _con.size();
        }

        bool empty() {
            return _con.empty();
        }

    private:
        Container _con;
    };

    void test_priority_queue1() {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(4);
        pq.push(41);
        pq.push(24);
        pq.push(2);
        pq.push(11);
        pq.push(1);
        pq.push(12);

        cout << pq.size() << endl;

        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
    }


    void test_queue1() {
        // 这里 Container不能用vector ，因为vector没有pop_front
        queue<int, list<int>> q;
        q.push(2);
        q.push(2);
        q.push(23);
        q.push(25);

        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }

    void test_stack1() {
        stack<int, list<int>> st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(1);

        cout << st.size() << endl;

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }

}
