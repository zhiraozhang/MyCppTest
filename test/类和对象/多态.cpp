#include <iostream>
using namespace std;

// 1.虚函数
class Animal
{
public:
	// 如果不加virtual，静态多态，地址早绑定，编译阶段确定函数地址。在doSpeak时，传入猫的对象但是会被转化成动物的对象。
	// 加上virtual，动态多态，地址晚绑定，运行阶段确定函数地址。

	// 如果不加virtual,Animal一个空类只占1个字节，但是如果是虚函数Animal会占用4个字节。

	// void speak()
	virtual void speak()
	{
		cout << "动物在说话！" << endl;
	}
};
class Cat : public Animal
{
	// 子类在重写的时候virtual可写可不写
	void speak()
	{
		cout << "小猫在说话。" << endl;
	}
};
// 父类的指针或引用指向子类对象，若是值传递，就算是虚函数也会调用Animal的函数，因为相当于创建一个Animal对象
void doSpeak(Animal &a)
{
	a.speak();
}

void test01()
{
	Cat c;
	doSpeak(c);
}

// 2.纯虚函数抽象类
// 一个类中只要有纯虚函数，这个类就是抽象类
// 特点如下：
// 无法实例化对象
// 子类必须要重写抽象类中的纯虚函数，否则也属于抽象类

// 重载：函数名相同，参数不一样
// 重写：返回值、函数名、形参列表要一致
class AbstractAnimal
{
public:
	AbstractAnimal(){};
	// 纯虚函数，后面=0就行
	virtual void speak() = 0;
};
class Dog : public AbstractAnimal
{
public:
	void speak()
	{
		cout << "小狗在说话！" << endl;
	}
};
void doSpeak(AbstractAnimal &a)
{
	a.speak();
}
void test02()
{
	// 尝试抽象类创建对象,报错
	// AbstractAnimal a1;
	// AbstractAnimal *a2 = new AbstractAnimal;

	// 但是，可以用子类实例化抽象类对象，这样就可以在一个函数中传入父类的参数列表，实际传入子类的形参。
	AbstractAnimal *a3 = new Dog;
	a3->speak();
	doSpeak(*a3);
	delete a3;
}
int main()
{
	test01();
	test02();
	return 0;
}