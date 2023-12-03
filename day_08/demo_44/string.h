//
// Created by 徐鹏 on 2023/11/29.
//

#include <cstring>
#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;


#ifndef DEMO_44_STRING_H
#define DEMO_44_STRING_H

#endif //DEMO_44_STRING_H

namespace xp {

    class string {
    public:
        //构造函数
        string() : _str(new char[1]), _size(0), _capacity(0) {
            _str[0] = '\0';//空字符串也包含一个\0
        }

        string(const char *s);

        //拷贝构造函数
        string(const string &str);

        //字符串大小
        size_t size() const {
            return _size;
        }

        //总容量
        size_t capacity() const {
            return _capacity;
        }

        //string转char*
        const char *c_str() const {
            return _str;
        }

        //要求string类对象的容量调整为计划好的容量
        void reserve(size_t n);

        //将有效字符的个数改成n个
        void resize(size_t n);

        //清空字符串
        void clear() {
            _str[0] = '\0';
            _size = 0;//只清空数据，不清空容量
        }

        //判断字符串是不是空字符串
        bool empty() {
            return _size == 0;
        }

        //下标访问
        char &operator[](size_t pos);

        const char &operator[](size_t pos) const;

        char &at(size_t pos);

        const char &at(size_t pos) const;

        const char &back() const {
            return _str[_size - 1];
        }

        const char &front() const {
            return _str[0];
        }

        //迭代器
        typedef char *iterator;
        typedef const char *const_iterator;

        iterator begin() {
            return _str;
        }

        iterator end() {
            return _str + _size;
        }

        const_iterator begin() const {
            return _str;
        }

        const_iterator end() const {
            return _str + _size;
        }

        //尾插字符或者字符串
        void append(const string &str);

        void append(const char *s);

        //尾插字符或者字符串
        string &operator+=(const string &str);

        string &operator+=(const char *s);

        string &operator+=(char c);

        //尾插字符
        void push_back(char c);

        //从某个位置前插字符
        string &insert(size_t pos, const string &str);

        string &insert(size_t pos, const char *s);

        string &insert(size_t pos, size_t n, char c);

        //从某个位置向后删除n个字符
        string &erase(size_t pos = 0, size_t len = std::string::npos);

        //交换
        void swap(string &str);

        //从某个位置开始查找字符、字符串、string对象位置
        size_t find(const string &str, size_t pos = 0) const;

        size_t find(const char *s, size_t pos = 0) const;

        size_t find(char c, size_t pos = 0) const;

        //取子串
        string substr(size_t pos = 0, size_t len = npos) const;

        //赋值
        string &operator=(const string &str);

        string &operator=(const char *s);

        string &operator=(char c);

        ~string() {
            delete[] _str;
            _str = nullptr;
            _capacity = 0;
            _size = 0;
        }

    private:
        char *_str;
        size_t _capacity;
        size_t _size;
        static const size_t npos = -1;
    };

    //重载流插入
    ostream &operator<<(ostream &out, string &str);

    //重载流提取
    istream &operator>>(istream &in, string &str);

    void test_string1();

    void test_string2();

    void test_string3();

    void test_string4();

    void test_string5();

    void test_string6();

    void test_string7();

    void test_string8();

    void test_string9();

    void test_string10();

    void test_string11();

}

