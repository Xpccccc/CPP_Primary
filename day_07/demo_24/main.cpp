#include <iostream>

using namespace std;

//malloc/calloc/realloc的区别

int main() {
    int *p1 = (int *) malloc(sizeof(int));
    free(p1);
    // 1.malloc/calloc/realloc的区别是什么？
    int *p2 = (int *) calloc(4, sizeof(int));
    int *p3 = (int *) realloc(p2, sizeof(int) * 10);
    // 这里需要free(p2)吗？
    free(p3);
    return 0;
}