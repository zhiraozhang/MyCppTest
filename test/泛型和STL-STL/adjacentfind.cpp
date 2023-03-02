/**
 * @file adjacentfind.cpp
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
#include <string>
using namespace std;
void test01()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(1);
    v.push_back(9);
    v.push_back(9);
    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos == v.end())
        cout << "没有找到相邻重复元素。" << endl;
    else
        cout << "找到了：" << *pos << endl;
}
int main()
{
    test01();
    return 0;
}