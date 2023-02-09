#include <iostream>
using namespace std;

class Person
{
private:
public:
	int m_A;
	int m_B;
	int *m_C = NULL;
	Person(){};
	Person(int a, int b) : m_A(a), m_B(b){};
	Person(int c)
	{
		m_C = new int(c);
	}
	~Person()
	{
		if (m_C != NULL)
		{
			delete m_C;
			m_C = NULL;
		}
	};

	// 重载赋值运算符
	Person &operator=(const Person &p)
	{
		m_A = p.m_A;
		m_B = p.m_B;
		if (p.m_C == NULL)
		{
			m_C = NULL;
		}
		else
		{
			if (m_C != NULL)
			{
				delete m_C;
				m_C = NULL;
			}
			m_C = new int(*p.m_C);
		}

		return *this;
	}
};

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
	if (p.m_C != NULL)
	{
		cout << p.m_A << endl;
		cout << p.m_B << endl;
		cout << *p.m_C << endl;
	}
	else
	{
		cout << p.m_A << endl;
		cout << p.m_B << endl;
		cout << "m_C为NULL" << endl;
	}
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
	cout << "test01!" << endl;
	Person p1(10, 40), p2(20, 80), p3;
	p3 = (p1 + p2);
	cout << p3 << endl;
	cout << p1 + p2 + p3 << endl;
}

void test02()
{
	cout << "test02!" << endl;
	Person p1(0, 0);
	cout << ++p1 << p1++ << endl;
	cout << p1 << endl;
}
void test03()
{
	cout << "test03!" << endl;
	Person p1(10), p2(20), p3(30);
	p1 = p2;
	p1 = p2 = p3;
	cout << p1 << endl;
}
int main()
{
	test01();
	test02();
	test03();
	return 0;
}