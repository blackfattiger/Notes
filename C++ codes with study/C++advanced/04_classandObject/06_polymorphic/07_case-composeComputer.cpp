// 4.7.6 多态案例三-电脑组装
// 案例描述：
// 电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）
// 将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商
// 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
// 测试时组装三台不同的电脑进行工作

#include<iostream>
using namespace std;

//抽象CPU类
class CPU{
public:
    //抽象计算类
    virtual void calculator() = 0;
};

//抽象显卡类
class Graphic{
public:
    //抽象显示类
    virtual void display() = 0;
};

//抽象内存条类
class Memory{
public:
    //抽象存储类  
    virtual void storage() = 0;
};

//Intel厂商的零件实现
class IntelCPU: public CPU{
public:
    void calculator(){
        cout<<"IntelCPU开始计算了！"<<endl;
    }
};

class IntelGraphics: public Graphic{
public:
    void display(){
        cout<<"IntelGraphics开始显示了！"<<endl;
    }
};

class IntelMemory: public Memory{
public:
    void storage(){
        cout<<"IntelMemory开始存储了！"<<endl;
    }
};

//Lenovo厂商的零件实现
class LenovoCPU: public CPU{
public:
    void calculator(){
        cout<<"LenovoCPU开始计算了！"<<endl;
    }
};

class LenovoGraphics: public Graphic{
public:
    void display(){
        cout<<"LenovoGraphics开始显示了！"<<endl;
    }
};

class LenovoMemory: public Memory{
public:
    void storage(){
        cout<<"LenovoMemory开始存储了！"<<endl;
    }
};

//电脑类  可以用这一个类组装三台不同的电脑
class Computer{  //:public IntelCPU, public IntelGraphics, public IntelMemory 开始自己写的时候写了继承
public:
    //构造函数内提供三个零件指针,抽象类不能实例化，所以用指针传入
    Computer(CPU * cpu, Graphic * gpu, Memory * m){
        m_cpu = cpu;
        m_gpu = gpu;
        m_m = m;
    }
    //提供工作函数
    void doWork(){
        //让零件工作起来，调用接口
        m_cpu->calculator();
        m_gpu->display();
        m_m->storage();
        // delete m_cpu;
        // delete m_gpu;
        // delete m_m;   写在析构函数里面
    }
    ~Computer(){
        if(m_cpu != NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        if(m_gpu != NULL){
            delete m_gpu;
            m_gpu = NULL;
        }
        if(m_m != NULL){
            delete m_m;
            m_m = NULL;
        }
    }
// public:
private:
    CPU * m_cpu;
    Graphic * m_gpu;
    Memory *  m_m;
};

void test01(){
    //组装第一台Intel电脑
//    computer ic(new IntelCPU, new IntelGraphics, new IntelMemory);
//老师用的指针
    Computer * Intelcomputer = new Computer(new IntelCPU, new IntelGraphics, new IntelMemory);
    Intelcomputer->doWork();
    delete Intelcomputer;
    cout<<"------------------------"<<endl;
    //组装第二台Lenovo电脑
    Computer * Lenovecomputer  = new Computer(new LenovoCPU, new LenovoGraphics, new LenovoMemory);
    Lenovecomputer->doWork();
    delete Lenovecomputer;
    cout<<"------------------------"<<endl;
    //组装第三台混合电脑
    Computer * Mixcomputer  = new Computer(new LenovoCPU, new IntelGraphics, new LenovoMemory);
    Mixcomputer->doWork();
    delete Mixcomputer;
}

int main(){
    test01();


    return 0;
}