#pragma once
#include<iostream>
using namespace std;

//职工抽象类
//这个抽象类并不需要实现，所以并不需要针对此类创建.cpp文件
class Worker{
public:
    virtual void showInfo() = 0; //显示个人信息

    virtual string getDeptName() = 0; //显示岗位名称

    int m_Id; //职工编号
    string m_Name;//职工姓名
    int m_DeptId;//职工所在部门编号
};
