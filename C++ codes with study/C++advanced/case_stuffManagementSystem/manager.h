#pragma once
#include"worker.h"  //其实在worker.h头文件中包含了 其他几个头文件和标准空间的话，在这里就只用包含这个头文件就行了，其他空间不用定义了
#include<iostream>
using namespace std;

//经理类
class Manager: public Worker{
public:
    Manager(int Id, string name, int DeptId); //构造函数，给属性赋值

    virtual void showInfo(); //显示个人信息 , 子类处virtual可写可不写

    virtual string getDeptName(); //显示岗位名称

};