/*================================================================once
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：static.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：20231年02月06日
*   描    述：静态变量，静态函数
*
#pragma once
================================================================*/
#include <iostream>
using namespace std;
// 如果一个类中什么都没有会占用1个字节空间
class Water
{
public:
	Water();
	~Water();

private:
};

Water::Water()
{
	cout << "Water构造函数调用" << endl;
}

Water::~Water()
{
	cout << "Water析构函数调用" << endl;
}
// 如果一个类中有东西就不需要占用之前那1个字节空间，会占用实际空间
// 但是static变量不属于类对象上，所以不占用对象的空间
class Tea
{
public:
	Tea();
	~Tea();
	// 只有非静态成员变量才属于类上
	int m_A; // int占用4个字节

	// 静态变量：static变量不属于类对象上, 类内声明类外初始化
	// 1.所有对象都共享统一数据
	// 2.编译阶段就分配内存
	// 3.类内声明，类外初始化操作
	static int m_B;

	// 函数也不属于类对象上
	void func();

	// 静态函数
	// 1.所有对象共享一个同一个函数
	// 2.静态成员函数只能访问静态成员变量
	static void func02()
	{
		// cout << m_A << endl; // 不能访问非静态成员变量
		// cout << this->m_B << endl; // this只能用于非静态函数
		cout << m_B << endl;
		cout << "静态函数调用" << endl;
	}

private:
	// 静态变量一样都访问权限
	static int m_C;
	// 静态函数一样有访问权限，类外不能访问静态成员函数
	static void func03()
	{
	}
};
int Tea::m_B = 100;
int Tea::m_C = 99;

Tea::Tea()
{
	cout << "Tea构造函数调用" << endl;
}

Tea::~Tea()
{
	cout << "Tea析构函数调用" << endl;
}

void test01()
{
	Water p;
	// 编译器会为每个空对象也分配一个字节，是为了区分空对象占内存的位置
	cout << "Water 空对象占用的空间为：" << sizeof(p) << endl;
}
void test02()
{
	Tea p;
	// 如果类中有数据，
	cout << "Tea 对象占用的空间为：" << sizeof(p) << endl;
}

// 静态变量一改都改，不存在某个对象上，所有对象共享一份数据
void test03()
{
	Tea p1;
	cout << "p1的static为" << p1.m_B << endl;
	Tea p2(p1);
	cout << "p2的static为" << p2.m_B << endl;
	// 可以看到如果吧p2的改了p1的也会改变
	p2.m_B = 200;
	cout << "p2的static更改之后" << endl;
	cout << "p1的static为" << p1.m_B << endl;
	cout << "p2的static为" << p2.m_B << endl;
	// 可以看到如果吧p2的改了p1的也会改变
}
// 静态对象的两种访问方式
void test04()
{
	// 通过对象访问
	Tea p;
	cout << "通过对象访问静态变量: " << p.m_B << endl;
	// 通过类名访问
	cout << "通过类名访问静态变量: " << Tea::m_B << endl;
	// private m_C 在类外不可访问
	// cout << p.m_C << endl;
}

// 静态函数的两种访问方式
void test05()
{
	Tea p;

	// 通过对象访问
	cout << "通过对象访问静态函数: ";
	p.func02();

	// 通过类名访问
	cout << "通过类名访问静态函数: ";
	Tea::func02();

	// 类外无法访问private
	// p.func2()；
}
//Water w 声明为静态的,就算test06函数结束之后,静态对象w也会存在,指到运行完程序
void test06()
{
	Tea t;
	static Water w;
	cout << "test06结束" << endl;
}

int main()
{
	//如果对象被声明为static
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	Tea t;
	return 0;
}