/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：KMP.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：2021年02月11日
*   描    述：KMP算法
*
#pragma once
================================================================*/
#include <iostream>
#include <cstring>

using namespace std;

// 求next数组是不需要主字符串的，只需要匹配字符串
// 说白了，next[]数组求的是匹配字符串的最大匹配数
void getNext(const char *str, int next[])
{
    int str_len = strlen(str);
    next[0] = -1;
    int i = 0, j = -1;
    while (i < str_len)
    {
        if (j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            next[i] = j;
        } else j = next[j];
    }
    //cout << "next : " << next << endl;
}

int KMP(const char *s, const char *t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (s_len < t_len) return -1;//主串长度少于匹配串

    int *next = new int[t_len];
    getNext(t, next);
    int i = 0, j = 0;
    while (i < s_len && j < t_len)
    {
        // 匹配：则匹配下一个；直到有一个字符串走完
        // 不匹配：回退模式串的j指针，回退到模式串当前最长匹配字符串的位置。如果还不匹配则继续回退。
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        } 
        else
        {
            j = next[j];
        }
    }
    //delete[] next;
    //j走完证明匹配上了，返回位置。否则就是失败
    if (j >= t_len)
        return i - j;
    else
        return -1;
}

int main()
{
    char *master_string = "abbaaabbaaba";
    char *another_string = "abbaaba";
    cout << "KMP!";
    //cout << "KMP! Start!：" << endl;
    //cin >> master_string >> another_string;
    int kmp_return = KMP(master_string, another_string);
    if (kmp_return == -1) cout << "false" << endl;
    else cout << "123" << kmp_return << endl;
    delete master_string;
    delete another_string;
    system("pause");
    return 0;
}