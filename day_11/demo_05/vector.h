//
// Created by 徐鹏 on 2023/12/10.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>

#include "ReverseIterator.h"

using namespace std;

#ifndef DEMO_01_VECTOR_H
#define DEMO_01_VECTOR_H

#endif //DEMO_01_VECTOR_H

namespace xp {
    template<typename T>
    class vector {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;

        typedef ReverseIterator<iterator, T &, T *> reverse_iterator;
        typedef ReverseIterator<const_iterator, const T &, const T *> const_reverse_iterator;


        vector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}

//        vector(const vector<T> &v) {
//            _start = new T[v.capacity()];
//            memcpy(_start, v._start, v.size() * sizeof(T));
//            _finish = _start + v.size();
//            _end_of_storage = _start + capacity();
//        }

        //拷贝构造函数
        vector(const vector<T> &v) {
            reserve(v.capacity());
            for (const auto &e: v) {
                push_back(e);
            }
        }

        template<class InputIterator>
        //构造迭代器区间
        vector(InputIterator first, InputIterator last) {
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }

        vector(size_t n, const T &val = T()) {
            resize(n, val);
        }

        //防止和上面迭代器区间搞混
        vector(int n, const T &val = T()) {
            resize(n, val);
        }

        //赋值 ,这里vector<T> v在传值的时候就已经有拷贝构造了
        vector<T> &operator=(vector<T> v) {
            swap(v);
            return *this;
        }

        T &operator[](size_t n) {
            return *(_start + n);
        }

        const T &operator[](size_t n) const {
            return *(_start + n);
        }

        ~vector() {
            if (_start) {
                delete[] _start;
                _start = _finish = _end_of_storage = nullptr;
            }
        }

        void swap(vector<T> v) {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        void reserve(size_t n) {
            if (n > capacity()) {
                //开辟新空间
                size_t old_size = size();
                iterator tmp = new T[n];
                //start不为空，在复制完内容需要释放空间
                if (_start) {
//                    //对于自定义类型，在进行delete[] _start 之后（自定义类型里面存在指针开辟空间问题的时候），会把原来的_start里面内容进行析构和空间释放
//                    memcpy(tmp, _start, old_size * sizeof(T));

                    //  解决方案，进行深拷贝
                    for (size_t i = 0; i < old_size; ++i) {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                //这里要注意，得用之前的size，不然新size使用内联进来就是_finish = _start + _finish - _start
                _finish = _start + old_size;
                _end_of_storage = _start + n;
            }
        }

        void resize(size_t n, T val = T()) {
            if (n > capacity()) {
                size_t fill = _start + n - _finish;
                reserve(n);
                //填补之前finish后面fill个数据
                while (fill != 0) {
                    *_finish = val;
                    _finish++;
                    fill--;
                }
            }
        }

        void push_back(const T &val) {
            if (_finish == _end_of_storage) {
                size_t newCapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newCapacity);
            }
            *_finish = val;
            ++_finish;
        }

        void pop_back() {
            --_finish;
        }

        void insert(iterator pos, const T &val) {
            assert(pos >= _start);
            assert(pos <= _finish);

            if (_finish == _end_of_storage) {
                size_t len = pos - _start;
                size_t newCapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newCapacity);
                pos = _start + len;//防止增容量后，pos位置还是之前被释放的空间
            }
            //memmove(pos + 1, pos, sizeof(T) * (_finish - pos)); //浅拷贝，扩容可能存在迭代器失效问题
            iterator end = _finish - 1;
            while (pos <= end) {
                *(end + 1) = *end;
                --end;
            }
            *pos = val;
            ++_finish;
        }

        iterator begin() {
            return _start;
        }

        const_iterator begin() const {
            return _start;
        }

        iterator end() {
            return _finish;
        }

        const_iterator end() const {
            return _finish;
        }

        reverse_iterator rbegin() {
            return end();
        }

        const_reverse_iterator rbegin() const {
            return end();
        }

        reverse_iterator rend() {
            return begin();
        }

        const_reverse_iterator rend() const{
            return begin();
        }


        size_t size() const {
            return _finish - _start;
        }

        size_t capacity() const {
            return _end_of_storage - _start;
        }

    private:
        iterator _start = nullptr;
        iterator _finish = nullptr;
        iterator _end_of_storage = nullptr;
    };

    void test_vector1() {
        vector<char> v;
        v.reserve(10);
        cout << v.size() << " " << v.capacity() << endl;
//        v.resize(100);
        v.resize(100, 'x');
        cout << v.size() << " " << v.capacity() << endl;

    }

    void test_vector2() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        for (auto e: v) {
            cout << e << " ";
        }
        cout << endl;
    }

    void test_vector3() {
        vector<string> v;
        v.push_back("hh");
        v.insert(v.begin(), "2");
        v.insert(v.begin(), "2");
        v.insert(v.begin(), "2");
        v.insert(v.begin(), "2");
        v.insert(v.begin(), "2");
        v.insert(v.begin(), "2");
        v.insert(v.begin(), "2");
        v.insert(v.begin(), "2");
        for (auto e: v) {
            cout << e << " ";
        }
        cout << endl;
    }

    void test_vector4() {
        vector<string> v1;
        v1.push_back("hhh");
        v1.push_back("www");
        for (auto e: v1) {
            cout << e << " ";
        }
        cout << endl;

        vector<string> v2;
        v2.push_back("lllll");
        v2.push_back("nnnnn");
        for (auto e: v2) {
            cout << e << " ";
        }
        cout << endl;
        cout << "----------------------" << endl;
        v1 = v2;
        for (auto e: v1) {
            cout << e << " ";
        }
        cout << endl;
        for (auto e: v2) {
            cout << e << " ";
        }
        cout << endl;

    }

    void test_vector5() {
        vector<string> v;
        v.push_back("w");
        v.push_back("s");
        v.push_back("x");
        v.push_back("p");
        cout << v[1] << endl;
    }

    void test_vector6() {
        vector<string> v;
        v.push_back("w");
        v.push_back("s");
        v.push_back("x");
        v.push_back("p");
        v.push_back("p");
        v.push_back("p");
        v.push_back("p");
        v.push_back("p");
        v.push_back("psdf");
        v.push_back("pdsf");
        v.push_back("pfd");
        v.push_back("pdsf");
        v.insert(v.begin(), "sdas");
        for (auto e: v) {
            cout << e << " ";
        }
        cout << endl;
    }

    void test_vector7() {
        vector<string> v;
        v.push_back("w");
        v.push_back("s");
        v.push_back("x");
        v.push_back("p");
        v.push_back("p");
        v.push_back("p");
        vector<string> v2(v.begin(), v.end());
        for (auto e: v2) {
            cout << e << " ";
        }
        cout << endl;

        int a[] = {1111, 222, 222, 3};
        vector<int> v3(a, a + 4);
        for (auto e: v3) {
            cout << e << " ";
        }
        cout << endl;

        list<string> lt;
        lt.push_back("hjakds");
        lt.push_back("wq");
        lt.push_back("qw");
        lt.push_back("w");

        vector<string> v4(lt.begin(), lt.end());
        for (auto e: v4) {
            cout << e << " ";
        }
        cout << endl;

        vector<int> v5(5, 5);
        for (auto e: v5) {
            cout << e << " ";
        }
        cout << endl;
    }

    void test_vector8() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        vector<int>::reverse_iterator rit = v.rbegin();
        while (rit != v.rend()) {
            cout << *rit << " ";
            rit++;
        }
        cout << endl;
    }


}
