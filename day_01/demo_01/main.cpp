#include <iostream>
#include "Stack.h"

using namespace std;

int y = 0;

namespace xp {
    int x = 1;

    namespace zl {
        int Add(int a, int b) {
            return a + b;
        }

        namespace xpzl {
            typedef struct Stack {
                int *data;
                int capacity;
                int size;
            } ST;
        }
    }

}


int main() {
    printf("%d\n", xp::x);
    xp::zl::Add(2, 3);
    xp::zl::xpzl::ST *st;
    printf("%d\n", y);
    cout << xp::zl::Add(1, 2) << endl;
    return 0;
}

//using namespace xp;

//int main() {
//    ST st1;
//    StackInit(&st1);
//    StackPush(&st1,1);
//    StackPush(&st1,2);
//    StackPush(&st1,3);
//    StackPush(&st1,4);
//
//    ST st2;
//    StackInit(&st2,10);
//    for (int i = 0; i < 10; ++i) {
//        StackPush(&st2, i);
//    }
//    cout << xpzl::a << " " << a << endl;
//    cout << "Hello, World!" << endl;
//    return 0;
//}




