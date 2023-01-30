#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

// �漰��ϵ�˽ṹ�� �������Ա����䡢�绰��סַ
struct Person
{
	string m_Name;
	int m_Sex; // 1���У�2��Ů
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
	cout << "*****ͨѶ¼����ϵͳv1.0****" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbooks *abs)
{
	// �Ƿ���
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else
	{
		// ��Ӿ�����ϵ��
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		int sex = -1;
		cout << "�������Ա�\t1--��\t2--Ů" << endl;
		while (true)
		{
			// �������1��2���������У�������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		int age = -1;
		cout << "���������䣺" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		string phone;
		cout << "������绰��" << endl;
		while (true)
		{
			cin >> phone;
			if (phone.length() == 11)
			{
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;

		// ����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls"); // ����
	}
}

// ��ʾ���е���ϵ��
void showPerson(Addressbooks *abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��û����ϵ���أ��½�һ���ɣ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}

// �����ϵ���Ƿ���ڣ�������ڷ�����ϵ��������λ�ã������ڷ���-1
int isExist(Addressbooks *abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1; // ������
}

// ɾ����ϵ��
void deletePerson(Addressbooks *abs)
{
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) // �鵽��
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		// while (ret < abs->m_Size)
		//{
		//	abs->personArray[ret] = abs->personArray[ret + 1];
		//	ret++;
		// }
		abs->m_Size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

// ������ϵ��
void findPerson(Addressbooks *abs)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) // �鵽��
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "��ַ��" << abs->personArray[ret].m_Address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

// �޸���ϵ��
void modifyPerson(Addressbooks *abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) // �鵽��
	{
		// �޸ľ�����ϵ��
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = -1;
		cout << "�������Ա�\t1--��\t2--Ů" << endl;
		while (true)
		{
			// �������1��2���������У�������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		int age = -1;
		cout << "���������䣺" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		string phone;
		cout << "������绰��" << endl;
		while (true)
		{
			cin >> phone;
			if (phone.length() == 11)
			{
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		string address;
		cout << "�������ַ��" << endl;
		cin >> address;
		abs->personArray[ret].m_Address = address;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

// �����ϵ��
void clearPerson(Addressbooks *abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	// ����ͨѶ¼
	Addressbooks abs;
	// ��ʼ����ǰͨѶ¼��Ա����
	abs.m_Size = 0;

	int select = 0; // �û�����ı���

	while (true)
	{
		// �˵�����
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:				 // ���
			addPerson(&abs); // ���õ�ַ���ݣ���������ʵ��
			break;
		case 2: // ��ʾ
			showPerson(&abs);
			break;
		case 3: // ɾ��
			deletePerson(&abs);
			break;
		case 4: // ����
			findPerson(&abs);
			break;
		case 5: // �޸�
			modifyPerson(&abs);
			break;
		case 6: // ���
			clearPerson(&abs);
			break;
		case 0: // �˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}

	system("pause");
	return 0;
}
