#include <iostream>

using namespace std;

//泛型编程
void Swap(int &left, int &right) {
    int temp = left;
    left = right;
    right = temp;
}

void Swap(double &left, double &right) {
    double temp = left;
    left = right;
    right = temp;
}

void Swap(char &left, char &right) {
    char temp = left;
    left = right;
    right = temp;
}

//......
int main() {
    int a = 1, b = 2;
    double c = 1.1, d = 2.2;
    Swap(a, b);
    Swap(c, d);
    return 0;
}
