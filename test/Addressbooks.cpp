#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

//涉及联系人结构体 姓名、性别、年龄、电话、住址
struct Person
{
	string m_Name;
	int m_Sex;//1：男，2：女
	int m_Age;
	string m_Phone;
	string m_Address;
};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu()
{
	cout << "*****通讯录管理系统v1.0****" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbooks* abs)
{
	//是否满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
	}
	else
	{
		//添加具体联系人
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex = -1;
		cout << "请输入性别：\t1--男\t2--女" << endl;
		while (true)
		{
			//如果输入1或2，正常进行，否则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		int age = -1;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		string phone;
		cout << "请输入电话：" << endl;
		while (true)
		{
			cin >> phone;
			if (phone.length() == 11)
			{
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");//清屏
	}
}

//显示所有的联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "还没有联系人呢，新建一个吧！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "地址：" << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，如果存在返回联系人数组中位置，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;//不存在
}

//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//查到了
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//while (ret < abs->m_Size)
		//{
		//	abs->personArray[ret] = abs->personArray[ret + 1];
		//	ret++;
		//}
		abs->m_Size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//查到了
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "地址：" << abs->personArray[ret].m_Address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//查到了
	{
		//修改具体联系人
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = -1;
		cout << "请输入性别：\t1--男\t2--女" << endl;
		while (true)
		{
			//如果输入1或2，正常进行，否则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		int age = -1;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		string phone;
		cout << "请输入电话：" << endl;
		while (true)
		{
			cin >> phone;
			if (phone.length() == 11)
			{
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Address = address;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//创建通讯录
	Addressbooks abs;
	//初始化当前通讯录人员个数
	abs.m_Size = 0;

	int select = 0;//用户输入的变量

	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://添加
			addPerson(&abs);//利用地址传递，可以修饰实参
			break;
		case 2://显示
			showPerson(&abs);
			break;
		case 3://删除
			deletePerson(&abs);
			break;
		case 4://查找
			findPerson(&abs);
			break;
		case 5://修改
			modifyPerson(&abs);
			break;
		case 6://清空
			clearPerson(&abs);
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}

	system("pause");
	return 0;
}
