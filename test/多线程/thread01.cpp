/**
 * @file thread01.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-03-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <thread>
using namespace std;
void MyPrint()
{
    cout << "线程开始。" << endl;

    for (size_t i = 0; i < 100; i++)
    {
        cout << "线程结束：" << i << endl;
    }
}
int main()
{
    cout << "主线程开始。" << endl;
    thread th(MyPrint);
    th.join();
    // th.detach();
    for (size_t i = 0; i < 100; i++)
    {
        cout << "主线程结束：" << i << endl;
    }
    return 0;
}