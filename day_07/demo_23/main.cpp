#include <iostream>

using namespace std;

//C语言中动态内存管理方式：malloc/calloc/realloc/free

int globalVar = 1;
static int staticGlobalVar = 1;

int main() {
    static int staticVar = 1;
    int localVar = 1;
    int num1[10] = {1, 2, 3, 4};
    char char2[] = "abcd";
    const char *pChar3 = "abcd";
    int *ptr1 = (int *) malloc(sizeof(int) * 4);
    int *ptr2 = (int *) calloc(4, sizeof(int));
    int *ptr3 = (int *) realloc(ptr2, sizeof(int) * 4);
    free(ptr1);
    free(ptr3);
    return 0;
}
//1. 选择题：
// 选项: A.栈 B.堆 C.数据段(静态区) D.代码段(常量区)
// globalVar在哪里？____  staticGlobalVar在哪里？____
// staticVar在哪里？____  localVar在哪里？____
// num1 在哪里？____
//
// char2在哪里？____  *char2在哪里？___
// pChar3在哪里？____   *pChar3在哪里？____
// ptr1在哪里？____ *ptr1在哪里？____
//2. 填空题：
// sizeof(num1) = ____;
//sizeof(char2) = ____;  strlen(char2) = ____;
// sizeof(pChar3) = ____;   strlen(pChar3) = ____;
// sizeof(ptr1) = ____;
//3. sizeof 和 strlen 区别？
//