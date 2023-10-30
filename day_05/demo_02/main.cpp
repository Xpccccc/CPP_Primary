#include <iostream>

using namespace std;

// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
typedef int DataType;

class Stack {
public:
    Stack(size_t capacity = 10) {
        _array = (DataType *) malloc(capacity * sizeof(DataType));
        if (nullptr == _array) {
            perror("malloc申请空间失败");
            return;
        }
        _size = 0;
        _capacity = capacity;
    }

//    //  改良
//    Stack (const Stack& st){
//        this->_array = (DataType *) malloc(st._capacity * sizeof(DataType));
//        if (nullptr == this->_array) {
//            perror("malloc申请空间失败");
//            return;
//        }
//        this->_size = st._size;
//        this->_capacity = st._capacity;
//    }

    void Push(const DataType &data) {
        // CheckCapacity();
        _array[_size] = data;
        _size++;
    }

    ~Stack() {
        cout << "~Stack()" << endl;
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

//拷贝构造函数的深拷贝
//类里面存在开辟空间的变量则需要采用深拷贝，否则在对象拷贝后，析构两次会出问题
int main() {
    Stack s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Push(4);
    Stack s2(s1);
    return 0;
}

