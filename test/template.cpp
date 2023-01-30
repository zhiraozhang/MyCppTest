/*================================================================
*     Copyright (c) 2022�� SherlockZhang. All rights reserved.
*
*   �ļ����ƣ�template.cpp
*   �� �� �ߣ�SherlockZhang
*   ��    �䣺SherlockZhang@aliyun.com
*   �������ڣ�20231��01��30��
*   ��    ����ģ���Ϊ����ģ�����ģ��
*
#pragma once
================================================================*/

#include<iostream>
using namespace std;

//����ģ��
template<typename T0>
void Swap(T0& left, T0& right)
{
	T0 temp = left;
	left = right;
	right = temp;
}

template<class T1,class T2>
class Student
{
public:
	Student(const string& name, const string& sex, const T1& age, const T2& height)
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

int main()
{
	//����ģ��
	int a = 33;
	int b = 22;
	Swap(a, b);
	//��ģ��
	Student<int, double> st1("Lily", "female", 25.06, 170.05);
	//Student<double, int> st2 = new Student<double, int>("Sam", "male", 22.00, 182.00);
	Student<double, int> st2("Sam","male",22.03,182.20);
	st1.PrintStu();
	st2.PrintStu();
	return 0;
}