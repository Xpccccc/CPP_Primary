//
// Created by 徐鹏 on 2023/11/29.
//


#include "string.h"


namespace xp {
    string::string(const char *s) {
        _size = strlen(s);//这里还没有size()呢，size()得自己写
        _capacity = _size;
        _str = new char[_capacity + 1];//多开一个空间存\0
        strcpy(_str, s);
    }

    //拷贝构造函数 --   传统写法
//    string::string(const string &str) {
//        _size = str._size;
//        _capacity = str._capacity;
//        _str = new char[_capacity + 1];
//        strcpy(_str, str._str);
//    }

    //  现代写法
    string::string(const string &str) : _str(nullptr), _size(0),
                                        _capacity(0) {
        //这里得使用初始化列表或者在private里得成员变量进行缺省，防止交换后tmp指向随机值，调用析构就会出错
        string tmp(str._str);
        swap(tmp);
    }

    void string::swap(string &str) {
        std::swap(_str, str._str);
        std::swap(_size, str._size);
        std::swap(_capacity, str._capacity);
    }

    void string::reserve(size_t n) {
        if (n > _capacity) {
            //扩容
            char *new_str = new char[n + 1];
            strcpy(new_str, _str);
            delete[] _str;
            _str = new_str;
            _capacity = n;
        }
        //小于等于则不改变容量
    }

    void string::resize(size_t n) {
        if (n > _capacity) {
            //需要重新开辟空间
            reserve(n);
        } else {
            //缩小容量和有效字符
            _capacity = n;
            _size = n;
            _str[n] = '\0';
        }
    }

    char &string::operator[](size_t pos) {
        assert(pos < _size);
        return _str[pos];
    }

    const char &string::operator[](size_t pos) const {
        assert(pos < _size);
        return _str[pos];
    }

    char &string::at(size_t pos) {
//        assert(pos < _size);
//        抛异常
        return _str[pos];
    }

    const char &string::at(size_t pos) const {
//        assert(pos < _size);
//        抛异常
        return _str[pos];
    }

    void string::append(const string &str) {
        size_t total_size = _size + str._size;
        //如果新插入的字符串加上之前的字符串的长度大于容量，则需要扩容
        if (total_size > _capacity) {
            reserve(total_size);
        }
        //把字符加进来
        for (int i = 0; i < str._size; ++i) {
            _str[_size++] = str[i];
        }
        _str[_size] = '\0';
    }

    void string::append(const char *s) {
        size_t total_size = _size + strlen(s);
        //如果新插入的字符串加上之前的字符串的长度大于容量，则需要扩容
        if (total_size > _capacity) {
            reserve(total_size);
        }
        //把字符加进来
        strcpy(_str + _size, s);
        _size += strlen(s);
    }

    string &string::operator+=(const string &str) {
        append(str);
        return *this;
    }

    string &string::operator+=(const char *s) {
        string str(s);
        append(str);
        return *this;
    }

    string &string::operator+=(char c) {
        push_back(c);
        return *this;
    }

    void string::push_back(char c) {
        size_t total_size = _size + 1;
        //如果新插入的字符加上之前的字符串的长度大于容量，则需要扩容
        if (total_size > _capacity) {
            reserve(total_size);
        }
        //把字符加进来
        _str[_size++] = c;
        _str[_size] = '\0';
    }

    string &string::insert(size_t pos, const string &str) {
        assert(pos < _size);
//        size_t total_size = _size + str._size;
//        //如果新插入的字符串加上之前的字符串的长度大于容量，则需要扩容
//        if (total_size > _capacity) {
//            reserve(total_size);
//        }
//        int end = _size;
//        //pos后面数据先后移，每个元素后移str._size，这里end最后等于-1
//        while (end >= (int) pos) {
//            _str[end + str._size] = _str[end];
//            --end;
//        }
//
////        size_t end = total_size;
////        //pos后面数据先后移，每个元素后移str._size，这里end最后等于0
////        while (end > pos) {
////            //当end减去str._size的时候，也就是预留的给插入的长度小于str._size时候，说明pos后面的数据移动完成，直接退出就行
////            if (end - str._size < 0)
////                break;
////            _str[end] = _str[end - str._size];
////            --end;
////        }
//        //插入数据
//        strncpy(_str + pos, str._str, str._size);
//        _size = total_size;
        insert(pos, str.c_str());//复用
        return *this;
    }

