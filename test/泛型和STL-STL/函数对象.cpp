/**
 * @file 函数对象.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-28
 * 
 * @copyright Copyright (c) 2023
 * 
 * 函数对象
 * 概念：重载函数调用操作符的类，其对象常称为函数对象；函数对象使用重载的()时，行为类似函数调用，被称为仿函数
 * 本质：是一个类，不是函数
 * 使用：函数对象在使用时，可以像普通函数那样调用，可以有参数也可以有返回值；但是超出普通函数的是函数对象可以有自己的状态；函数对象可以作为参数传递。
 * 
 * 
 * 内建函数对象
 * 1.算数放函数：plus,minus,multiplies,divides,modulus,negate(取反)
 * 2.关系仿函数：equal_to ,not_equal_to,greater,greater_equal,less,less_equal
 * 3.逻辑放函数：bool logical_and,logical_or,logical_not
 **/

#include<iostream>
#include<string>
using namespace std;

class Myadd
{
public:
    int operator()(int v1,int v2)
    {
        return v1 + v2;
    }
};

void test01()
{
    Myadd myadd;
    cout << myadd(10, 20) << endl;
}

//状态

int main()
{
    test01();
    return 0;
}