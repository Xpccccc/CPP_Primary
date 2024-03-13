#include <iostream>
#include "stack_queue.h"


using namespace std;


// 模版特化示例
int main() {
    Date *d1 = new Date(2024, 3, 11);
    Date *d2 = new Date(2024, 3, 13);
    Date *d3 = new Date(2024, 3, 10);


//    xp::priority_queue<Date *> pq1;
    xp::priority_queue<Date *, vector<Date *>, xp::greater<Date *>> pq1;// 注意这里greater要指定命名空间
    pq1.push(d1);
    pq1.push(d2);
    pq1.push(d3);

    while (!pq1.empty()) {
        cout << *pq1.top();
        pq1.pop();
    }
    cout << "-------------\n";

    xp::priority_queue<int *> pq2;// 注意这里greater要指定命名空间
    pq2.push(new int(1));
    pq2.push(new int(3));
    pq2.push(new int(2));
    pq2.push(new int(4));

    while (!pq2.empty()) {
        cout << *pq2.top() << endl;
        pq2.pop();
    }

    return 0;
}





//template<class T1, class T2>
//class Date1 {
//public:
//    Date1() {
//        cout << "Date <T1 ,T2>" << endl;
//    }
//
//private:
//    T1 _d1;
//    T2 _d2;
//};
//
//// 类模版全特化
//template<>
//class Date1<char, int> {
//public:
//    Date1() {
//        cout << "Date <char ,int>" << endl;
//    }
//
//private:
//    int _d1;
//    char _d2;
//};
//
//// 类模版偏特化
//template<class T1, class T2>
//class Date1<T1 *, T2 *> {
//public:
//    Date1() {
//        cout << "Date <T1* ,T2*>" << endl;
//    }
//
//private:
//    T1 *_d1;
//    T2 *_d2;
//};
//
//int main() {
//    Date1<char, char> d1;
//    Date1<char, int> d2;
//    Date1<char *, int *> d3;
//    Date1<int *, int *> d4;
//    Date1<int *, char> d5;
//    return 0;
//}



//template<class T1, class T2>
//class Date1 {
//public:
//    Date1() {
//        cout << "Date <T1 ,T2>" << endl;
//    }
//
//private:
//    T1 _d1;
//    T2 _d2;
//};
//
//template<class T>
//class Date1<T, int> {
//public:
//    Date1() {
//        cout << "Date <T,int>" << endl;
//    }
//
//private:
//    T _d1;
//    int _d2;
//};
//
////两个参数偏特化为指针类型
//template<class T>
//class Date1<T *, T *> {
//public:
//    Date1() {
//        cout << "Date <T*,T*>" << endl;
//    }
//
//private:
//    T *_d1;
//    T *_d2;
//};
//
////两个参数偏特化分别为引用类型和指针类型
//template<class T1, class T2>
//class Date1<T1 &, T2 *> {
//public:
//    Date1() {
//        cout << "Date <T&,T*>" << endl;
//    }
//
//private:
//    T1 _d1;
//    T2 _d2;
//};
//
//
//int main() {
//    Date1<char, double> d0; // Date <T1 ,T2>
//    Date1<double, int> d1; // Date <T,int>
//    Date1<int *, int *> d2; // Date <T*,T*>
//    Date1<int &, int *> d3; // Date <T&,T*>
//    return 0;
//}




//template<class T>
//bool Less(const T x, const T y) {
//    return x < y;
//}
//
//// 函数模版全特化
//template<>
//bool Less(const int x, const int y) {
//    return x < y;
//}
//
////// 函数模版偏特化 --- 不支持
////template<class T1>
////bool Less(const T1 x, const int y) {
////    return x < y;
////}
//int main() {
//    cout << Less(1, 2) << endl;
//    cout << Less(2.2, 1.2) << endl;
//    return 0;
//}








//#include <iostream>
//
//using namespace std;
//
//namespace xp {
//    template<class T, size_t N = 10>
//    class array {
//    public:
//        T &operator[](size_t pos) {
//            return _array[pos];
//        }
//
//        bool empty() {
//            return 0 == _size;
//        }
//
//    private:
//        T _array[N];
//        size_t _size;
//    };
//}
//
//int main() {
//
//    xp::array<int> arr;
//    cout << arr[0] << endl; // 随机值
//    cout << arr.empty() << endl;
//    return 0;
//}


