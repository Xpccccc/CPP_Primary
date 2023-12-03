#include <iostream>

using namespace std;

//class Date {
//public:
//
//    void operator++() {
//        (this->x)++;
////        (this->y)++;//y是const成员变量，不能修改
//
//    }
//
//private:
//    int x; // 非const变量
//    const int y = 1; // const变量
//};
//
//int main() {
//    Date d1;
//
//    return 0;
//}


//class Date {
//public:
//
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    bool operator++() const{
//        //(*this)._year++;//const
//    }
//
//private:
//    int _year; // 非const变量
//    int _month;
//    int _day;
//    const int y = 1; // const变量
//};

//int main() {
//    const Date d1(2022, 1, 1);
//    const Date d2(2022, 1, 2);
//    int ret = d1 == d2;
//    cout << ret << endl;
//
//    return 0;
//}

//class Date {
//public:
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    void Print() {
//        cout << "Print()" << endl;
//        cout << "year:" << _year << endl;
//        cout << "month:" << _month << endl;
//        cout << "day:" << _day << endl << endl;
//    }
//
//    void Print() const {
//        cout << "Print()const" << endl;
//        cout << "year:" << _year << endl;
//        cout << "month:" << _month << endl;
//        cout << "day:" << _day << endl << endl;
//    }
//
//private:
//    int _year; // 年
//    int _month; // 月
//    int _day; // 日
//};
//
//void Test() {
//    Date d1(2022, 1, 13);
//    d1.Print();//Print()
//    const Date d2(2022, 1, 13);//Printf()const
//    d2.Print();
//}
//
//int main(){
//    Test();
//    return 0;
//}

//权限只能缩小或者平移，不能变大
//class Date {
//public:
//
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    bool operator==(const Date &d) {
//        return _year == d._year && _month == d._month && _day == d._day;
//    }
//
//private:
//    int _year; // 非const变量
//    int _month;
//    int _day;
//    const int y = 1; // const变量
//};
//
//int main() {
//    const Date d1(2022, 1, 1);
//    const Date d2(2022, 1, 2);
//    //int ret = d1 == d2;//报错，这里const对象传给this，this的类型是Date* const而不是 const Date* ，因为*this才是对象，this是指针
//    //cout << ret << endl;
//
//    return 0;
//}

//const成员函数内可以调用其它的非const成员函数
//class Date {
//public:
//
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    bool operator++() {
//        (*this)._year++;
//    }
//
//    int jj(int x){
//        return ++x;
//    }
//    bool operator==(const Date &d) const{
//        Date a(11,1,1);
//        ++a;
//        int b = 1;
//        //int c= jj(this,b);//报错，jj不是const成员函数
//        return _year == d._year && _month == d._month && _day == d._day;
//    }
//
//private:
//    int _year; // 非const变量
//    int _month;
//    int _day;
//    const int y = 1; // const变量
//};
//
//int main() {
//    Date d1(2022, 1, 1);
//    Date d2(2022, 1, 2);
//    int ret = d1 == d2;
//    cout << ret << endl;
//
//    return 0;
//}


//非const成员函数内可以调用其它的const成员函数
//class Date {
//public:
//
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    bool operator==(const Date &d) const {
//        return _year == d._year && _month == d._month && _day == d._day;
//    }
//
//    bool operator++() {
//        Date aa(2022, 1, 1);
//        *this == aa;
//        (*this)._year++;
//    }
//
//private:
//    int _year; // 非const变量
//    int _month;
//    int _day;
//    const int y = 1; // const变量
//};


//取地址及const取地址操作符重载
//class Date {
//public :
//
//    Date() : _year(1), _month(1), _day(1) {
//        _year = 2;
//        _month = 3;
//        _day = 4;
//    }
//
//    Date *operator&() {
//        cout << "operator&()" << endl;
//        return this;
//
//    }
//
//    const Date *operator&() const {
//        cout << "operator&() const" << endl;
//        return this;
//    }
//
//private :
//    int _year; // 年
//    int _month; // 月
//    int _day; // 日
//};
//
//int main() {
//    Date d1, d2;
//    const Date d3;
//    cout << &d1 << endl << &d2 << endl << &d3 << endl;
//    return 0;
//}

//初始化列表
//class Date {
//public :
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//
//private :
//    int _year; // 年
//    int _month; // 月
//    int _day; // 日
//};
//
//int main() {
//    Date d1(2023,11,3);
//    return 0;
//}

//class Date {
//public :
//    Date(int year, int month, int day) : _year(year), _month(month), _day(day) {
//    }
//
//
//private :
//    int _year; // 年
//    int _month; // 月
//    int _day; // 日
//};
//
//int main() {
//    Date d1(2023, 11, 3);
//    return 0;
//}


//class Time {
//public:
//    Time(int hour, int minute, int second) {
//        cout << "Time(int ,int , int )" << endl;
//    }
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//class Date {
//public :
//    Date(int year, int month, int day) : _year(year), _month(month), _day(day), _n(year), _x(1), _t(1, 1, 1) {
//    }
//
//
//private :
//    int _year; // 年
//    int _month; // 月
//    int _day; // 日
//    int &_n;//引用
//    const int _x;//const成员变量
//    Time _t;//没有默认构造函数的自定义类型成员变量
//};
//
//int main() {
//    Date d1(2023, 11, 3);
//    return 0;
//}

//class Time {
//public:
//    Time(int hour = 0)
//            : _hour(hour) {
//        cout << "Time()" << endl;
//    }
//
//private:
//    int _hour;
//};
//
//class Date {
//public:
//    Date(int day) {
//        cout << "Date()" << endl;
//    }
//
//private:
//    int _day;
//    Time _t;
//};
//
//int main() {
//    Date d(1);
//}


//class A {
//public:
//    A(int a)
//            : _a1(a), _a2(_a1) {}
//
//    void Print() {
//        cout << _a1 << " " << _a2 << endl;//a2先声明，但是并没有初始化，
//    }
//
//private:
//    int _a2;
//    int _a1;
//};
//
//int main() {
//    A aa(1);//1 随机值
//    aa.Print();
//}


//构造函数隐式类型转换
//class Date {
//public:
//
////    Date(int year)
////            : _year(year) {}
//
//    Date(int year, int month = 1, int day = 1)
//            : _year(year), _month(month), _day(day) {}
//
//    Date &operator=(const Date &d) {
//        if (this != &d) {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    Date d1(11);
//    // 用一个整型变量给日期类型对象赋值
//    // 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
//    d1 = 2023;//2023先转换为Date类型，然后用2023构造一个无名对象，相当于 d1 =  d2(2023)
//    d1 = (2021,2,1); //逗号表达式的值是最后一个数值（这里是1） 相当于  d1 =  d3(1)
//    d1 = {2021, 2, 1};//相当于 d1 = d4(2021, 2, 1)
//    return 0;
//}

//构造函数隐式类型转换
//class Date {
//public:
//
////    Date(int year)
////            : _year(year) {}
//
//    //这里验证构造函数的隐式类型转换功能  ---  需要隐式类型转换的变量类型必须和构造函数的参数类型匹配
//    Date(int *n) {}
//
//    Date(int year, int month = 1, int day = 1)
//            : _year(year), _month(month), _day(day) {}
//
//    Date &operator=(const Date &d) {
//        if (this != &d) {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    int *p = nullptr;
//    Date d1(2023, 11, 6);
//    d1 = p;//这里p进行隐式类型转换了，先创建一个临时对象，再将临时对象赋值给d1
//
//    int** num = nullptr;
//    //d1 = num;//报错，这里num和构造函数的参数类型不匹配
//    Date d2 = {2023, 11, 6};
//    const Date &d3 = {2023, 11, 6};
//
//    return 0;
//}


//explicit关键字使用
//class Date {
//public:
//
//    // 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
//    // explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
////  explicit  Date(int year)
////            : _year(year) {}
//
//
//    // 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具有类型转换作用
//    // explicit修饰构造函数，禁止类型转换
//    explicit Date(int year, int month = 1, int day = 1)
//            : _year(year), _month(month), _day(day) {}
//
//    Date &operator=(const Date &d) {
//        if (this != &d) {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    Date d1(11);
//    // 用一个整形变量给日期类型对象赋值
//    // 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
//    //d1 = 2023;//报错，有explicit关键字隐式转换不了
//    //d1 = {2023, 11, 6};//同样报错
//    // 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了构造函数类型转换的作用
//    return 0;
//}


//static成员
//class Date {
//public:
//
////    Date(int year)
////            : _year(year) {}
//
//    Date(int year, int month = 1, int day = 1)
//            : _year(year), _month(month), _day(day) {}
//
//
//    //static成员函数没有this指针
//    static void Show(int n) {
//        cout << n << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//    static int n;//声明
//};
//
//int Date::n = 1;//定义
//
//int main() {
//    Date::Show(2);
//    return 0;
//}

//面试题：实现一个类，计算程序中创建出了多少个类对象。
//class A {
//public:
//    A() { ++_scount; }
//
//    A(const A &t) { ++_scount; }
//
//    ~A() { --_scount; }
//
//    int Sum (){
//        GetACount();
//        return 0;
//    }
//
//    static int GetACount() {
//        return _scount;
//    }
//
//private:
//    static int _scount;
//};
//
//int A::_scount = 0;
//
//int main() {
//    cout << A::GetACount() << endl;
//    A a1, a2;
//    A a3(a1);//拷贝构造函数
//    cout << A::GetACount() << endl;
//}

//友元函数
//class Date {
//    friend ostream &operator<<(ostream &_cout, const Date &d);
//
//    friend istream &operator>>(istream &_cin, Date &d);
//
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//            : _year(year), _month(month), _day(day) {}
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//ostream &operator<<(ostream &_cout, const Date &d) {
//    _cout << d._year << "-" << d._month << "-" << d._day;
//    return _cout;
//}
//
//istream &operator>>(istream &_cin, Date &d) {
//    _cin >> d._year;
//    _cin >> d._month;
//    _cin >> d._day;
//    return _cin;
//}
//
//int main() {
//    Date d;
//    cin >> d;
//    cout << d << endl;
//    return 0;
//}

//友元类
//class Time {
//    friend class Date;  // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//    Time(int hour = 0, int minute = 0, int second = 0)
//            : _hour(hour), _minute(minute), _second(second) {}
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//
//};
//
//class Date {
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//            : _year(year), _month(month), _day(day) {}
//
//    void SetTimeOfDate(int hour, int minute, int second) {
//        // 直接访问时间类私有的成员变量
//        _t._hour = hour;
//        _t._minute = minute;
//        _t._second = second;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//    Time _t;
//};


//内部类
//class A {
//public:
//    class B // B天生就是A的友元
//    {
//    public:
//        class C {
//        public:
//            void fun_c() {}
//
//            class D {//内部类可以嵌套
//            public:
//                void fun_d() {
//                    cout << "A::B::C::D" << endl;
//                };
//            private:
//                int _a;
//                int _b;
//            };
//
//        private:
//            int _x;
//            int _y;
//        };
//
//        void foo(const A &a) {
//            cout << k << endl;//OK
//            cout << a._h << endl;//OK
//        }
//
//    private:
//        int _mm;
//        int _nn;
//    };
//
//private:
//    static int k;
//    int _h;
//
//    class E {
//    public:
//        void fun_e() {}
//
//    private:
//        int _aa;
//        int _bb;
//    };
//};
//
//int A::k = 1;
//
//int main() {
//    A::B b;
//    b.foo(A());
//    A::B::C::D abcd;
//    abcd.fun_d();
//    cout << sizeof(A) << endl;
//    return 0;
//}

//匿名对象
//class A {
//public:
//    A(int a = 0)
//            : _a(a) {
//        cout << "A(int a)" << "_a = " <<_a << endl;
//    }
//
//    ~A() {
//        cout << "~A()" << endl;
//    }
//
//private:
//    int _a;
//};
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        //...
//        return n;
//    }
//};
//
//int main() {
//    A aa1;
//
//    //A aa1();// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
//    // 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
//    // 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
//    A();//这里就是匿名对象，匿名对象的作用域就在这一行，出了这一行就销毁了
//    A(2);//匿名对象，参数是2
//    A aa2(2);
//
//    // 匿名对象在这样场景下就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
//    Solution().Sum_Solution(10);
//    return 0;
//}


//class Date {
//public:
//    //构造函数
//    Date(int year, int month = 1, int day = 1) : _year(year), _month(month), _day(day) {
//        cout << "Date(int year, int month, int day) " << endl;
//    }
//
//    //拷贝构造函数
//    Date(Date &d) {
//        cout << "Date(Date &d)" << endl;
//    }
//
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//Date func1(Date d) {
//    Date tmp = d;
//    return tmp;
//}
//
//void func2() {
//    Date d1(1, 2, 3);
//    //构造 + 构造 --> 构造
//    Date d2 = d1;
//    Date d3 = d2;
//}
//
//int main() {
////    Date d1(1999, 11, 14);
////    Date d2(2020,11,14);
//
//    //同一个表达式中 构造 + 拷贝构造 --> 构造
//    Date d3 = 1;
//    //同一个表达式中 拷贝构造 + 拷贝构造 --> 拷贝构造
//    Date d4 = func1(d3);
//    func2();
//}


//int globalVar = 1;
//static int staticGlobalVar = 1;
//
//int main() {
//    static int staticVar = 1;
//    int localVar = 1;
//    int num1[10] = {1, 2, 3, 4};
//    char char2[] = "abcd";
//    const char *pChar3 = "abcd";
//    int *ptr1 = (int *) malloc(sizeof(int) * 4);
//    int *ptr2 = (int *) calloc(4, sizeof(int));
//    int *ptr3 = (int *) realloc(ptr2, sizeof(int) * 4);
//    free(ptr1);
//    free(ptr3);
//    return 0;
//}
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


//int main() {
//    int *p1 = (int *) malloc(sizeof(int));
//    free(p1);
//// 1.malloc/calloc/realloc的区别是什么？
//    int *p2 = (int *) calloc(4, sizeof(int));
//    int *p3 = (int *) realloc(p2, sizeof(int) * 10);
//// 这里需要free(p2)吗？
//    free(p3);
//    return 0;
//}


//int main() {
//    // 动态申请一个int类型的空间
//    int *ptr4 = new int;
//
//    // 动态申请一个int类型的空间并初始化为10
//    int *ptr5 = new int(10);
//
//    cout << *ptr5 << endl;
//    // 动态申请10个int类型的空间
//    int *ptr6 = new int[3];
//    // 动态申请10个int类型的空间并初始化前3个
//    int *ptr7 = new int[3]{1, 2, 3};
//    cout << ptr7[0] << ptr7[1] << ptr7[2] << ptr7[3];
//
//    delete ptr4;
//    delete ptr5;
//    delete[] ptr6;
//    delete[] ptr7;
//}


//class Date {
//public:
//    Date() : _year(1), _month(1), _day(1) {
//        cout << "Date()" << endl;
//    }
//
//    Date(int year, int month, int day) : _year(1), _month(1), _day(1) {
//        _year = year;
//        _month = month;
//        _day = day;
//        cout << "Date()" << endl;
//    }
//
//    ~Date() {
//        cout << "~Date()" << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main() {
//    Date *ptr1 = new Date();
//    Date *ptr2 = new Date(2, 2, 2);
//
//    Date *ptr3 = new Date[10]{{1, 2, 2}};
//
//    int a(1);
//    free(ptr1);
//    delete ptr2;
//    delete[] ptr3;
//    return 0;
//}


//class Date {
//public:
//    Date() : _year(1), _month(1), _day(1) {
//        cout << "Date()" << endl;
//    }
//
//    Date(int year, int month, int day) : _year(1), _month(1), _day(1) {
//        _year = year;
//        _month = month;
//        _day = day;
//        cout << "Date()" << endl;
//    }
//
//    ~Date() {
//        cout << "~Date()" << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main() {
//    Date *ptr1 = new Date();
//    Date *ptr2 = new Date(2, 2, 2);
//
//    //operator new -- 不调用构造函数 和 malloc 基本一样
//    Date *ptr6 = (Date *) operator new(sizeof(Date));
//
//    Date *ptr3 = new Date[10]{{1, 2, 2}};
//
//    int a(1);
//    free(ptr1);
//    delete ptr2;
//    delete[] ptr3;
//    operator delete(ptr6);
//    ptr6 = nullptr;
//    return 0;
//}


//class Date {
//public:
//    Date() : _year(1), _month(1), _day(1) {
//        cout << "Date()" << endl;
//    }
//
//    Date(int year, int month, int day) : _year(1), _month(1), _day(1) {
////        _a = new int[10];
//        _year = year;
//        _month = month;
//        _day = day;
//        cout << "Date()" << endl;
//    }
//
////    ~Date() {
////        cout << "~Date()" << endl;
////    }
//
//private:
////    int* _a;
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main() {
//    Date *ptr1 = new Date;
//    delete ptr1;
//
//    Date *ptr2 = new Date[10];
//    // 这里如果不写析构函数(默认成员变量没有开辟空间，如果开辟了空间，必须调用析构函数释放空间，不然会内存泄露)的话就不报错
//    // 因为成员变量都是内置类型没有开空间，不需要调用析构函数，也就不需要在前面添加4字节存个数
//    delete ptr2;
//    return 0;
//}

//定位new
//class Date {
//public:
//    Date() : _year(1), _month(1), _day(1) {
//        cout << "Date()" << endl;
//    }
//
//    Date(int year, int month, int day) : _year(1), _month(1), _day(1) {
//        _year = year;
//        _month = month;
//        _day = day;
//        cout << "Date()" << endl;
//    }
//
//    ~Date() {
//        cout << "~Date()" << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main() {
//    Date *p = (Date *) operator new(sizeof(Date));
//    // 不能显式调用构造函数
//    // p->Date();
//    // 定位new可以显式调用构造函数
//    new(p)Date(1, 1, 1);
//    p->~Date();
//
//    return 0;
//}


//泛型编程
//void Swap(int &left, int &right) {
//    int temp = left;
//    left = right;
//    right = temp;
//}
//
//void Swap(double &left, double &right) {
//    double temp = left;
//    left = right;
//    right = temp;
//}
//
//void Swap(char &left, char &right) {
//    char temp = left;
//    left = right;
//    right = temp;
//}
//
////......
//int main() {
//    int a = 1, b = 2;
//    double c = 1.1, d = 2.2;
//    Swap(a, b);
//    Swap(c, d);
//    return 0;
//}

//单参数函数模版
//template<typename T>
//
//void Swap(T &a, T &b) {
//    T tmp = a;
//    a = b;
//    b = tmp;
//}
//
//int main() {
//    int a = 1, b = 2;
//    Swap(a, b);
//
//    double c = 1.1, d = 2.2;
//    Swap(c, d);
//
//    char e = 1, f = 2;
//    Swap(e, f);
//
//    return 0;
//}

//多参数函数模版
//template<typename T1, class T2>
//
//void Swap(T1 &a, T2 &b) {
//    T1 tmp = a;
//    a = b;
//    b = tmp;
//}
//
//int main() {
//    int a = 1, b = 2;
//    double c = 1.1, d = 2.2;
//    Swap(a, b);
//    Swap(c, d);
//    Swap(a, c);
//    return 0;
//}

//template<class T>
//
//T Add(const T &left, const T &right) {
//    return left + right;
//}
//
//int main() {
//    int a1 = 10, a2 = 20;
//    double d1 = 10.0, d2 = 20.0;
//    Add(a1, a2);//推导出a1，a2是int类型
//    Add(d1, d2);//推导出d1，d2是double类型
//
//    /*
//    该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//    通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
//    编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//    注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//    Add(a1, d1);
//    */
//
//    // 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//    //1. 用户自己来强制转化
//    int a = 1;
//    double d = 2.1;
//    Add(a, (int) d);
//
//    //2. 使用显式实例化
//    int b = 1;
//    double c = 2.1;
//    Add<int>(b, c);//这里c就被强转化为int类型
//    return 0;
//}


//// 专门处理int的加法函数
//int Add(int left, int right) {
//    return left + right;
//}
//
//// 通用加法函数
//template<class T>
//T Add(T left, T right) {
//    return left + right;
//}
//
//int main() {
//    Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//    Add<int>(1, 2); // 调用编译器特化的Add版本
//    return 0;
//}

//// 专门处理int的加法函数
//int Add(int left, int right) {
//    return left + right;
//}
//
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right) {
//    return left + right;
//}
//
//int main() {
//    Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//    Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//    return 0;
//}

//类模版
// 动态顺序表
// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具
//template<class T>
//class Vector {
//public :
//    Vector(size_t capacity = 10)
//            : _pData(new T[capacity]), _size(0), _capacity(capacity) {}
//
//    // 使用析构函数演示：在类中声明，在类外定义。
//    ~Vector();
//
//    void PushBack(const T &data);
//
//    void PopBack();
//    // ...
//
//    size_t Size() { return _size; }
//
//    T &operator[](size_t pos) {
//        assert(pos < _size);
//        return _pData[pos];
//    }
//
//private:
//    T *_pData;
//    size_t _size;
//    size_t _capacity;
//};
//
//// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
//template<class T>
//Vector<T>::~Vector() {
//    if (_pData)
//        delete[] _pData;
//    _size = _capacity = 0;
//}
//
//class Date {
//public:
//    Date() : _year(1), _month(1), _day(1) {
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    Vector<int> it;
//    Vector<Date> dt;
//    return 0;
//}


//string类
//string类对象的常见构造
//int main() {
//    //构造函数/拷贝构造函数
//    string s1;
//    cout << s1 << endl;
//
//    string s2("hello");
//    cout << s2 << endl;
//
//    string s3(s2);
//    cout << s3 << endl;
//
//    string s4(s3, 2, 10);
//    cout << s4 << endl;
//
//    string s5("world", 2);
//    cout << s5 << endl;
//
//    return 0;
//}

//string类对象的容量操作
//int main() {
//    string s1("hello world a");
//
//    cout << s1.capacity() << endl;//返回当前已经分配给字符串的存储空间大小，单位是字节
//
//    cout << s1.size() << endl;//返回字符串有效字符长度
//    cout << s1.length() << endl;//返回字符串有效字符长度
//    cout << s1.max_size() << endl;//返回字符串可以达到的最大字符长度
//
//    s1.resize(25, 'x');//将有效字符的个数该成n个，多出的空间用字符c填充（如果有参数字符c）
//    cout << s1.size() << endl;
//    cout << s1.capacity() << endl;
//
//    s1.reserve(33);//要求字符串的容量调整为计划好的容量（参数为n），如果n小于之前的容量，则不调整，大于则调整为n（看编译器，有些编译器可能大于n）
//    cout << s1 << endl;
//    cout << s1.capacity() << endl;
//
//    s1.clear();//清空字符串的内容，使其变成一个空字符串
//    cout << s1.empty() << endl;//判断字符串是不是空
//
//    return 0;
//}













//int main(int argc, char *argv[]) {
//    string a = "hello world";
//    string b = a;
//    if (a.c_str() == b.c_str()) {
//        cout << "true" << endl;
//    } else cout << "false" << endl;
//    string c = b;
//    c = "";
//    if (a.c_str() == b.c_str()) {
//        cout << "true" << endl;
//    } else cout << "false" << endl;
//    a = "";
//    if (a.c_str() == b.c_str()) {
//        cout << "true" << endl;
//    } else cout << "false" << endl;
//    return 0;
//}

//int main(int argc, char *argv[]) {
//    string strText = "How are you?";
//    string strSeparator = " ";
//    string strResult;
//    int size_pos = 0;
//    int size_prev_pos = 0;
//    while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos) {
//        strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//        cout << strResult << " ";
//        size_prev_pos = ++size_pos;
//    }
//    if (size_prev_pos != strText.size()) {
//        strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//        cout << strResult << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//string类对象的访问及遍历操作
//int main() {
//    const string str1("hello ynu");
//    string str2("hello ynu");
//
////    str1[1] = '1';//常量string对象，这里调用的是const char& operator[] (size_t pos) const;
//    str2[1] = 'n';
//    str2.at(2) = 'y';
//
//    char ch1 = str2.back();
//    char ch2 = str2.front();
//
//    string::iterator it2 = str2.begin();
//    while (it2 != str2.end()) {
//        cout << *it2;
//        fflush(stdout);//将缓冲区数据刷新到终端
//        it2++;
//    }
//    cout << endl;
//
//    //const迭代器
//    string::const_iterator it1 = str1.begin();
//    while (it1 != str1.end()) {
//        cout << *it1;
//        it1++;
//    }
//    cout << endl;
//
//    //反向迭代器
//    string::reverse_iterator it3 = str2.rbegin();
//    while (it3 != str2.rend()) {
//        cout << *it3;
//        it3++;
//    }
//    cout << endl;
//
//    //专属/const迭代器
//    string::const_iterator it = str1.cbegin();
//    while (it != str1.end()) {
//        cout << *it;
//        it++;
//    }
//    cout << endl;
//
//    //范围for
//    for (auto e: str2) {
//        cout << e;
//    }
//    cout << endl;
//    return 0;
//}

//string类对象的修改操作

//int main() {
//
//    string s1("hello world");
//    string s2("no no no");
//
//    //operator+=
//    s2 += "hh";
//    s2 += 'x';
//    s2 += s1;
//
//    //append
//    s1.append(1, 'x');
//    s1.append("hh");
//    s1.append(s2);
//
//    //push_back
//    s2.push_back('x');
//
//    //insert
//    s1.insert(0, "xx");
//    s1.insert(0, 2, 'x');
//
//
//    //erase
//    s1.erase(0, 4);
//
//    //replace
//    s1.replace(0, 4, "x");
//
//    //swap
//    s1.swap(s2);
//
//    //c_str
//    const char *str = s1.c_str();
//
//    //data
//    const char *str1 = s1.data();
//
//    string s3("hello world");
//
//    //copy
//    char buffer[20] = {0};
//    size_t length = s3.copy(buffer, 8, 0);
//    buffer[length] = '\0';
//    cout << buffer << endl;
//
//    //find
//    size_t found1 = s3.find('d', 3);
//    cout << found1 << endl;
//
//    size_t found2 = s3.find('f');
//    //测试是不是用int表示的-1
//    int test = found2;
//    cout << found2 << endl;
//    cout << test << endl;
//
//    //rfind
//    size_t found3 = s3.rfind("ll", 5);
//    cout << found3 << endl;
//
//    string s4("hello gun qnd world haha no --skas wcl cb ");
//
//    //find_first_of
//    size_t found4 = s4.find_first_of("gunwcqnd", 0);
//
//    while (found4 != std::string::npos) {
//        s4[found4] = '*';
//        found4 = s4.find_first_of("gunwcqnd", found4 + 1);
//    }
//    cout << s4 << endl;
//
//    //substr
//    string sub_str = s4.substr(0, 9);
//    cout << sub_str << endl;
//
//    return 0;
//}

//string类非成员函数
//int main() {
//
//    //operator+
//    string s1("hello");
//    string s2("world");
//
//    string s3 = s1 + s2;
//    cout << s3 << endl;
//    string s4 = s1 + 'x';
//    cout << s4 << endl;
//
//    //operator==
//    bool b = s1 == s2;
//    cout << b << endl;
//
//    //swap
//    cout << s1 << endl;
//    cout << s2 << endl;
//    swap(s1, s2);
//    cout << s1 << endl;
//    cout << s2 << endl;
//
//    //operator>>
//    cin >> s1;
//    cout << s1 << endl;
//
//    //operator<<
//    cout << s2 << endl;
//
//    string s5("hello ynu");
//    //getline
//    getline(cin, s5);
//    cout << s5 << endl;
//
//    return 0;
//}
