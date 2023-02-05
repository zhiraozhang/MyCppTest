/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：初始化列表.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：20231年02月05日
*   描    述：浅拷贝就是简单的复制拷贝，深拷贝重新在堆区重新创建空间，注意如果类中用到了指针，就需要深拷贝
*
#pragma once
================================================================*/

#include<iostream>
using namespace std;
class Person
{
public:
	int m_A;
	int m_B;
	int m_C;
	//初始化列表方式初始化,构造函数
	Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c)
	{

	}
};
void test01()
{
	Person p(10, 20, 10000);
	cout << p.m_A <<" "<< p.m_B <<" " << p.m_C;
}
int main()
{
	test01();
	Person p2;
	return 0;
}