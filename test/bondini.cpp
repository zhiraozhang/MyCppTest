/*================================================================
*     Copyright (c) 2022�� SherlockZhang. All rights reserved.
*
*   �ļ����ƣ�bondini.cpp
*   �� �� �ߣ�SherlockZhang
*   ��    �䣺SherlockZhang@aliyun.com
*   �������ڣ�2021��11��6��
*   ��    ����ת��
*
#pragma once
================================================================*/
#include<iostream>
int main()
{
	using namespace std;
	cout << "\aOpeeration \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code:______\b\b\b\b\b\b";//\b�ǻ��˹�꣬�˴�����˵��»��߿�ͷ
	long code;
	cin >> code;
	cout << "\aYou entered " << code << "...\n";//\a�����壬���ǵ��Է�����ʾ��
	cout << "\aCode verified! Proceed with Plan Z3!\n";
	return 0;
}
//int main()
//{
//	using namespace std;
//	cout << "Opeeration \"HyperHype\" is now activated!\n";
//	cout << "Enter your agent code:______\b\b\b\b\b\b";
//	long code;
//	cin >> code;
//	cout << "You entered " << code << "...\n";
//	cout << "Code verified! Proceed with Plan Z3!\n";
//	return 0;
//}