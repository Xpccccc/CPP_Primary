#include <iostream>
#include <list>
#include <vector>

using namespace std;


void test_list1() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);

    list<int>::reverse_iterator rit = lt.rbegin();
    while (rit != lt.rend()) {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;

    lt.pop_back();
    cout << lt.front() << " " << lt.back() << endl;

    lt.push_front(10);
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    lt.pop_front();
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    lt.assign(2, 11);
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;
}

void test_list2() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);

    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    lt.insert(++lt.begin(), 10);
    lt.insert(find(lt.begin(), lt.end(), 3), 30);
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    list<int>::iterator it = lt.erase(find(lt.begin(), lt.end(), 4));//返回被删元素的后一个位置
    cout << *it << endl;
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    lt.resize(12, 9);
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    lt.clear();
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;
}

void test_list3() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(2);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(4);
    lt.push_back(4);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(2);
    lt.push_back(6);

    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    lt.sort();
    lt.unique();//只针对连续的相同的元素进行只存一个的操作，所以可以先排序再调用这个接口
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    lt.reverse();
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    // LRU 把2放到最后面去
    lt.splice(lt.end(), lt, find(lt.begin(), lt.end(), 2));//可以自己给自己的元素转移
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

}

void test_list4() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(6);

    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    list<int> lt1(10, 2);
    for (auto e: lt1) {
        cout << e << " ";
    }
    cout << endl;

    list<int> lt2(lt1.begin(), lt1.end());
    for (auto e: lt2) {
        cout << e << " ";
    }
    cout << endl;

    list<int> lt3(lt2);
    for (auto e: lt3) {
        cout << e << " ";
    }
    cout << endl;

}

void test_list5() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(6);

    list<int>::iterator it = lt.begin();
    while (it != lt.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;


    list<int>::reverse_iterator rit = lt.rbegin();
    while (rit != lt.rend()) {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

void test_list6() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(6);

    cout << lt.size() << endl;
    cout << lt.empty() << endl;

    lt.assign(0, 0);
    cout << lt.size() << endl;
    cout << lt.empty() << endl;
}

void test_list7() {
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(6);

    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    cout << lt.front() << endl;
    cout << lt.back() << endl;

    lt.push_front(10);
    lt.push_back(9);
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    lt.pop_front();
    lt.pop_back();
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    lt.insert(find(lt.begin(),lt.end(),4),40);
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    list<int>::iterator it = lt.erase(find(lt.begin(),lt.end(),6));
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    list<int> lt1(10,1);
    swap(lt,lt1);
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

    for (auto e: lt1) {
        cout << e << " ";
    }
    cout << endl;

    lt.clear();
    for (auto e: lt) {
        cout << e << " ";
    }
    cout << endl;

}

// 迭代器失效问题
void TestListIterator1()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    list<int> l(array, array+sizeof(array)/sizeof(array[0]));
    auto it = l.begin();
    while (it != l.end())
    {
        // erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋值
//        l.erase(it);
        it = l.erase(it);
        ++it;// 每次跳一个删除
    }
}

// list的使用
int main() {
//    test_list1();
//    test_list2();
//    test_list7();
//    test_list6();
//    test_list5();
//    test_list4();
    TestListIterator1();
    return 0;
}
