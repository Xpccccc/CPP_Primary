//
// Created by 徐鹏 on 2023/10/29.
//

#ifndef DEMO_03_STACK_H
#define DEMO_03_STACK_H

#endif //DEMO_03_STACK_H

#include <iostream>

using namespace std;
typedef int DataType;

//Stack.h文件
class Stack {
public:
    void Init(size_t capacity);

    void Push(const DataType &data);

    DataType Top();

    void Destroy();

    DataType *_array;
    size_t _capacity;
    size_t _size;
};
