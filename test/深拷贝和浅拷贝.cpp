/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：深拷贝和浅拷贝.cpp
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
	Person()
	{
		cout << "无参构造函数调用。" << endl;
	}
	Person(int age)
	{
		m_Age = age;
		cout << "有参构造函数调用。" << endl;
	}
	Person(int age, int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "有参构造函数02调用。" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		m_Height = new int(*p.m_Height);
		cout << "拷贝构造函数调用。" << endl;
	}
	~Person()
	{
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "析构函数调用。" << endl;
	}
	int m_Age;
	int* m_Height;
};
void test(int* &s)
{
	Person p1(13, 170);
	cout << "p1年龄为" << p1.m_Age << "，p1身高为：" << *p1.m_Height << endl;
	Person p2(p1);
	cout << "p2年龄为" << p2.m_Age << "，p2身高为：" << *p2.m_Height << endl;
	cout << "p1的m_Height：" << p1.m_Height << "，p2的m_Height：" << p2.m_Height << endl;
	s = p2.m_Height;
}
int main()
{
	int* s=NULL;
	test(s);
	cout << *s << endl;
	return 0;
}