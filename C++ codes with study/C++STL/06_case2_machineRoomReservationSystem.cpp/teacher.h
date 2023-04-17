#include"identity.h"
//创建教师类

#ifndef _TEACHER_H_
#define _TEACHER_H_

class Teacher: public Identity{
public:
    //默认构造
    Teacher();

    //构造函数   姓名、职工编号、密码
    Teacher(string name, int id, string pwd);

    //菜单界面
    virtual void operMenu();

    //查看所有预约
    void showAllOrder();

    //审核预约
    void validOrder();

    int m_EmpId; //教师编号
};

#endif