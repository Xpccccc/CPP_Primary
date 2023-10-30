#include <iostream>

using namespace std;

typedef int DataType;

class Stack {
public:
    Stack(size_t capacity = 3) {
        _array = (DataType *) malloc(sizeof(DataType) * capacity);
        if (NULL == _array) {
            perror("malloc申请空间失败!!!");
            return;
        }
        _capacity = capacity;
        _size = 0;
    }

    void Push(DataType data) {
        // CheckCapacity();
        _array[_size] = data;
        _size++;
    }

    // 其他方法...
    ~Stack() {
        if (_array) {
            free(_array);
            _array = NULL;
            _capacity = 0;
            _size = 0;
        }
    }

private:
    DataType *_array;
    int _capacity;
    int _size;
};

void TestStack() {
    Stack s;
    s.Push(1);
    s.Push(2);
}

// 栈的析构
int main(){
    TestStack();
    return 0;
}