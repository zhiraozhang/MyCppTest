/**
 * @file map.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-26
 *
 * @copyright Copyright (c) 2023
 *
 * map/multimap：关联式键值对容器
 * 底层结构：二叉树
 * map中所有元素都是pair
 * pair第一个元素为key（键值，索引值），第二个是value（实值）
 * 所有元素都会根据键值自动排序
 * 优点：可以根据key值快速找到value值
 * map和multimap区别：
 * map不允许有重复key，multimap允许有重复key
 * 构造：
 *     map(T1,T2) m;//默认构造
 *     map(const map &m);//拷贝构造
 *     map& operator=(const map &m);//重载等号运算符
 * 大小和交换：
 *     size();
 *     empty();
 *     swap();
 * 插入和删除：
 *     insert(key,value);
 *     clear();
 *     erase(pos);
 *     erase(beg,end);
 *     erase(key);
 * 查找和统计：
 *     find(key);
 *     count(key);
 */
#include <iostream>
#include <map>

using namespace std;

void test01()
{
    map<int, int> m;
    // pair & make_pair
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));
    m.insert(make_pair(6, 60));

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}
// 仿函数
class MyCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};
void test02()
{
    map<int, int, MyCompare> m;
    // pair & make_pair
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));
    m.insert(make_pair(6, 60));

    cout << "通过仿函数返反向排序：" << endl;
    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}
int main()
{
    test01();
    test02();
    return 0;
}