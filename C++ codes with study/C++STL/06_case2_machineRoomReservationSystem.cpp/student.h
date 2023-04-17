#include"identity.h"
#include"computerRoom.h"
#include<vector>
//创建学生类
//具有整体架构思维：先把架子搭出来，然后再去想办法填充内容

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student: public Identity{
public:
    Student();
    //构造函数  姓名、学号、密码
    Student(string name, int id, string pwd);
    //菜单界面
    virtual void operMenu();
    //申请预约
    void applyOrder();
    //查看我的预约
    void showMyOrder();
    //查看所有预约
    void showAllOrder();
    //取消预约
    void cancelOrder();

    int m_Id; //学号

    //机房信息
    vector<computerRoom> vCom;
};

#endif