/**
 * @file MyArray.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
using namespace std;

template <class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        cout << "参数构造函数调用" << endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->pAddress = new T[this->m_capacity];
    }
    MyArray(const MyArray<T> &arr)
    {
        cout << "拷贝构造函数调用" << endl;
        // 有数据则释放
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
        // 深拷贝
        this->m_size = arr.m_size;
        this->m_capacity = arr.m_capacity;
        this->pAddress = new T[arr.m_capacity];
        for (size_t i = 0; i < arr.m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    ~MyArray()
    {
        cout << "析构函数调用" << endl;
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }
    MyArray<T> &operator=(const MyArray &arr)
    {
        cout << "operator=函数调用" << endl;
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
        this->m_size = arr.m_size;
        this->m_capacity = arr.m_capacity;
        this->pAddress = new T[arr.m_capacity];
        for (size_t i = 0; i < arr.m_size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

private:
    int m_size;
    int m_capacity;
    T *pAddress = NULL;
};

void test01()
{
    MyArray<int> arr01(10);
    MyArray<int> arr02(arr01);
    MyArray<int> arr03(20);
    arr03 = arr01;
}

int main()
{
    test01();
    return 0;
}