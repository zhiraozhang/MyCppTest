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

    cout << "线程结束1。" << endl;
    cout << "线程结束2。" << endl;
    cout << "线程结束3。" << endl;
    cout << "线程结束4。" << endl;
    cout << "线程结束5。" << endl;
    cout << "线程结束5。" << endl;
    cout << "线程结束7。" << endl;
    cout << "线程结束8。" << endl;
}
int main()
{
    cout << "主线程开始。" << endl;
    thread th(MyPrint);
    //th.join();
    th.detach();
    cout << "主线程结束1。" << endl;
    cout << "主线程结束2。" << endl;
    cout << "主线程结束3。" << endl;
    cout << "主线程结束4。" << endl;
    cout << "主线程结束5。" << endl;
    return 0;
}