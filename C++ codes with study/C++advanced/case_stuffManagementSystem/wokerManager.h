//.h  头文件中只需要写上函数声明即可，不需要具体实现

#pragma once       //防止头文件重复包含
#include<iostream> //包含输入输出流头文件
using namespace std;//使用标准命名空间
#include"worker.h"
#define FILENAME "empFile.txt"


//只是把方法封装到类里面啦，免得主函数页面过于繁琐，真正抽象出来的类还是员工类，他们有共同的特性！
class WorkerManager{
public:
    WorkerManager();

    //展示函数
    void Show_Menu();

    //退出系统
    void exitSystem();

    //增加职工
    void addWorker();

    //查看是否已有相同的员工编号
    bool IsRepeat(int id );

    //保存文件
    void save();

    //判断文件是否为空
    bool m_FileIsEmpty;

    //统计文件中人数
    int get_EmpNum();

    //初始化员工
    void init_Emp();

    //显示职工
    void show_Emp();

    //删除职工
    void del_Emp();

    //判断职工是否存在
    int ISEXist(int id);

    //修改员工信息
    void Mod_Emp();

    //查找职工
    void Find_Emp();

    //按照职工编号排序
    void Sort_Emp();

    //清空文件实现
    void Clean_File();

    ~WorkerManager();
    
    //员工总数
    int m_EmpNum;
    //保存员工指针的数组，即指针的指针
    Worker ** m_EmpArray;    /*考虑到用指针来存放各个员工，需要一个数组来存放这些指针，数组本身
                        即可用数组表示，那么接收这个指针数组的指针就属于指针的指针*/
    // ofstream ofs;
// private:
//     string m_Name;
//     int m_Num;   //又出现面向过程的毛病了，  普通员工、经理、老板都有很多相同的特性，他们身上可以抽离出形成一个类
//     int m_P;
};
