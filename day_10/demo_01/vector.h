//
// Created by 徐鹏 on 2023/12/10.
//

#include <cstdio>
#include <cstring>

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
                    memcpy(tmp, _start, old_size * sizeof(T));
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
            memmove(pos + 1, pos, sizeof(T) * (_finish - pos));
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

}
