/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：inherit.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：2021年01月28日
*   描    述：继承的学习,一文件流
*
#pragma once
================================================================*/
#include<iostream>
#include<string>
using namespace std;
class animal//基类
{
private:
    int pri_age;
public:
    int age;
    string name;
    string voice;
    animal()
    {
        cout << "---animal start---" << endl;
    }
    ~animal()
    {
        cout << "---animal close---" << endl;
    }
protected:
    int pro_age;
};
class dog : public animal
{
public:
    int age;
    string name;
    string voice;
    dog(string inputName,int inputAge)
    {
        cout << "---dog    start---" << endl;
        voice = "woo~woo~";
        name = inputName;
        age = inputAge;
    }
    ~dog()
    {
        cout << "---dog    close---" << endl;
    }
};
class human : public animal
{
private :
    int age;
    string name;
    int weigh;
public:
    enum sex
    {
        man,
        woman
    };
    int high = NULL;

    human()
    {
        cout << "---human  start---" << endl;
        age = 1;
    }
    ~human()
    {
        cout << "---human  close---" << endl;
    }

    void setName(string inputName)
    {
        name = inputName;
    }
    string getName()
    {
        return name;
    }
};
int main1()
{
    cout << "---程序  start!---" << endl;
    //堆中分配
    cout << "堆中分配 start!" << endl;
    human* zhang=new human;
    zhang->setName("三");
    cout << "张" << zhang->getName() << endl;
    delete zhang;
    dog* hashiqi = new dog("哈士奇",1);
    cout << "他家养了条" << hashiqi->name << endl;
    delete hashiqi;
    cout << "------------------" << endl;
    //栈中分配
    cout << "栈中分配 start!" << endl;
    human wang;
    wang.setName("五");
    cout << "王" << wang.getName() << endl;
    dog jinmao("金毛",2);
    cout << "他家养了条" << jinmao.name << endl;
    cout << "---程序  close!---" << endl;
    return 0;
}
