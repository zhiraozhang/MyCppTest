#include <iostream>
using namespace std;

class CPU
{
public:
    virtual void caculate() = 0;
};

class VidioCard
{
public:
    virtual void display() = 0;
};

class Memory
{
public:
    virtual void storage() = 0;
};

class InterCPU : public CPU
{
private:
    /* data */
public:
    void caculate()
    {
        cout << "InterCPU正常！" << endl;
    }
};

class AMDVidioCard : public VidioCard
{
private:
    /* data */
public:
    void display()
    {
        cout << "AMD显卡正常！" << endl;
    }
};

class SumsungMemory : public Memory
{
private:
    /* data */
public:
    void storage()
    {
        cout << "Sumsung内存正常！" << endl;
    }
};

class Computer
{
public:
    Computer(CPU *cpu, VidioCard *vc, Memory *mm)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mm = mm;
    }
    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        if (m_mm != NULL)
        {
            delete m_mm;
            m_mm = NULL;
        }
    }
    void work()
    {
        m_cpu->caculate();
        m_vc->display();
        m_mm->storage();
        cout << "电脑开始工作" << endl;
    }

private:
    CPU *m_cpu;
    VidioCard *m_vc;
    Memory *m_mm;
};
void test01()
{
    CPU *cpu = new InterCPU;
    VidioCard *vc = new AMDVidioCard;
    Memory *mm = new SumsungMemory;
    Computer *c1 = new Computer(cpu, vc, mm);
    c1->work();
    delete c1;
    c1 = NULL;
}
int main()
{
    test01();
    return 0;
}