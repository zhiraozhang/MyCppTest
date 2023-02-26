/**
 * @file set.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-26
 *
 * @copyright Copyright (c) 2023
 * set/multiset
 * 自动排序、关联式容器、二叉树实现
 * 如果不允许插入重复数据可以用pair
 */

#include <iostream>
#include <set>

using namespace std;

void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(40);
    s1.insert(30);

    for (set<int>::iterator i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i
             << " ";
    }
    cout << endl;
}
// 用pair不让插入重复值
void test02()
{
    set<int> s2;
    s2.insert(10);
    pair<set<int>::iterator, bool> ret = s2.insert(10);
    if (ret.second)
    {
        cout << "插入成功" << endl;
    }
    else
        cout << "插入失败!" << endl;
}
// 仿函数自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
class comparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.m_Age > p2.m_Age;
    }
};
void test03()
{
    set<Person, comparePerson> s3;
    Person p1("关羽", 33);
    Person p2("张飞", 30);
    Person p3("赵云", 29);
    Person p4("马超", 32);
    Person p5("黄忠", 50);
    s3.insert(p1);
    s3.insert(p2);
    s3.insert(p3);
    s3.insert(p4);
    s3.insert(p5);
    for (set<Person, comparePerson>::iterator it = s3.begin(); it != s3.end(); it++)
    {
        cout << it->m_Name << endl;
    }
}
int main()
{
    test01();
    test02();
    test03();
    return 0;
}