    string &string::insert(size_t pos, const char *s) {
        assert(pos < _size);
        size_t total_size = _size + strlen(s);
        if (total_size > _capacity) {
            reserve(total_size);
        }
        size_t end = total_size;
        //pos后面数据先后移，每个元素后移str._size，这里是相当于元素后移，这里end最后等于0
        while (end > pos) {
            //当end减去strlen(str)的时候，也就是预留的给插入的长度小于strlen(str)时候，说明pos后面的数据移动完成，直接退出就行
            if (end - strlen(s) < 0)
                break;
            _str[end] = _str[end - strlen(s)];
            --end;
        }
        //插入数据
        strncpy(_str + pos, s, strlen(s));
        _size = total_size;
        return *this;
    }

    string &string::insert(size_t pos, size_t n, char c) {
        assert(pos < _size);
        size_t total_size = _size + n;
        if (total_size > _capacity) {
            reserve(total_size);
        }
        size_t end = total_size;
        //pos后面数据先后移，每个元素后移str._size，这里是相当于元素后移，这里end最后等于0
        while (end > pos) {
            if (end - n < 0)
                break;
            _str[end] = _str[end - n];
            --end;
        }
        //插入数据
        while (n--) {
            _str[pos++] = c;
        }
        _size = total_size;
        return *this;
    }

    string &string::erase(size_t pos, size_t len) {
        assert(pos < _size);
        if (len == std::string::npos || len + pos >= size()) {
            _str[pos] = '\0';//pos后面数据全部不要了
            _size = pos;
        } else {
            strcpy(_str + pos, _str + pos + len);
            _size -= len;
        }
        return *this;
    }


    size_t string::find(const string &str, size_t pos) const {
        assert(pos < _size);
        const char *ret = strstr(_str + pos, str._str);
        if (nullptr == ret) return std::string::npos;
        return ret - _str;
    }

    size_t string::find(const char *s, size_t pos) const {
        assert(pos < _size);
        const char *ret = strstr(_str + pos, s);
        if (nullptr == ret) return std::string::npos;
        return ret - _str;
    }

    size_t string::find(char c, size_t pos) const {
        assert(pos < _size);
        while (pos < _size) {
            if (_str[pos] == c) return pos;
            pos++;
        }
        //没找到
        return std::string::npos;
    }

    string string::substr(size_t pos, size_t len) const {
        assert(pos < _size);
        size_t end = pos + len;
        if (len == npos || end >= _size) {
            end = _size;
        }
        string str;
        str.reserve(end - pos);//开辟空间
        while (pos < end) {
            str += _str[pos++];
        }
        //把\0也带进去
        str._str[_size] = '\0';
        return str;
    }

    // 传统写法
//    string &string::operator=(const string &str) {
//        if (this != &str) {
//            reserve(str._capacity);
//            strcpy(_str, str._str);
//            _size = str._size;
//        }
//
//        return *this;
//    }

    //  现代写法
    string &string::operator=(string str) {
        //这里不会改变赋值的值，这里str只是临时拷贝
        swap(str);
        return *this;
    }

    string &string::operator=(const char *s) {
        reserve(strlen(s));
        strcpy(_str, s);
        _size = strlen(s);
        return *this;
    }

    string &string::operator=(char c) {
        reserve(1);
        _str[0] = c;
        _str[1] = '\0';
        _size = 1;
        return *this;
    }


    ostream &operator<<(ostream &out, string &str) {
        for (auto e: str) {
            out << e;
        }
        return out;
    }

