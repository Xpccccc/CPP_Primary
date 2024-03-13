//
// Created by 徐鹏 on 2024/3/12.
//

#include "template.h"

template<class T>
T Add(const T &x, const T &y) {
    return x + y;
}

// 显式实例化
template
int Add(const int &x, const int &y);