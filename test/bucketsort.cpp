/*================================================================
*     Copyright (c) 2022年 SherlockZhang. All rights reserved.
*
*   文件名称：bucketlesort.cpp
*   创 建 者：SherlockZhang
*   邮    箱：SherlockZhang@aliyun.com
*   创建日期：2021年11月4日
*   描    述：桶排序，标记出现的次数,时间复杂O(M+N),浪费空间
*
#pragma once
================================================================*/
#include <iostream>

void BucketSort(int sort[])
{
    int bucket[11] = {0};
    for (int i = 0; i < 10; i++)
    {
        bucket[sort[i]]++;
    }
    for (int i = 0; i < 11; i++)
    {
        for (; bucket[i] > 0; bucket[i]--)
        {
            std::cout << i << " ";
        }
    }
}
int main()
{
    int sort_array[10] = {2, 4, 1, 5, 0, 8, 6, 2, 10, 7};
    for (int i = 0; i < 10; i++)
    {
        std::cout << sort_array[i] << " ";
    }
    std::cout << std::endl;
    BucketSort(sort_array);
    return 0;
}