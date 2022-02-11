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
//#include "string.h"

using namespace std;

// 求next数组是不需要主字符串的，只需要匹配字符串
// 说白了，next[]数组求的是匹配字符串的最大匹配数
void getNext(const char *str, int *next)
{
    int str_len = strlen(str);
    int pre = 1, post = 1;
    while (pre < str_len)
    {
        if (post == -1 || str[pre] == str[post])
        {
            pre++;
            post++;
            next[pre] = post;
        } else post = next[post];
    }
}

int KMP(const char *mas_str, const char *ano_str)
{
    int mas_len = strlen(mas_str), ano_len = strlen(ano_str);
    if (mas_len < ano_len) return -1;
    int i = 0, j = 0;
    int *next = new int[ano_len];
    getNext(ano_str, next);
    while (i < mas_len && j < ano_len)
    {
        // 匹配：则匹配下一个；直到有一个字符串走完
        // 不匹配：回退匹配字符串的j指针，回退到匹配字符串当前最长匹配字符串的位置。如果还不匹配则继续回退。
        if (j == 1 || mas_str[i] == ano_str[j])
        {
            i++;
            j++;
        } else j = next[j];
    }
    //j走完证明匹配上了，返回位置。否则就是失败
    if (j > ano_len) return i - j;
    else return -1;
}

int main()
{
    const char *master_string = "abbaabbaaba";
    const char *another_string = "abbaaba";
    //cout << "KMP! Start!：" << endl;
    //cin >> master_string >> another_string;
    int kmp_number = KMP(master_string, another_string);
    if (kmp_number == -1) cout << "匹配失败" << endl;
    else cout << "匹配成功，位置：" << kmp_number << endl;
    delete master_string, another_string;
    system("pause");
    return 0;
}