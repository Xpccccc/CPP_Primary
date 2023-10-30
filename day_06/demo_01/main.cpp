#include <iostream>

using namespace std;


// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//
//class Stack1 {
//public:
//    Stack1(size_t capacity = 10) {
//        _array = (DataType *) malloc(capacity * sizeof(DataType));
//        if (nullptr == _array) {
//            perror("malloc申请空间失败");
//            return;
//        }
//        _size = 0;
//        _capacity = capacity;
//    }
//
//    void Push(const DataType &data) {
//        // CheckCapacity();
//        _array[_size] = data;
//        _size++;
//    }
//
//
//    ~Stack1() {
//        if (_array) {
//            free(_array);
//            _array = nullptr;
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//
//private:
//    DataType *_array;
//    size_t _size;
//    size_t _capacity;
//};
//
//int main() {
//    Stack1 s1;
//    s1.Push(1);
//    s1.Push(2);
//    s1.Push(3);
//    s1.Push(4);
//    Stack1 s2;
//    s2 = s1;
//    return 0;
//}

//解决办法   --- 栈的拷贝构造函数的深拷贝
typedef int DataType;

class Stack1 {
public:
    Stack1(size_t capacity = 10) {
        _array = (DataType *) malloc(capacity * sizeof(DataType));
        if (nullptr == _array) {
            perror("malloc申请空间失败");
            return;
        }
        _size = 0;
        _capacity = capacity;
    }

    Stack1& operator=(const Stack1 &st) {
        this->_array = (DataType *) malloc(st._capacity * sizeof(DataType));
        if (nullptr == this->_array) {
            perror("malloc申请空间失败");
            exit(-1);
        }
        this->_size = st._size;
        this->_capacity = st._capacity;
        return *this;
    }

    void Push(const DataType &data) {
        // CheckCapacity();
        _array[_size] = data;
        _size++;
    }


    ~Stack1() {
        if (_array) {
            free(_array);
            _array = nullptr;
            _capacity = 0;
            _size = 0;
        }
    }

private:
    DataType *_array;
    size_t _size;
    size_t _capacity;
};

int main() {
    Stack1 s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    Stack1 s2;
    s2 = s1;
    return 0;
}