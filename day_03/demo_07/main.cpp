#include <iostream>


//C语言实现栈和C++实现栈对比
using namespace std;

//C语言实现栈
//typedef int DataType;
//typedef struct Stack {
//    DataType *array;
//    int capacity;
//    int size;
//} Stack;
//
//void StackInit(Stack *ps) {
//    assert(ps);
//    ps->array = (DataType *) malloc(sizeof(DataType) * 3);
//    if (NULL == ps->array) {
//        assert(0);
//        return;
//    }
//    ps->capacity = 3;
//    ps->size = 0;
//}
//
//void StackDestroy(Stack *ps) {
//    assert(ps);
//    if (ps->array) {
//        free(ps->array);
//        ps->array = NULL;
//        ps->capacity = 0;
//        ps->size = 0;
//    }
//}
//
//void CheckCapacity(Stack *ps) {
//    if (ps->size == ps->capacity) {
//        int newcapacity = ps->capacity * 2;
//        DataType *temp = (DataType *) realloc(ps->array,
//                                              newcapacity * sizeof(DataType));
//        if (temp == NULL) {
//            perror("realloc申请空间失败!!!");
//            return;
//        }
//        ps->array = temp;
//        ps->capacity = newcapacity;
//    }
//}
//
//void StackPush(Stack *ps, DataType data) {
//    assert(ps);
//    CheckCapacity(ps);
//    ps->array[ps->size] = data;
//    ps->size++;
//}
//
//int StackEmpty(Stack *ps) {
//    assert(ps);
//    return 0 == ps->size;
//}
//
//void StackPop(Stack *ps) {
//    if (StackEmpty(ps))
//        return;
//    ps->size--;
//}
//
//DataType StackTop(Stack *ps) {
//    assert(!StackEmpty(ps));
//    return ps->array[ps->size - 1];
//}
//
//int StackSize(Stack *ps) {
//    assert(ps);
//    return ps->size;
//}
//
//int main() {
//    Stack s;
//    StackInit(&s);
//    StackPush(&s, 1);
//    StackPush(&s, 2);
//    StackPush(&s, 3);
//    StackPush(&s, 4);
//    printf("%d\n", StackTop(&s));
//    printf("%d\n", StackSize(&s));
//    StackPop(&s);
//    StackPop(&s);
//    printf("%d\n", StackTop(&s));
//    printf("%d\n", StackSize(&s));
//    StackDestroy(&s);
//    return 0;
//}


//C++实现栈
typedef int DataType;

class Stack {
public:
    void Init() {
        _array = (DataType *) malloc(sizeof(DataType) * 3);
        if (NULL == _array) {
            perror("malloc申请空间失败!!!");
            return;
        }
        _capacity = 3;
        _size = 0;
    }

    void Push(DataType data) {
        CheckCapacity();
        _array[_size] = data;
        _size++;
    }

    void Pop() {
        if (Empty())
            return;
        _size--;
    }

    DataType Top() { return _array[_size - 1]; }

    int Empty() { return 0 == _size; }

    int Size() { return _size; }

    void Destroy() {
        if (_array) {
            free(_array);
            _array = NULL;
            _capacity = 0;
            _size = 0;
        }
    }

private:
    void CheckCapacity() {
        if (_size == _capacity) {
            int newcapacity = _capacity * 2;
            DataType *temp = (DataType *) realloc(_array, newcapacity *
                                                          sizeof(DataType));
            if (temp == NULL) {
                perror("realloc申请空间失败!!!");
                return;
            }
            _array = temp;
            _capacity = newcapacity;
        }
    }

private:
    DataType *_array;
    int _capacity;
    int _size;
};

int main() {
    Stack s;
    s.Init();
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);

    printf("%d\n", s.Top());
    printf("%d\n", s.Size());
    s.Pop();
    s.Pop();
    printf("%d\n", s.Top());
    printf("%d\n", s.Size());
    s.Destroy();
    return 0;
}
