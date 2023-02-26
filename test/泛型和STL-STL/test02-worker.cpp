/**
 * @file test02-worker.cpp
 * @author SherlockZhang@aliyun.com
 * @brief
 * @version 0.1
 * @date 2023-02-26
 *
 * @copyright Copyright (c) 2023
 *
 * 10个员工（ABCDEFGHIJ）
 * 员工信息：姓名，薪资，部门（策划，美术，研发）
 * 随机分配部门和薪资
 * multimap进行信息插入部门编号和员工
 * 分部门显示员工信息
 * 实现步骤：
 * 1.创建10名员工放入vector
 * 2.遍历vector，取出每个员工随机分组到multimap
 * 3.分部门显示信息
 */

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
using namespace std;

class Worker
{
public:
    int m_Salary;
    string m_Name;
};

void createWorker(vector<Worker> &w)
{
    for (size_t i = 0; i < 10; i++)
    {
        string nameSeed = "ABCDEFGHIJ";
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];
        worker.m_Salary = rand() % 10000 + 10000; // 10000~19999
        w.push_back(worker);
    }
}
void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator i = v.begin(); i != v.end(); i++)
    {
        int deptId = rand() % 3;
        m.insert(make_pair(deptId, *i));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m)
{
    cout << "策划部门：" << endl;
    // 由于是有序排序，所以pos指向的是第一个策划人员
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA); // 统计策划人数
    // for 策划人数个次数
    for (size_t index = 0; index < count && pos != m.end(); pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "，薪资为：" << pos->second.m_Salary << endl;
    }

    cout << "美术部门：" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    for (size_t index = 0; index < count && pos != m.end(); pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "，薪资为：" << pos->second.m_Salary << endl;
    }

    cout << "研发部门：" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    for (size_t index = 0; index < count && pos != m.end(); index++)
    {
        cout << "姓名：" << pos->second.m_Name << "，薪资为：" << pos->second.m_Salary << endl;
        pos++;
    }
}

int main()
{
    // 用法:
    //     它初始化随机种子，会提供一个种子，这个种子会对应一个随机数，如果使用相同的种子后面的 rand() 函数会出现一样的随机数，如 : srand(1);
    //     直接使用 1 来初始化种子。不过为了防止随机数每次重复，常常使用系统时间来初始化，即使用 time函数来获得系统时间，它的返回值为从 00 : 00 : 00 GMT, January 1, 1970 到现在所持续的秒数，然后将time_t型数据转化为(unsigned) 型再传给srand函数，即 : srand((unsigned)time(&t));
    //     还有一个经常用法，不需要定义time_t型t变量, 即 : srand((unsigned)time(NULL));
    //     直接传入一个空指针，因为你的程序中往往并不需要经过参数获得的数据。
    // 进一步说明下：计算机并不能产生真正的随机数，而是已经编写好的一些无规则排列的数字存储在电脑里，把这些数字划分为若干相等的N份，并为每份加上一个编号用srand() 函数获取这个编号，然后rand() 就按顺序获取这些数字，当srand() 的参数值固定的时候，rand() 获得的数也是固定的，所以一般srand的参数用time(NULL)，因为系统的时间一直在变，所以rand() 获得的数，也就一直在变，相当于是随机数了。只要用户或第三方不设置随机种子，那么在默认情况下随机种子来自系统时钟。如果想在一个程序中生成随机数序列，需要至多在生成随机数之前设置一次随机种子。
    // 即：只需在主程序开始处调用 srand((unsigned)time(NULL)); 后面直接用rand就可以了。不要在 for 等循环放置 srand((unsigned)time(NULL));
    srand((unsigned int)time(NULL));
    // 创建员工
    vector<Worker> w;
    createWorker(w);
    for (vector<Worker>::iterator it = w.begin(); it < w.end(); it++)
    {
        cout << "name = " << it->m_Name << ", salary = " << it->m_Salary << endl;
    }
    // 分组
    multimap<int, Worker> mw;
    setGroup(w, mw);
    showWorkerByGroup(mw);

    return 0;
}