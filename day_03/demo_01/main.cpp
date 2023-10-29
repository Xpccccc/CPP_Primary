#include <iostream>
//#include "Stack.h"

using namespace std;

//class Person {
//public:
//    void PrintPersonInfo();
//
//private:
//    char _name[20];
//    char _gender[3];
//    int _age;
//};
//
//// 这里需要指定PrintPersonInfo是属于Person这个类域
//void Person::PrintPersonInfo() {
//    cout << _name << " " << _gender << " " << _age << endl;
//}

//int main() {
//    Stack s;
//    s.Init(10);
//    s.Push(1);
//    s.Push(2);
//    s.Push(3);
//    cout << s.Top() << endl;
//    s.Destroy();
//    return 0;
//}

//class Person {
//public:
//    void showInfo();
//
//public:
//    int _age;
//    char *_name;
//    char *_sex;
//};
//
//void Person::showInfo() {
//    cout << this->_age << endl << _name << endl << _sex << endl;
//}
//
//void Test() {
//    //Person._age = 100;  // 编译失败：error C2059: 语法错误:“.”
//    Person man;//实例化一个对象，占用物理空间
//    man._age = 10;
//    man._name = "hh";
//    man._sex = "nan";
//    man.showInfo();
//}
//
//int main() {
//    Test();
//    return 0;
//}


//// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//    void f1() {}
//
//private:
//    int _a;
//};
//
//// 类中仅有成员函数
//class A2 {
//public:
//    void f2() {}
//};
//
//// 类中什么都没有---空类
//class A3 {
//};
//
//int main() {
//    cout << sizeof(A1) << endl << sizeof(A2) << endl << sizeof(A3) << endl;
//    return 0;
//}

////this指针
//class Date {
//public:
//    void Init(int year, int month, int day) { //void Init(const Date* this, int year, int month, int day)
//        _year = year;
//        _month = month;
//        _day = day;
//        //this->_year = year;
//        //this->_month = month;
//        //this->_day = day;
//    }
//
//    void Print() { // void Print(const Date* this)
//        cout << _year << "-" << _month << "-" << _day << endl;
//        //cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//    }
//
//private:
//    int _year;// 年
//    int _month;// 月
//    int _day;// 日
//};
//
//int main() {
//    Date d1, d2;
//    d1.Init(2022, 1, 11);
//    //d1.Init(&d1, 2022, 1, 11);
//    d2.Init(2022, 1, 12);
//    d1.Print();
//    //d1.Print(&d1);
//    d2.Print();
//    return 0;
//}

//C语言实现栈
//typedef int DataType;
//typedef struct Stack {
//    DataType *array;
//    int capacity;
//    int size;
//} Stack;
//
//void StackInit(Stack *ps) {
//    assert(ps);
//    ps->array = (DataType *) malloc(sizeof(DataType) * 3);
//    if (NULL == ps->array) {
//        assert(0);
//        return;
//    }
//    ps->capacity = 3;
//    ps->size = 0;
//}
//
//void StackDestroy(Stack *ps) {
//    assert(ps);
//    if (ps->array) {
//        free(ps->array);
//        ps->array = NULL;
//        ps->capacity = 0;
//        ps->size = 0;
//    }
//}
//
//void CheckCapacity(Stack *ps) {
//    if (ps->size == ps->capacity) {
//        int newcapacity = ps->capacity * 2;
//        DataType *temp = (DataType *) realloc(ps->array,
//                                              newcapacity * sizeof(DataType));
//        if (temp == NULL) {
//            perror("realloc申请空间失败!!!");
//            return;
//        }
//        ps->array = temp;
//        ps->capacity = newcapacity;
//    }
//}
//
//void StackPush(Stack *ps, DataType data) {
//    assert(ps);
//    CheckCapacity(ps);
//    ps->array[ps->size] = data;
//    ps->size++;
//}
//
//int StackEmpty(Stack *ps) {
//    assert(ps);
//    return 0 == ps->size;
//}
//
//void StackPop(Stack *ps) {
//    if (StackEmpty(ps))
//        return;
//    ps->size--;
//}
//
//DataType StackTop(Stack *ps) {
//    assert(!StackEmpty(ps));
//    return ps->array[ps->size - 1];
//}
//
//int StackSize(Stack *ps) {
//    assert(ps);
//    return ps->size;
//}
//
//int main() {
//    Stack s;
//    StackInit(&s);
//    StackPush(&s, 1);
//    StackPush(&s, 2);
//    StackPush(&s, 3);
//    StackPush(&s, 4);
//    printf("%d\n", StackTop(&s));
//    printf("%d\n", StackSize(&s));
//    StackPop(&s);
//    StackPop(&s);
//    printf("%d\n", StackTop(&s));
//    printf("%d\n", StackSize(&s));
//    StackDestroy(&s);
//    return 0;
//}


