#include <iostream>

using namespace std;

//匿名对象
class A {
public:
    A(int a = 0)
            : _a(a) {
        cout << "A(int a)" << "_a = " << _a << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }

private:
    int _a;
};

class Solution {
public:
    int Sum_Solution(int n) {
        //...
        return n;
    }
};

int main() {
    A aa1;

    //A aa1();// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
    // 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
    // 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
    A();//这里就是匿名对象，匿名对象的作用域就在这一行，出了这一行就销毁了
    A(2);//匿名对象，参数是2
    A aa2(2);

    // 匿名对象在这样场景下就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
    Solution().Sum_Solution(10);
    return 0;
}