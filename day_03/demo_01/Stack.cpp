//
// Created by 徐鹏 on 2023/10/23.
//

//Stack.cpp文件
#include "Stack.h"

void Stack::Init(size_t capacity) {
    _array = (DataType *) malloc(sizeof(DataType) * capacity);
    if (nullptr == _array) {
        perror("malloc申请空间失败");
        return;
    }
    _capacity = capacity;
    _size = 0;
}

void Stack::Push(const DataType &data) {
    // 扩容
    _array[_size] = data;
    ++_size;
}

DataType Stack::Top() {
    return _array[_size - 1];
}

void Stack::Destroy() {
    if (_array) {
        free(_array);
        _array = nullptr;
        _capacity = 0;
        _size = 0;
    }
}