//C++实现栈
//typedef int DataType;
//
//class Stack {
//public:
//    void Init() {
//        _array = (DataType *) malloc(sizeof(DataType) * 3);
//        if (NULL == _array) {
//            perror("malloc申请空间失败!!!");
//            return;
//        }
//        _capacity = 3;
//        _size = 0;
//    }
//
//    void Push(DataType data) {
//        CheckCapacity();
//        _array[_size] = data;
//        _size++;
//    }
//
//    void Pop() {
//        if (Empty())
//            return;
//        _size--;
//    }
//
//    DataType Top() { return _array[_size - 1]; }
//
//    int Empty() { return 0 == _size; }
//
//    int Size() { return _size; }
//
//    void Destroy() {
//        if (_array) {
//            free(_array);
//            _array = NULL;
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//
//private:
//    void CheckCapacity() {
//        if (_size == _capacity) {
//            int newcapacity = _capacity * 2;
//            DataType *temp = (DataType *) realloc(_array, newcapacity *
//                                                          sizeof(DataType));
//            if (temp == NULL) {
//                perror("realloc申请空间失败!!!");
//                return;
//            }
//            _array = temp;
//            _capacity = newcapacity;
//        }
//    }
//
//private:
//    DataType *_array;
//    int _capacity;
//    int _size;
//};
//
//int main() {
//    Stack s;
//    s.Init();
//    s.Push(1);
//    s.Push(2);
//    s.Push(3);
//    s.Push(4);
//
//    printf("%d\n", s.Top());
//    printf("%d\n", s.Size());
//    s.Pop();
//    s.Pop();
//    printf("%d\n", s.Top());
//    printf("%d\n", s.Size());
//    s.Destroy();
//    return 0;
//}



//class Date {
//public:
//    //无参构造函数
//    Date() {
//        _year = 1;
//        _month = 1;
//        _day = 1;
//    }
//
//    //带参构造函数
//    Date(int year, int month, int day) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    void Print() {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
////Date d1();函数声明
//
//int main() {
//    Date d1;//调用无参(默认)构造函数
//    //为什么不是 Date d1(); ? 因为这和函数的声明的格式冲突了
//    d1.Print();
//    Date d2(2023, 10, 23);//调用带参构造函数
//    d2.Print();
//    return 0;
//}

//class Date {
//public:
//
////    // 如果用户显式定义了构造函数，编译器将不再生成
////    Date(int year, int month, int day) {
////        _year = year;
////        _month = month;
////        _day = day;
////    }
//
//
//    void Print() {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    // 将Date类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函数
//    // 将Date类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再生成
//    // 无参构造函数，放开后报错：error C2512: “Date”: 没有合适的默认构造函数可用
//    Date d1;
//    return 0;
//}

//class Time {
//public:
//    Time() {
//        cout << "Time()" << endl;
//        _hour = 0;
//        _minute = 0;
//        _second = 0;
//    }
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//

//class Date {
//private:
//    // 基本类型(内置类型)
//    int _year;
//    int _month;
//    int _day;
//    // 自定义类型
//    Time _t;
//};
//
//int main() {
//    Date d;
//    return 0;
//}

//class Time {
//public:
//    Time() {
//        cout << "Time()" << endl;
//        _hour = 0;
//        _minute = 0;
//        _second = 0;
//    }
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//class Date {
//private:
//    // 基本类型(内置类型)
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//    // 自定义类型
//    Time _t;
//};
//
//int main() {
//    Date d;
//    return 0;
//}

//class Time {
//public:
//    Time() {
//        cout << "Time()" << endl;
//        _hour = 0;
//        _minute = 0;
//        _second = 0;
//    }
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//

