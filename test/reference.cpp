#include<iostream>
#include<string>

using namespace std;

int main()
{
    int hello(int i, string);
    int hello(int *i, string);
    int search1(int i);
    void search2(int &i);

    int he = 1;
    int *s = &he;
    hello(s, "he的地址为：");
    search1(he);
    hello(he, "he的值为：");
    search2(he);//search2形参是实参的引用，所以实参会变化，search1
    hello(he, "he的值为：");

    cout << "上海就是浦东，浦东就是上海！" << endl;
    int a, b = 1;
    int *p = &a;
    int *q = &b, *r = NULL;

    hello(p, "a的地址为：");
    hello(q, "b的地址为：");
    int &c = b;    //c是b的引用
    hello(c, "c的值为：");//此处c的地址是b，所以上海就是浦东，浦东就是上海
    b++;
    hello(c, "b+1后c的值为：");
    r = &c;
    hello(q, "b的地址为：");
    hello(r, "c的地址为：");//甚至于b和c的地址都是一样的
    return 0;
}

int hello(int i, string j)
{
    cout << j << i << endl;
    return 0;
}

int hello(int *i, string j)
{
    cout << j << i << endl;
    return 0;
}

int search1(int i)
{
    cout << "search1启动" << endl;
    ++i;
    int *p = &i;
    hello(p, "search1之后i的地址为");
    cout << "search1结束" << endl;
    return 0;
}

void search2(int &i)
{
    cout << "search2启动(引用)" << endl;
    ++i;
    int *p = &i;
    hello(p, "search2之后i的地址为");
    cout << "search2结束" << endl;
}