//
// Created by 徐鹏 on 2023/10/11.
//

#include "Stack.h"

namespace xp {
    void StackInit(ST *ps, int n) {
//        ps->data = NULL;
        ps->data = (int *) malloc(sizeof(int) * n);
        ps->size = 0;
        ps->capacity = 0;
    }

    void StackPush(ST *ps, int x) {

    }
}
