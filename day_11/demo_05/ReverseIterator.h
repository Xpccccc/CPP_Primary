//
// Created by 徐鹏 on 2024/3/11.
//

#ifndef DEMO_05_REVERSEITERATOR_H
#define DEMO_05_REVERSEITERATOR_H

#endif //DEMO_05_REVERSEITERATOR_H


template<class Iterator, class Ref, class Ptr>
struct ReverseIterator {
    typedef ReverseIterator<Iterator, Ref, Ptr> self;

    ReverseIterator(Iterator it) : _it(it) {

    }


    // 这里我们采用和正向迭代器对称的结构
    Iterator _it;

    Ref operator*() {
        Iterator tmp = _it;// 不能改变_it的位置，用tmp来指向_it的位置，来改变tmp的位置
        --tmp;
        return *tmp;
    }

    Ptr operator->() {
        return &(operator*());
    }

    self &operator++() {
        --_it;
        return *this;
    }

    self operator++(int) {
        self tmp(*this);
        --_it;
        return tmp;
    }

    self &operator--() {
        ++_it;
        return *this;
    }

    self operator--(int) {
        self tmp(*this);
        ++_it;
        return tmp;
    }

    bool operator!=(const self &s) {
        return _it != s._it;
    }

    bool operator==(const self &s) {
        return _it == s._it;
    }
};
