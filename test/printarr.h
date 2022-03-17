#pragma once
#include <iostream>

void PrintSherlock()
{
    std::cout << std::endl;
}

void PrintArr(int arr[], std::string text)
{
    std::cout << text;
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}