    istream &operator>>(istream &in, string &str) {
        str.clear();
        char buffer[128];//缓冲一下
        char c = in.get();
        int i = 0;
        while (c != ' ' && c != '\n') {
            buffer[i++] = c;
            if (i == 127) {
                buffer[i] = '\0';
                str += buffer;
                i = 0;//重置
            }
            c = in.get();
        }
        //提前读到' ' 或者 '\n'
        if (i > 0) {
            buffer[i] = '\0';
            str += buffer;
        }
        return in;
    }

    string::~string() {
        delete[] _str;
        _str = nullptr;
        _capacity = 0;
        _size = 0;
    }

    void test_string1() {
        string s1;
        cout << s1.c_str() << endl;
        string s2("hello world");
        cout << s2.c_str() << endl;

        string s3(s2);
        cout << s3.c_str() << endl;
    }

    void test_string2() {
        string s1;
        string s2("hello world");

        cout << s2.capacity() << endl;
        s2.reserve(2);
        cout << s2.capacity() << endl;

        s2.resize(15);
        cout << s2.capacity() << endl;

        s2.resize(7);
        cout << s2.capacity() << endl;
        cout << s2.c_str() << endl;

    }

    void test_string3() {
        string s1("hello world");
        const string s2("nihao liangzai");

        string::iterator it1 = s1.begin();
        while (it1 != s1.end()) {
            cout << *it1 << " ";
            ++it1;
        }
        cout << endl;

        string::const_iterator it2 = s2.begin();
        while (it2 != s2.end()) {
            cout << *it2 << " ";
            ++it2;
        }
        cout << endl;
    }

    void test_string4() {
        string s1("hello world");
        const string s2("nihao liangzai");

//        s1.append(s2);
//        s1.append("hh");
//        s1 += s2;
//        s1 += "hh";
//        s1 += 'x';
        s1.push_back('v');

        cout << s1.c_str() << endl;
    }

    void test_string5() {
        string s1("hello world");
        const string s2("nihao liangzai");

//        s1.insert(0, s2);
//        s1.insert(2, "hh");
        s1.insert(11, 5, 'x');
        cout << s1.c_str() << endl;
    }

    void test_string6() {
        string s1("hello world");
        const string s2("nihao liangzai");
        s1.erase();
        cout << s1.c_str() << endl;
    }

    void test_string7() {
        string s1("hello world");
        string s2("nihao liangzai");
        cout << s1.c_str() << endl;
        cout << s2.c_str() << endl;
        s1.swap(s2);
        cout << s1.c_str() << endl;
        cout << s2.c_str() << endl;
    }

    void test_string8() {
        string s1("hello world");
        const string s2("wo");
        size_t pos1 = s1.find(s2);
        size_t pos2 = s1.find("d");
        size_t pos3 = s1.find("f");
        size_t pos4 = s1.find('o');

        cout << pos1 << endl;
        cout << pos2 << endl;
        cout << (int) pos3 << endl;
        cout << (int) pos4 << endl;
    }

    void test_string9() {
        string s1("hello world");
        string s2(s1.substr(5, 2));
        const string s3("nihao liangzai");
        string s4(s3.substr(2, 5));

        cout << s2.c_str() << endl;
        cout << s4.c_str() << endl;
    }

    void test_string10() {
        string s1("hello world");
        const string s2("nihao liangzai");

        cout << s1.c_str() << endl;
        s1 = s2;
        cout << s1.c_str() << endl;
        s1 = "woshixp";
        cout << s1.c_str() << endl;
        s1 = '1';
        cout << s1.c_str() << endl;
    }

    void test_string11() {
        string s;
        cin >> s;
        cout << s << endl;
    }

    void test_string12() {
        string s1("111");
        string s2(s1);
        cout << s1 << endl;
        cout << s2 << endl;

        string s3;
        s3 = s2;
        cout << s3 << endl;
    }

}




