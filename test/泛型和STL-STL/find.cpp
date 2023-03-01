/**
 * @file find.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-03-01
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void test01()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if (it == v.end())
    {
        cout << "没有找到。" << endl;
    }
    else
        cout << "找到了：" << *it << endl;
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
    // 需要重载==号
    bool operator==(const Person &p)
    {
        return this->age == p.age && this->name == p.name;
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
    Person p0("ccc", 31);
    vector<Person>::iterator it = find(v.begin(), v.end(), p0);
    if (it == v.end())
        cout << "没有找到。" << endl;
    else
        cout << "找到了：" << it->name << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}