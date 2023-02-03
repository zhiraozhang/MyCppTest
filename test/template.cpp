/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：template.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：20231年01月30日
*   描    述：模板分为函数模板和类模板
*
#pragma once
================================================================*/

#include <iostream>
using namespace std;

// 函数模板
template <typename T0>
void Swap(T0 &left, T0 &right)
{
	T0 temp = left;
	left = right;
	right = temp;
}

// 类模板
template <class T1, class T2>
class Student
{
public:
	Student(const string &name, const string &sex, const T1 &age, const T2 &height)
	{
		_name = name;
		_sex = sex;
		_age = age;
		_height = height;
	}
	void PrintStu()
	{
		cout << _name << " " << _sex << " " << _age << " " << _height << endl;
	}

private:
	string _name;
	string _sex;
	T1 _age;
	T2 _height;
};

// 可变模版参数
template <class... T3>
void Printargs(T3... args)
{
	cout << sizeof...(args) << endl; // 打印变参的个数
}

int main()
{
	// 函数模板
	int a = 33;
	int b = 22;
	Swap(a, b);
	// 类模板
	Student<int, double> st1("Lily", "female", 25.06, 170.05);
	// Student<double, int> st2 = new Student<double, int>("Sam", "male", 22.00, 182.00);
	Student<double, int> st2("Sam", "male", 22.03, 182.20);
	st1.PrintStu();
	st2.PrintStu();
	return 0;
}