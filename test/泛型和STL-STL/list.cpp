/**
 * @file list.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-26
 *
 * @copyright Copyright (c) 2023
 *
 * STL中是循环链表
 * 优点：
 *     动态分配，不会造成内存浪费和溢出
 *     可以对任意位置进行插入或删除元素，不必移动大量元素
 * 缺点：
 *     容器遍历速度没有数组快
 *     占用空间比数组大
 *     空间和时间复杂度大
 *

 * begin()
 * end()
 * //赋值
 * assign(beg,end)
 * assign(n,elem)
 * size()
 * empty
 * resize(num)
 * resize(num,elem)
 * 插入删除
 * pop_back()
 * push_back()
 * pop_front()
 * push_front()
 * insert()
 * remove()
 * clear()
 * erase()
 * 反转和排序
 * reverse()
 * sort()
 *
 */
#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> &ls)
{
    for (list<int>::const_iterator it = ls.begin(); it != ls.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// 赋值
void test01()
{
    list<int> ls1;
    ls1.push_back(10);
    ls1.push_back(20);
    ls1.push_back(30);
    ls1.push_back(40);
    printList(ls1);

    list<int> ls2 = ls1;
    printList(ls2);

    list<int> ls3;
    ls3.assign(ls1.begin(), ls1.end());
    printList(ls3);

    list<int> ls4;
    ls4.assign(10, 100);
    printList(ls4);
}
// 交换
void test02()
{
    list<int> ls1;
    ls1.push_back(10);
    ls1.push_back(20);
    ls1.push_back(30);
    ls1.push_back(40);
    printList(ls1);
    list<int> ls4;
    ls4.assign(10, 100);
    printList(ls4);
    swap(ls1, ls4);
    printList(ls1);
    printList(ls4);
}
int main()
{
    test01();
    test02();
    return 0;
}