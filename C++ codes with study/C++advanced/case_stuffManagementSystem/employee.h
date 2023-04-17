#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

//普通员工文件
class Employee: public Worker{
public:
    Employee(int Id, string name, int DeptId); //构造函数，给属性赋值

    virtual void showInfo(); //显示个人信息 , 子类处virtual可写可不写

    virtual string getDeptName(); //显示岗位名称

};