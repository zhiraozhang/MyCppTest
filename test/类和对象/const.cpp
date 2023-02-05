//const 修饰成员函数
//常函数：
//成员函数 后面 加const后我们称之为常函数
//常函数不可以修改成员属性
//成员属性声明时加关键字mutable，在场函数中依然可以修改
//常对象：
//声明对象前加const为常对象
//常对象只能调用常函数
#include<iostream>
using namespace std;
class Person
{
public:
	//this指针的本质 是指针常量  Person * const this
	//如果不让修改指针的指向 就需要 const Person * const this === 函数后面加const
	//在成员函数后面加const修饰的是this指向，指针的值也不能更改
	void showPerson() //const
	{
		this->m_A = 100;
	}

	int m_A;
	mutable int m_B;//可修改
};