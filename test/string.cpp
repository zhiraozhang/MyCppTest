/*================================================================
*     Copyright (c) 2022�� SherlockZhang. All rights reserved.
*
*   �ļ����ƣ�string.cpp
*   �� �� �ߣ�SherlockZhang
*   ��    �䣺SherlockZhang@aliyun.com
*   �������ڣ�2022��11��6��
*   ��    ����string��
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
	std::cout << R"+*(\a \n ��R"()"���治�ᱻת��)+*";
	//����C����ַ���ʹ��strcpy strcat������������cstringͷ�ļ��
	//��һ�ж�ȡ��string���棬getline(cin,str}
}