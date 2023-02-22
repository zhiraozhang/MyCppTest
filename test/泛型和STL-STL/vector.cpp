#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

// vector初识
void test00()
{
    // vector<int>
    vector<size_t> vec;
    // 显示vec原始大小
    cout << "vector size = " << vec.size() << endl;
    for (int i = 0; i < 5; i++)
    {
        // 随机放入5个数
        vec.push_back(rand());
    }
    cout << "插入5个数之后，vector size = " << vec.size() << endl;
    // 访问向量中的 5 个值
    for (int i = 0; i < 5; i++)
    {
        cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }
    // 三种遍历方式
    // while
    // for，见test01
    // for_each
    //  使用迭代器 iterator 访问值，vec.begin()启示迭代器，指向第一个元素。vec.end()结束迭代器，指向容器中最后一个元素的下一个位置
    vector<size_t>::iterator v = vec.begin();
    cout << "while遍历vector" << endl;
    while (v != vec.end())
    {
        cout << "value of v = " << *v << endl;
        v++;
    }
}
void test01()
{
    Person p1("Jack", 18);
    Person p2("Sam", 19);
    Person p3("Lily", 20);
    Person p4("GalaDOS", 999);
    vector<Person> vperson;
    vperson.push_back(p1);
    vperson.push_back(p2);
    vperson.push_back(p3);
    vperson.push_back(p4);
    // 遍历vector<Person>
    cout << "遍历vector<Person>数组" << endl;
    for (vector<Person>::iterator v = vperson.begin(); v != vperson.end(); v++)
    {
        // 可以使用v->或者 (*v).
        cout << "姓名为：" << v->m_name << "年龄为：" << (*v).m_age << endl;
    }
}
void test03()
{
    // 嵌套容器
    vector<vector<int>> vvint;
    vector<int> v1, v2, v3, v4;
    // 4个小容器，每个里面5个数
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }
    vvint.push_back(v1);
    vvint.push_back(v2);
    vvint.push_back(v3);
    vvint.push_back(v4);
}
int main()
{
    test00();
    test01();
    return 0;
}