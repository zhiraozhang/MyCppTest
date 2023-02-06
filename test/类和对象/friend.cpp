/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：friend.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：20231年02月05日
*   描    述：友元
*
#pragma once
================================================================*/
//友元的三种实现
//全局函数做友元
//类做友元
//成员函数做友元 friend GoodGuy::visit02();
#include<iostream>
#include<string>
using namespace std;
class GoodGuy;//预引用之后可以在friend后面不加class
class Building
{
	friend void gooGuy();
	friend GoodGuy;
public:
	Building();
	~Building();

private:
	string m_SittingRoom;
	string m_BedRoom;
};

Building::Building()
{
	this->m_SittingRoom = " 客厅";
	m_BedRoom = "卧室";
}

Building::~Building()
{
}

void gooGuy()
{
	Building b1;
	 //如果不加友元不可访问private变量
	cout << "好基友函数正在访问："<< b1.m_SittingRoom << b1.m_BedRoom << endl;

}
class GoodGuy
{
	friend Building;
public:
	GoodGuy();
	~GoodGuy();
	void visit();

private:
	Building* building;
};

GoodGuy::GoodGuy()
{
	building=new Building;
}

GoodGuy::~GoodGuy()
{
	delete building;

}
void GoodGuy::visit()
{
	cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
	//在GoodGuy里加友元Building之后可以访问Building的私有变量
	cout << "好基友类正在访问：" << building->m_BedRoom << endl;
}
void test01()
{
	GoodGuy gg;
	gg.visit();
}
int main()
{
	//gooGuy();
	test01();
	return 0;
}