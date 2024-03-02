#include <iostream>

using namespace std;

#include <vector>

// vector迭代器失效问题
//int main() {
//    vector<int> v{1, 2, 3, 4, 5, 6};
//
//    auto it = v.begin();
//
//    // 将有效元素个数增加到100个，多出的位置使用8填充，操作期间底层会扩容
//     v.resize(100, 8);
//
//    // reserve的作用就是改变扩容大小但不改变有效元素个数，操作期间可能会引起底层容量改变
//    // v.reserve(100);
//
//    // 插入元素期间，可能会引起扩容，而导致原空间被释放
//    // v.insert(v.begin(), 0);
//    // v.push_back(8);
//
//    // 给vector重新赋值，可能会引起底层容量改变
////    v.assign(100, 8);
//
//    /*
//    出错原因：以上操作，都有可能会导致vector扩容，也就是说vector底层原理旧空间被释放掉，
//   而在打印时，it还使用的是释放之间的旧空间，在对it迭代器操作时，实际操作的是一块已经被释放的
//   空间，而引起代码运行时崩溃。
//    解决方式：在以上操作完成之后，如果想要继续通过迭代器操作vector中的元素，只需给it重新
//   赋值即可。
//    */
//
//    it = v.begin();//解决办法
//    while (it != v.end()) {
//        cout << *it << " ";
//        ++it;
//    }
//    cout << endl;
//    return 0;
//}


int main() {
    int a[] = {1, 2, 3, 4};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    // 使用find查找3所在位置的iterator
    vector<int>::iterator pos = find(v.begin(), v.end(), 3);
    // 删除pos位置的数据，导致pos迭代器失效。
    v.erase(pos);
    cout << *pos << endl; // 此处会导致非法访问，解决办法：不再访问pos

    v.push_back(5);
    v.push_back(6);
    v.push_back(6);
    v.push_back(5);
    v.push_back(8);

    for (auto e: v) {
        cout << e << " ";
    }
    cout << endl;

    //删除v里所有偶数
    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        if (*it % 2 == 0) {
//            v.erase(it);//这里最好不再用it
            it = v.erase(it);//解决办法
        } else {
            ++it;
        }
    }
    for (auto e: v) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}

//#include <string>
//
//int main() {
//
//    string s("hello");
//    string::iterator sit = s.begin();
//
//    // 这里resize过后，会扩容，之前等sit的位置会改变
//    s.resize(100, 'w');
//
//    // 解决办法，给sit重新赋值
//    sit = s.begin();
//    while (sit != s.end()) {
//        cout << *sit << " ";
//        ++sit;
//    }
//    cout << endl;
//
//    sit = s.begin();
//    while (sit != s.end()) {
//        sit = s.erase(sit);//这里s.erase(sit)后的sit位置是之前sit的后一个位置
//        ++sit;//说明是隔一个元素删除
//    }
//
//    for (char e: s) {
//        cout << e << " ";
//    }
//    cout << endl;
//    return 0;
//}
