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

// list的使用
int main() {
//    test_list1();
//    test_list2();
    test_list3();
    return 0;
}
