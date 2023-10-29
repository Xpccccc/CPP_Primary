#include <iostream>
#include "Stack.h"

//类的声明和定义分离
int main() {
    Stack s;
    s.Init(10);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    cout << s.Top() << endl;
    s.Destroy();
    return 0;
}
