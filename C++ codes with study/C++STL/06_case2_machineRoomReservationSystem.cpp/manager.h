#include"identity.h"
#include"student.h"
#include"teacher.h"
#include<vector>
#include"computerRoom.h"

#ifndef _MANAGER_H_
#define _MANAGER_H_

//管理员类
class Manager: public Identity{
public:
    //默认构造
    Manager();

    //有参构造
    Manager(string name, string pwd);

    //显示菜单
    virtual void operMenu();

    //添加账号
    void addPerson();

    //查看账号  
    void showPerson();

    //查看机房信息
    void showComputer();

    //清空预约记录
    void cleanFile();

    //初始化容器
    void initVector();

    //检测重复   参数1 检测学号/教师号  参数2 检测类型
    bool checkRepeat(int id, int type);

    // //打印学生信息
    // void printStudent(Student & s);

    // //打印教师信息
    // void printTeacher(Teacher & t);

    //学生信息
    vector<Student> vStu;
    
    //教师信息
    vector<Teacher> vTea;

    //机房信息
    vector<computerRoom> vCom;
};

#endif