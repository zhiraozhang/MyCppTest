#include <iostream>
// 1.包含头文件
#include <fstream>
#include <string>
using namespace std;
void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    ofs << "测试！" << endl;
    ofs.close();
}
void test02()
{
    // 2.创建对象
    ifstream ifs;
    // 3.打开并且判断是否打开
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    // 4.读数据
    // 第一种
    char buf[1024] = {0};
    while (ifs >> buf)
    {
        cout << buf << endl;
    }
    // // 第二种
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
    // 第三种
    // string buf;
    // while (getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }
    // 第四种EOF=end of file
    // char c;
    // while ((c = ifs.get()) != EOF)
    // {
    //     cout << c;
    // }

    // 5.关闭文件
    ifs.close();
}
int main()
{
    test01();
    test02();
    return 0;
}