#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <string>

// vector存放内置数据类型

// void MyPrint(int val) {
//     cout << val << endl;
// }

// int main () {
//
//     vector<int> v;
//     v.push_back(10);
//     v.push_back(20);
//     v.push_back(30);
//     vector<int>::iterator pBegin = v.begin();
//     vector<int>::iterator pEnd = v.end();

//     //第一种遍历
//     while (pBegin != pEnd) {
//         cout << *pBegin << endl;
//         pBegin++;
//     }

//     //第二种遍历
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//         cout << *it << endl;
//     }

//     //第三种遍历
//     //使用STL提供标准遍历算法  头文件 algorithm
//     for_each(v.begin(), v.end(), MyPrint);
//     return 0;
// }

// vector存放自定义数据类型

class Person
{
public:
    Person(string name, int age)
    {
        mName = name;
        mAge = age;
    }

public:
    string mName;
    int mAge;
};

int main()
{
    vector<Person> p;

    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);

    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);

    for (vector<Person>::iterator it = p.begin(); it != p.end(); it++)
    {
        cout << it->mName << it->mAge << endl;
    }
}
