/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：quicksort.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：2021年03月02日
*   描    述：快速排序。
*
#pragma once
================================================================*/
#include <iostream>
#include "printarr.h"
using namespace std;

void QuickSort(int arr[], int left, int right)
{
    if (arr == NULL)
    {
        return;
    }
    if (left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    int key = arr[left];
    while (1)
    {
        while (arr[++i] < key)
        {
            if (i == right)
            {
                break;
            }
        }
        while (arr[--j] > key)
        {
            if (j == left)
            {
                break;
            }
        }
        if (i >= j)
        {
            break;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    arr[left] = arr[j];
    arr[j] = key;
    QuickSort(arr, left, j - 1);
    QuickSort(arr, j + 1, right);
}

int main()
{
    int sort_array[10] = {2, 4, 1, 5, 0, 8, 6, 9, 3, 7};
    PrintArr(sort_array, "快速排序前数组sort_array为：");
    QuickSort(sort_array, 0, 9);
    PrintArr(sort_array, "快速排序后数组sort_array为：");
    return 0;
}
