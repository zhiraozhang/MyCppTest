#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<size_t> vec;
    size_t i;
    // 显示vec原始大小
    cout << "vector size = " << vec.size() << endl;
    for (i = 0; i < 5; i++)
    {
        vec.push_back(rand());
    }
    cout << "vector size = " << vec.size() << endl;
    // 访问向量中的 5 个值
    for (i = 0; i < 5; i++)
    {
        cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }
    // 三种遍历方式
    // while
    // for
    // for_each
    //  使用迭代器 iterator 访问值，vec.begin()启示迭代器，指向第一个元素。vec.end()结束迭代器，指向容器中最后一个元素的下一个位置
    vector<size_t>::iterator v = vec.begin();
    while (v != vec.end())
    {
        cout << "value of v = " << *v << endl;
        v++;
    }

    return 0;
}