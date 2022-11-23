/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：string.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：2022年11月6日
*   描    述：string类
*
#pragma once
================================================================*/
#include<iostream>
#include<string>
int main()
{
	std::string str1, str2, str3;
	str1 = { "Let's go!" };
	str2 = { "\aPikachu!\n"};
	str3 = str1 + str2;
	std::cout << str3;
	std::cout << R"+*(\a \n 在R"()"里面不会被转义)+*";
	//对于C风格字符串使用strcpy strcat函数，包含在cstring头文件里。
	//将一行读取到string里面，getline(cin,str}
	char a[3] = { 0,1,2 };
	std::cout << &a[0] << a[1] << std::endl;
	return 0;
}