/**
 * @file template.cpp
 * @author SherlockZhang3 (SherlockZhang@aliyun.com)
 * @brief 模板分为函数模板和类模板，可以统一使用class T
 * @version 0.1
 * @date 2023-02-26
 *
 * @copyright Copyright (c) 2023
 *
 */
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
	int a = 1;
	int b = 2;
	Swap(a, b);
	cout << a << " " << b << endl;

	// 类模板
	Student<int, double> st1("Lily", "female", 25.06, 170.05);
	Student<double, int> st2("Sam", "male", 22.03, 182.20);
	Student<double, int> *st3 = new Student<double, int>("Jack", "male", 22.50, 177);
	st1.PrintStu();
	st2.PrintStu();
	st3->PrintStu();
	delete st3;
	st3 = NULL;

	// 可变参数模板
	Printargs(a, b);
	Printargs(a, a, a, b);
	return 0;
}