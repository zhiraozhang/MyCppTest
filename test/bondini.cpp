/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：bondini.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：2021年11月6日
*   描    述：转义
*
#pragma once
================================================================*/
#include<iostream>
int main()
{
	using namespace std;
	cout << "\aOpeeration \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code:______\b\b\b\b\b\b";//\b是回退光标，此处会回退到下划线开头
	long code;
	cin >> code;
	cout << "\aYou entered " << code << "...\n";//\a是振铃，就是电脑发出提示音
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