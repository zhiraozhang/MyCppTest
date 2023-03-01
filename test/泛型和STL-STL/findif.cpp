/**
 * @file findif.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-03-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};
void test01()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
        cout << "没有找到。" << endl;
    else
        cout << "找到大于5的数字：" << *it << endl;
}
class Person
{
public:
    string name;
    int age;
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};
class Greater20
{
public:
    bool operator()(const Person &p)
    {
        return p.age > 20;
    }
};
void test02()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
    if (it != v.end())
        cout << "找到大于20岁的人：" << it->name << endl;
    else
        cout << "没有找到。" << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}