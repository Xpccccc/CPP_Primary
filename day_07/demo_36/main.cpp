#include <iostream>

using namespace std;

//类模版
// 动态顺序表
// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
template<class T>
class Vector {
public :
    Vector(size_t capacity = 10)
            : _pData(new T[capacity]), _size(0), _capacity(capacity) {}

    // 使用析构函数演示：在类中声明，在类外定义。
    ~Vector();

    void PushBack(const T &data);

    void PopBack();
    // ...

    size_t Size() { return _size; }

    T &operator[](size_t pos) {
        assert(pos < _size);
        return _pData[pos];
    }

private:
    T *_pData;
    size_t _size;
    size_t _capacity;
};

// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
template<class T>
Vector<T>::~Vector() {
    if (_pData)
        delete[] _pData;
    _size = _capacity = 0;
}

class Date {
public:
    Date() : _year(1), _month(1), _day(1) {
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    Vector<int> it;
    Vector<Date> dt;
    return 0;
}