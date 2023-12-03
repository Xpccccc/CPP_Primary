#include <iostream>

using namespace std;

//内部类
class A {
public:
    class B // B天生就是A的友元
    {
    public:
        class C {
        public:
            void fun_c() {}

            class D {//内部类可以嵌套
            public:
                void fun_d() {
                    cout << "A::B::C::D" << endl;
                };
            private:
                int _a;
                int _b;
            };

        private:
            int _x;
            int _y;
        };

        void foo(const A &a) {
            cout << k << endl;//OK
            cout << a._h << endl;//OK
        }

    private:
        int _mm;
        int _nn;
    };

private:
    static int k;
    int _h;

    class E {
    public:
        void fun_e() {}

    private:
        int _aa;
        int _bb;
    };
};

int A::k = 1;

int main() {
    A::B b;
    b.foo(A());
    A::B::C::D abcd;
    abcd.fun_d();
    cout << sizeof(A) << endl;
    return 0;
}