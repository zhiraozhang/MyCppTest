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
#include "printarr.h"
using namespace std;

void BubbleSort(int sort[])
{
    int k = 0;
    for (int j = 9; j >= 0; j--) //第一轮，bsort[9]是最大的，接下来找第二大的放到bsort[8]里
    {
        for (int i = 0; i < j; i++) //两两比较，把最大的数放到最后
        {
            if (sort[i] > sort[i + 1])
            {
                k = sort[i];
                sort[i] = sort[i + 1];
                sort[i + 1] = k;
            }
        }
    }
}

int main()
{
    int sort_array[10] = {2, 4, 1, 5, 0, 8, 6, 9, 3, 7};
    PrintArr(sort_array, "冒泡排序前数组sort_array为：");
    BubbleSort(sort_array);
    PrintArr(sort_array, "冒泡排序后数组sort_array为：");
    return 0;
}
