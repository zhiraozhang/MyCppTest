/**
 * @file linklist.cpp
 * @author SherlockZhang@aliyun.com
 * @brief 链表
 * @version 0.1
 * @date 2022-01-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <iostream>

typedef int DataType;
using namespace std;

// 定义一个链表结构体，LNode是一个节点。LinkList是一个节点的首地址指针？
typedef struct LNode
{
    DataType data;
    LNode *next;
} *LinkList;

// 头插法
LinkList HeadInsert(LinkList L)
{
    cout << "头插法启动，请输入值：（输入9999结束）";
    int x;
    cin >> x;
    L->next = NULL;
    while (x != 9999)
    {
        LinkList s = new LNode; // 存疑，LNode怎么用LinkList替换？
        s->data = x;
        s->next = L->next;
        L->next = s;
        cout << "请输入下一个值: ";
        cin >> x;
    }
    return L;
}

// 尾插法
LNode *TailInsert(LNode *L)
{
    int x;
    LNode *Tail = L;
    cout << "尾插法启动，请输入值：（输入9999结束）";
    cin >> x;
    while (x != 9999)
    {
        LNode *s = new LNode;
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

// 打印链表
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
        cout << "NULL" << endl;
    }
    catch (const exception &)
    {
        cout << "haha";
    }
}

// 按序号查找节点值
LinkList GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    while (L && i > 0)
    {
        L = L->next;
        i--;
    }
    if (L != NULL)
    {
        cout << "值为" << L->data;
        return L;
    }
    else
    {
        cout << "不存在" << endl;
        return NULL;
    }
    return L;
}

int main()
{
    try
    {
        LNode *List1 = new LNode; // == LNode* List1 = new LNode;
        LNode *List2 = new LNode;
        // 测试头插法
        HeadInsert(List1);
        PrintLinkList(List1);
        // 测试尾插法
        TailInsert(List2);
        PrintLinkList(List2);
        // GetElem(List1);
        return 0;
    }
    catch (const std::exception &)
    {
        cout << "ouch!" << endl;
    }
}