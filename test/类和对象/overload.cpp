#include <iostream>
using namespace std;

class Person
{
private:
public:
	Person(){};
	Person(int a, int b) : m_A(a), m_B(b){};
	~Person();
	int m_A;
	int m_B;
};

Person::~Person()
{
}

// 运算符重载
// 加法，加减乘除类似
Person operator+(const Person &p1, const Person &p2) // 全局函数的重载 传两个参数
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

// 左移运算符
// 重载<<时，&Person不加const会报错，why？
ostream &operator<<(ostream &cout, const Person &p)
{
	cout << p.m_A << endl;
	cout << p.m_B << endl;
	return cout;
}

// 递增运算符
// 前置递增返回引用
Person &operator++(Person &p)
{
	p.m_A += 1;
	p.m_B += 1;
	return p;
}
// 前置递增局部函数
//  Person &operator++()
//  {
//  	p.m_A += 1;
//  	p.m_B += 1;
//  	return p;
//  }
//  int代表占位参数，用于区分前置和后置
//  后置递增返回值
Person operator++(Person &p, int)
{
	Person temp = p;
	p.m_A += 1;
	p.m_B += 1;
	return temp;
}

void test01()
{
	Person p1(10, 40), p2(20, 80), p3;
	p3 = p1 + p2;
	cout << p3 << endl;
	cout << p1 + p2 + p3 << endl;
}

void test02()
{
	Person p1(0, 0);
	cout << ++p1 << p1++ << endl;
	cout << p1 << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}