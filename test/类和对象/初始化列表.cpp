/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：初始化列表.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：20231年02月05日
*   描    述：初始化列表，静态变量，静态函数
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
	Person()
	{

	}
	//初始化列表方式初始化,构造函数
	Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c)
	{

	}
	//静态变量
	//1.所有对象都共享统一数据
	//2.编译阶段就分配内存
	//3.类内声明，类外甥初始化操作
	static int m_D;
	//静态函数
	//1.所有对象共享一个同一个函数
	//2.静态成员函数只能访问静态成员变量
	static void func()
	{
		//cout << m_A << endl;//不能访问非静态成员变量
		cout << m_E << endl;
		cout << "静态函数调用" << endl;
	}
private:
	//静态变量一样都访问权限
	static int m_E;
	//静态函数一样有访问权限，类外不能访问静态成员函数
	static void func2()
	{
	}
};
int Person::m_D = 400;
int Person::m_E = 500;

//初始化列表方式初始化
void test01()
{
	Person p(10, 20, 300);
	cout << p.m_A <<" "<< p.m_B <<" " << p.m_C;

}

//静态变量一改都改，不存在某个对象上，所有对象共享一份数据
void test02()
{
	Person p1;
	cout << p1.m_D << endl;
	Person p2(p1);
	cout << p2.m_D << endl;
	//可以看到如果吧p2的改了p1的也会改变
	p2.m_D = 200;
	cout << p1.m_D << endl;
	cout << p2.m_D << endl;
}

//静态对象的两种访问方式
void test03()
{
	//通过对象访问
	Person p;
	cout << p.m_D << endl;
	//通过类名访问
	cout << Person::m_D << endl;
	//private m_E 在类外不可访问
	//cout << p.m_E << endl;
}

//静态函数的两种访问方式
void test04()
{
	//通过对象访问
	Person p;
	p.func();
	//通过类名访问
	Person::func();
	//类外无法访问private
	//p.func2()；
}

int main()
{
	test04();
	return 0;
}