//
// Created by 徐鹏 on 2023/10/11.
//

#ifndef DEMO_01_STACK_H
#define DEMO_01_STACK_H


#endif //DEMO_01_STACK_H

#include <stdio.h>
#include <stdlib.h>

namespace xp {
    typedef struct Stack {
        int *data;
        int size;
        int capacity;
    } ST;

    void StackInit(ST *ps, int n = 4);

    void StackPush(ST *ps, int x);
}


