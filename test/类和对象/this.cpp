#include<iostream>
using namespace std;

//this
//this指向被调用成员函数 所属的对象
//返回对象本身用*this
class Person02
{
public:
	Person02(int age)
	{
	//this指向被调用成员函数 所属的对象
		//this->age = age;
		(*this).age = age;
	}
	//如果下面函数不加引用的话，每次返回都会返回一个新的对象。
	//加上引用才会返回p2本函数
	Person02& PersonAddAge(Person02 &p)
	{
		this->age += p.age;
		return *this;
	}


	int age;
};
void test03()
{
	Person02 p1(10);
	cout << p1.age << endl;
	Person02 p2(10);
	//p2.PersonAddAge(p1);
	//cout << p2.age << endl;
	//链式编程思想
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
	cout << p2.age << endl;
}

class Person03
{
public:
	void getPersonAge(int age)
	{
		if (this == NULL)
		{
			return;
		}
		this->m_age = age; 
}
	void showPersonAge()
	{
		if (this == NULL)
		{
			return;
		}
		cout << m_age << endl;
	}
	void noThisShowPersonAge()
	{
		cout << "空指针也能调用成员函数" << endl;
	}
private:
	int m_age;
};
void test04()
{
	Person03* p=new Person03;
	p->getPersonAge(10);
	p->showPersonAge();
	Person03* p2 = NULL;
	//空指针也能访问
	p2->noThisShowPersonAge();
}
int main()
{
	test04();
	return 0;
}