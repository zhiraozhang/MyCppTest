/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：bubblesort.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：2021年02月23日
*   描    述：冒泡排序，其实应该说是反冒泡排序，把最大的数沉到后方。
*
#pragma once
================================================================*/
#include <iostream>
using namespace std;

void bubble(int bsort[])
{
    int k = 0;
    for (int j = 9; j >= 0; j--)    //第一轮，bsort[9]是最大的，接下来找第二大的放到bsort[8]里
    {
        for (int i = 0; i < j; i++) //两两比较，把最大的数放到最后
        {
            if (bsort[i] > bsort[i + 1])
            {
                k = bsort[i];
                bsort[i] = bsort[i + 1];
                bsort[i + 1] = k;
            }
        }
    }
}
void coutsort(int sort[],string text)
{
    cout << text;
    for (int i = 0; i < 10; i++)
    {
        cout << sort[i] << " ";
    }
    cout << endl;
}

int main()
{
    int sort[10] = {2, 4, 1, 5, 0, 8, 6, 9, 3, 7};
    coutsort(sort,"冒泡排序前数组sort为");
    bubble(sort);
    coutsort(sort,"冒泡排序后数组sort为");
    return 0;
}
