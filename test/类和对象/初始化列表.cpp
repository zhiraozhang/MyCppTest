/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：初始化列表.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：20231年02月05日
*   描    述：初始化列表
#pragma once
================================================================*/

#include <iostream>
using namespace std;
class Person
{
public:
	int m_A;
	int m_B;
	int m_C;
	Person()
	{
	}
	// 初始化列表方式初始化,构造函数
	Person(int a, int b, int c) : m_A(a), m_B(b), m_C(c)
	{
	}

private:
};

// 初始化列表方式初始化
void test01()
{
	Person p(10, 20, 300);
	cout << p.m_A << " " << p.m_B << " " << p.m_C;
}

int main()
{
	test04();
	return 0;
}