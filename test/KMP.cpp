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
void getNext(const char *ano, int next[])
{
    int ano_len = strlen(ano);
    next[0] = -1;
    int i = 0, j = -1;
    while (i < ano_len)
    {
        if (j == -1 || ano[i] == ano[j])
        {
            i++;
            j++;
            if (i < ano_len) next[i] = j;//防止数组下标越界
        } else j = next[j];
    }
    cout << "next数组为:";
    for (int k = 0; k < ano_len; ++k)
    {
        cout << next[k] + 1 << " ";//书中都是从1开始,但是程序中是以程序下标0开始,所以和书中数据差1
    }
    cout << endl;
}

int KMP(const char *mas_str, const char *ano_str)
{
    int mas_len = strlen(mas_str);
    int ano_len = strlen(ano_str);

    if (mas_len < ano_len) return -1;//主串长度少于匹配串

    int *next = new int[ano_len];
    getNext(ano_str, next);
    int i = 0, j = 0;
    while (i < mas_len && j < ano_len)
    {
        // 匹配：则匹配下一个；直到有一个字符串走完
        // 不匹配：回退模式串的j指针，回退到模式串当前最长匹配字符串的位置。如果还不匹配则继续回退。
        if (j == -1 || mas_str[i] == ano_str[j])
        {
            i++;
            j++;
        } else
        {
            j = next[j];
        }
    }
    //delete[] next;
    //j走完证明匹配上了，返回位置。否则就是失败
    if (j >= ano_len)
        return i - j;
    else
        return -1;
}

int main()
{
    const char *master_string = "abbaaaabbaabaaaabababaaababaabaabaabbaaba";
    const char *another_string = "ababaaababaa";
    cout << "KMP! Start!" << endl;
    int kmp_return = KMP(master_string, another_string);
    if (kmp_return == -1) cout << "false" << endl;
    else cout << "在第几个位置起匹配:" << kmp_return << endl;
    //delete master_string;
    //delete another_string;
    //system("pause");
    return 0;
}