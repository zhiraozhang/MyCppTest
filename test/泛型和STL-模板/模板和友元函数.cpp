/**
 * @file 模板和友元函数.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-20
 *
 * @copyright Copyright (c) 2023
 *
 *   // 全局函数类外实现
 *   // 1.需要加一个空模板的参数列表
 *   // 2.需要在上方让编译器知道Person的存在
 *   // 3.需要在上方让编译器知道函数存在
 */

#include <iostream>
#include <string>

using namespace std;

// 全局函数类外实现第2条：需要在上方让编译器知道Person的存在
template <class T1, class T2>
class Person;

// 全局函数类外实现第3条：需要在上方让编译器知道函数存在
template <class T1, class T2>
void printPerson02(Person<T1, T2> p)
{
    cout << "类外实现：姓名为：" << p.m_name << "，年龄为：" << p.m_age << endl;
};

template <class T1, class T2>
class Person
{
    // 全局函数类内实现
    friend void printPerson01(Person<T1, T2> p)
    {
        cout << "类内实现：姓名为：" << p.m_name << "，年龄为：" << p.m_age << endl;
    };
    // 全局函数类外实现第1条：需要加一个空模板的参数列表
    friend void printPerson02<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    };

private:
    T1 m_name;
    T2 m_age;
};

void test01()
{
    Person<string, int> p("zhangsan", 18);
    printPerson01(p);
}
void test02()
{
    Person<string, int> p("lisi", 20);
    printPerson02(p);
}

int main()
{
    test01();
    test02();
    return 0;
}