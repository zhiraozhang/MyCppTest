/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：LinkListTest.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：2021年01月28日
*   描    述：链表
*
#pragma once
================================================================*/
#include<iostream>
using namespace std;

//定义
typedef struct LNode
{
	int data;
	LNode* next;
}*LinkList;
//无论是头插法还是尾插法都会有一个什么呢？都会有一个头节点
//头插法
LinkList HeadInsert(LinkList& L);
//尾插法
LinkList TailInsert(LinkList& L);
//打印链表
void PrintLinkList(LinkList L);
//获取第i位的值
LinkList GetElem(LinkList L, int i=3);

int main2() 
{
	try
	{
		LinkList List1= new LNode;		// == LNode* List1 = new LNode;
		LNode* List2 = new LNode;
		//测试头插法
		HeadInsert(List1);
		PrintLinkList(List1);
		//测试尾插法
		TailInsert(List2);
		PrintLinkList(List2);
		//GetElem(List1);
		return 0;
	}
	catch (const std::exception&)
	{
		cout << "ouch!" << endl;
	}

}
//头插法
LinkList HeadInsert(LinkList& L)
{
	cout << "头插法启动，请输入值：（输入9999结束）";
	int x;
	cin >> x;
	L->next = NULL;
	while (x != 9999) 
	{
		LNode* s = new LNode;
		s->data = x;
		s->next = L->next;
		L->next = s;
		cout << "请输入下一个值: ";
		cin >> x;
	}
	return L;
}
//尾插法
LinkList TailInsert(LinkList& L)
{
	int x;
	LNode* Tail = L;
	cout << "尾插法启动，请输入值：（输入9999结束）";
	cin >> x;
	while (x != 9999) {
		LinkList s = new LNode;
		s->data = x;
		s->next = NULL;
		Tail->next = s;
		Tail = s;
		cout << "请输入下一个值: ";
		cin >> x;
	}
	Tail->next = NULL;
	return L;
}
//打印链表
void PrintLinkList(LinkList L)
{
	try
	{
		cout << "链表的数据为:";
		while (L->next)
		{
			cout << L->next->data << "->";
			L->next = L->next->next;
		}
		cout <<"NULL"<< endl;
	}
	catch (const exception&)
	{
		cout << "haha";
	}

}
//按序号查找节点值
LinkList GetElem(LinkList L, int i)
{
	if (i < 0)return NULL;
	while (L && i > 0) {
		L = L->next;
		i--;
	}
	if (L != NULL) {
		cout <<"值为"<< L->data;
		return L;
	}
	else {
		cout << "不存在" << endl;
		return NULL;
	}
	return L;
}