//class Date {
//public:
//    //默认构造函数(无参构造函数)
////    Date() {
////        _year = 1;
////        _month = 1;
////        _day = 1;
////    }
////   //默认构造函数(全缺省构造函数)
////    Date(int year = 1, int month = 1, int day = 1) {
////        _year = year;
////        _month = month;
////        _day = day;
////    }
//
//    //我们没写编译器默认生成的构造函数，对应下面的缺省成员变量，但是如果有构造函数（非默认）存在（你已经定义了自己的构造函数，编译器就不会再自动生成默认构造函数），
//    //还想要调用默认构造函数的话，需要声明函数 Date(){}，否则调用默认构造函数编译器会找不到默认构造函数
//
//    void Print() {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    //基本类型(内置类型),这里使用缺省的时候，可以直接使用编译器默认的构造函数，会传值帮它初始化为这个缺省值而不是随机值
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//};
//
//int main() {
//    Date d;
//    d.Print();
//    return 0;
//}

//class Date {
//public:
//
//    //Date(){} //存在非默认构造函数时候，配合下面缺省成员变量使用
//    Date(int year, int month, int day) { //你已经定义了自己的构造函数，编译器就不会再自动生成默认构造函数
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    void Print() {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    //基本类型(内置类型),这里使用缺省的时候，可以直接使用编译器默认的构造函数，会传值帮它初始化为这个缺省值而不是随机值
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//};
//
//int main() {
//    Date d;//报错，找不到默认构造函数
//    d.Print();
//    return 0;
//}

//typedef int DataType;
//
//class Stack {
//public:
//    Stack(size_t capacity = 3) {
//        _array = (DataType *) malloc(sizeof(DataType) * capacity);
//        if (NULL == _array) {
//            perror("malloc申请空间失败!!!");
//            return;
//        }
//        _capacity = capacity;
//        _size = 0;
//    }
//
//    void Push(DataType data) {
//        // CheckCapacity();
//        _array[_size] = data;
//        _size++;
//    }
//
//    // 其他方法...
//    ~Stack() {
//        if (_array) {
//            free(_array);
//            _array = NULL;
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//
//private:
//    DataType *_array;
//    int _capacity;
//    int _size;
//};
//
//void TestStack() {
//    Stack s;
//    s.Push(1);
//    s.Push(2);
//}
//
//int main(){
//    TestStack();
//    return 0;
//}


//class Time {
//public:
//    ~Time() {
//        cout << "~Time()" << endl;
//    }
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//class Date {
//private:
//    // 基本类型(内置类型)
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//    // 自定义类型
//    Time _t;
//};
//
//int main() {
//    Date d;
//    // 在main方法中根本没有直接创建Time类的对象，为什么最后会调用Time类的析构函数？
//    // 因为：main方法中创建了Date对象d，而d中包含4个成员变量，其中_year, _month,_day三个是
//    // 内置类型成员，销毁时不需要资源清理，最后系统直接将其内存回收即可；而_t是Time类对象，所以在
//    // d销毁时，要将其内部包含的Time类的_t对象销毁，所以要调用Time类的析构函数。但是：main函数
//    // 中不能直接调用Time类的析构函数，实际要释放的是Date类对象，所以编译器会调用Date类的析构函
//    // 数，而Date没有显式提供，则编译器会给Date类生成一个默认的析构函数，目的是在其内部调用Time
//    // 类的析构函数，即当Date对象销毁时，要保证其内部每个自定义对象都可以正确销毁
//    // main函数中并没有直接调用Time类析构函数，而是显式调用编译器为Date类生成的默认析构函数
//    // 注意：创建哪个类的对象则调用该类的构造函数，销毁那个类的对象则调用该类的析构函数
//    return 0;
//}

//class Date {
//public:
//    Date(int year = 1900, int month = 1, int day = 1) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // Date(const Date& d)  // 正确写法
//    Date(const Date &d)
//
//    // 错误写法：编译报错，会引发无穷递归
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    Date d1;
//    Date d2(d1);
//    return 0;
//}

//class Time {
//public:
//    Time() {
//        _hour = 1;
//        _minute = 1;
//        _second = 1;
//    }
//
//    Time(const Time &t) {
//        _hour = t._hour;
//        _minute = t._minute;
//        _second = t._second;
//        cout << "Time::Time(const Time&)" << endl;
//    }
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//class Date {
//private:
//    // 基本类型(内置类型)
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//    // 自定义类型
//    Time _t;
//};
//
//int main() {
//    Date d1;
//    // 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
//    // 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数
//    Date d2(d1);
//    return 0;
//}


//// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//
//class Stack {
//public:
//    Stack(size_t capacity = 10) {
//        _array = (DataType *) malloc(capacity * sizeof(DataType));
//        if (nullptr == _array) {
//            perror("malloc申请空间失败");
//            return;
//        }
//        _size = 0;
//        _capacity = capacity;
//    }
//
////    //  改良
////    Stack (const Stack& st){
////        this->_array = (DataType *) malloc(st._capacity * sizeof(DataType));
////        if (nullptr == this->_array) {
////            perror("malloc申请空间失败");
////            return;
////        }
////        this->_size = st._size;
////        this->_capacity = st._capacity;
////    }
//
//    void Push(const DataType &data) {
//        // CheckCapacity();
//        _array[_size] = data;
//        _size++;
//    }
//
//    ~Stack() {
//        cout << "~Stack()" << endl;
//        if (_array) {
//            free(_array);
//            _array = nullptr;
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//
//private:
//    DataType *_array;
//    size_t _size;
//    size_t _capacity;
//};
//
//int main() {
//    Stack s1;
//    s1.Push(1);
//    s1.Push(2);
//    s1.Push(3);
//    s1.Push(4);
//    Stack s2(s1);
//    return 0;
//}

#include <iostream>

using namespace std;

//class Date {
//public:
//    Date(int year, int minute, int day) {
//        cout << "Date(int,int,int):" << this << endl;
//    }
//
//    Date(const Date &d) {
//        cout << "Date(const Date& d):" << this << endl;
//    }
//
//    ~Date() {
//        cout << "~Date():" << this << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//Date Test(Date d) {
//    Date temp(d);
//    return temp;//这里不调用拷贝构造函数可能是编译器优化了
//}
//
//int main() {
//    Date d1(2023, 10, 25);
//    Test(d1);
//    return 0;
//}

//// 全局的operator==
//class Date {
//public:
//    Date(int year = 1900, int month = 1, int day = 1) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
////private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//// 这里会发现运算符重载成全局的就需要成员变量是公有的，那么问题来了，封装性如何保证？
//// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
//bool operator==(const Date &d1, const Date &d2) {
//    return d1._year == d2._year
//           && d1._month == d2._month
//           && d1._day == d2._day;
//}
//
//void Test() {
//    Date d1(2018, 9, 26);
//    Date d2(2018, 9, 27);
//    cout << (d1 == d2) << endl;
//}
//
//int main() {
//    Test();
//    return 0;
//}


//// 类里面的operator==
//class Date {
//
//public:
//    Date(int year = 1900, int month = 1, int day = 1) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    //干脆重载成成员函数。
//    //bool operator==(const Date* this,const Date &d2)
//    //隐含了this
//    bool operator==(const Date &d2) {
//        return this->_year == d2._year
//               && _month == d2._month
//               && _day == d2._day;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//void Test() {
//    Date d1(2018, 9, 26);
//    Date d2(2018, 9, 27);
//    cout << (d1 == d2) << endl;//流插入运算符优先级比重载的运算符 == 高 ，所以加括号提升优先级
//    //d1 == d2 --> d1.operator==(d2)
//    cout << d1.operator==(d2) << endl;//相当于d1.operator==(&d1,d2);
//}
//
//int main() {
//    Test();
//    return 0;
//}

//class Date {
//public :
//    Date(int year = 1900, int month = 1, int day = 1) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    Date(const Date &d) {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//
//    //Date &operator=(const Date* this, const Date &d)
//    Date &operator=(const Date &d) {
//        if (this != &d) {//防止自己给自己赋值
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//
//        return *this;//支持连续赋值
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//void Test() {
//    Date d1(2018, 9, 26);
//    Date d2(2018, 9, 27);
//    d1 = d2;//d1 = d2 --> d1.operator=(d2)
//    d1.operator=(d2);//相当于 d1.operator=(&d1,d2);
//}
//
//int main(){
//    Test();
//    return 0;
//}

//class Date {
//public:
//    Date(int year = 1900, int month = 1, int day = 1) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    int _year;
//    int _month;
//    int _day;
//};
//
//// 赋值运算符重载成全局函数，注意重载成全局函数时没有this指针了，需要给两个参数
//Date &operator=(Date &left, const Date &right) {
//    if (&left != &right) {
//        left._year = right._year;
//        left._month = right._month;
//        left._day = right._day;
//    }
//    return left;
//}
//// 编译失败：
//// error C2801: “operator =”必须是非静态成员

//class Time {
//public:
//    Time() {
//        _hour = 1;
//        _minute = 1;
//        _second = 1;
//    }
//
//    //这里都是自定义类型赋值，其实可以不用自己实现
//    Time &operator=(const Time &t) {
//        if (this != &t) {
//            _hour = t._hour;
//            _minute = t._minute;
//            _second = t._second;
//        }
//        return *this;
//    }
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
//
//class Date {
//private:
//    // 基本类型(内置类型)
//    int _year = 1970;
//    int _month = 1;
//    int _day = 1;
//    // 自定义类型
//    Time _t;
//};
//
//int main() {
//    Date d1;
//    Date d2;
//    d1 = d2;
//    return 0;
//}

// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
//typedef int DataType;
//
//class Stack1 {
//public:
//    Stack1(size_t capacity = 10) {
//        _array = (DataType *) malloc(capacity * sizeof(DataType));
//        if (nullptr == _array) {
//            perror("malloc申请空间失败");
//            return;
//        }
//        _size = 0;
//        _capacity = capacity;
//    }
//
//    void Push(const DataType &data) {
//        // CheckCapacity();
//        _array[_size] = data;
//        _size++;
//    }
//
//
//    ~Stack1() {
//        if (_array) {
//            free(_array);
//            _array = nullptr;
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//
//private:
//    DataType *_array;
//    size_t _size;
//    size_t _capacity;
//};
//
//int main() {
//    Stack1 s1;
//    s1.Push(1);
//    s1.Push(2);
//    s1.Push(3);
//    s1.Push(4);
//    Stack1 s2;
//    s2 = s1;
//    return 0;
//}

////解决办法
//typedef int DataType;
//
//class Stack1 {
//public:
//    Stack1(size_t capacity = 10) {
//        _array = (DataType *) malloc(capacity * sizeof(DataType));
//        if (nullptr == _array) {
//            perror("malloc申请空间失败");
//            return;
//        }
//        _size = 0;
//        _capacity = capacity;
//    }
//
//    Stack1& operator=(const Stack1 &st) {
//        this->_array = (DataType *) malloc(st._capacity * sizeof(DataType));
//        if (nullptr == this->_array) {
//            perror("malloc申请空间失败");
//            exit(-1);
//        }
//        this->_size = st._size;
//        this->_capacity = st._capacity;
//        return *this;
//    }
//
//    void Push(const DataType &data) {
//        // CheckCapacity();
//        _array[_size] = data;
//        _size++;
//    }
//
//
//    ~Stack1() {
//        if (_array) {
//            free(_array);
//            _array = nullptr;
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//
//private:
//    DataType *_array;
//    size_t _size;
//    size_t _capacity;
//};
//
//int main() {
//    Stack1 s1;
//    s1.Push(1);
//    s1.Push(2);
//    s1.Push(3);
//    s1.Push(4);
//    Stack1 s2;
//    s2 = s1;
//    return 0;
//}


//日期类
//class Date {
//public:
//    //默认构造函数，与下面全缺省成员变量配合使用
//    Date() {
//    }
//
//    Date(int year, int month, int day) { //你已经定义了自己的构造函数，编译器就不会再自动生成默认构造函数
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    // 前置++ 加完原来的值也改变
//    // *this就是d1
//    Date &operator++() {
//        _day += 1;
//        return *this;
//    }
//
//    Date operator++(int ){ //后置++运算符重载就是这样规定的，参数加个int类型
//        Date temp(*this);
//        _day += 1;
//        return temp;//临时对象，不能引用
//    }
//
//private:
//    int _year = 1900;
//    int _month = 1;
//    int _day = 1;
//};
//
//
//int main() {
//    Date d1;
//    Date d;
//    d = ++d1;//d1.operator++(&d1);
//    d = d1++;
//    return 0;
//}

#include "Date.h"

int main() {
    Date d;
    Date d1(2023, 10, 27);
    Date d2;
    Date d3(2100, 7, 22);

//    d2 += 10;
//    d3 = d2 + 10;
//
//    d2 -= 10;
//    d3 = d2 - 10;

    d1 -= 100;
    d1 -= -100;

    cout << (d1 - d2) << endl;

    return 0;
}