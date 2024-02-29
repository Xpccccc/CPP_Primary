#include <iostream>
#include <vector>
#include <list>

using namespace std;

void test_vector1() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    for (int e: v) {
        cout << e << " ";
    }
    cout << endl;
}

void test_vector2() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    for (int e: v1) {
        cout << e << " ";
    }
    cout << endl;

    //用顺序表v1构造v2
    vector<int> v2(v1);
    for (int e: v2) {
        cout << e << " ";
    }
    cout << endl;

    //用顺序表v1的迭代区间构造v3
    vector<int> v3(v1.begin(), v1.end());
    for (int e: v3) {
        cout << e << " ";
    }
    cout << endl;

    //构造长度为10并且各元素为1的顺序表
    vector<int> v4(10, 1);
    for (int e: v4) {
        cout << e << " ";
    }
    cout << endl;
}

void test_vector3() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    v1.insert(v1.begin(), 10);
    for (int e: v1) {
        cout << e << " ";
    }
    cout << endl;
    vector<int>::iterator pos = find(v1.begin(), v1.end(), 4);//find是函数模版
    v1.insert(pos, 40);
    for (int e: v1) {
        cout << e << " ";
    }

    cout << endl;
    list<int> lt;
    lt.push_back(5);
    lt.push_back(6);
    lt.push_back(7);
    lt.push_back(8);
    for (int e: lt) {
        cout << e << " ";
    }
    cout << endl;

    vector<int> v3(lt.begin(), lt.end());
    for (int e: v3) {
        cout << e << " ";
    }
    cout << endl;


}

// 测试vector的默认扩容机制 -- 这里CLion是2倍扩容，VS是1.5倍扩容
// 如果已经确定vector中要存储元素大概个数，可以提前将空间设置足够
// 就可以避免边插入边扩容导致效率低下的问题了
void TestVectorExpand() {
    size_t sz;
    vector<int> v;
    sz = v.capacity();
    v.reserve(100); // 提前将容量设置好，可以避免一遍插入一遍扩容
    cout << "making v grow:\n";
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
        if (sz != v.capacity()) {
            sz = v.capacity();
            cout << "capacity changed: " << sz << '\n';
        }
    }
}

void test_vector4() {
    TestVectorExpand();
}

void test_vector5() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int>::iterator it1 = v1.begin();
    while (it1 != v1.end()) {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;

    vector<int>::const_iterator it2 = v1.begin();
    while (it2 != v1.end()) {
        cout << *it2 << " ";
        ++it2;
    }
    cout << endl;

}

void test_vector6() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int>::reverse_iterator it1 = v1.rbegin();
    while (it1 != v1.rend()) {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
}

void test_vector7() {
    vector<int> v1;
    cout << v1.size() << " " << v1.capacity() << endl;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    cout << v1.size() << " " << v1.capacity() << endl;
    v1.resize(10);
    cout << v1.size() << " " << v1.capacity() << endl;
    v1.reserve(11);
    cout << v1.size() << " " << v1.capacity() << endl;
    v1.resize(5);
    cout << v1.size() << " " << v1.capacity() << endl;

    cout << v1.empty() << endl;
    v1.resize(0);
    cout << v1.empty() << endl;

}

void test_vector8() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    for (int e: v1) {
        cout << e << " ";
    }
    cout << endl;
    v1.pop_back();
    for (int e: v1) {
        cout << e << " ";
    }
    cout << endl;

    cout << v1[0] << endl;
    v1.insert(v1.begin(), 10);
    for (int e: v1) {
        cout << e << " ";
    }
    cout << endl;

    vector<int>::iterator it = find(v1.begin(), v1.end(), 3);
    v1.erase(it);
    for (int e: v1) {
        cout << e << " ";
    }
    cout << endl;

    cout << "-----------------------" << endl;
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    v2.push_back(60);
    for (int e: v2) {
        cout << e << " ";
    }
    cout << endl;
    cout << "-----------------------" << endl;

    swap(v1, v2);
    for (int e: v1) {
        cout << e << " ";
    }
    cout << endl;
    for (int e: v2) {
        cout << e << " ";
    }
    cout << endl;

}

//vector的使用
int main() {
//    test_vector1();
//    test_vector2();
//    test_vector3();
//    test_vector4();
//    test_vector5();
//    test_vector6();
//    test_vector7();
    test_vector8();


    return 0;
}
