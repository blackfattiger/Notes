#pragma once
#include<iostream>
using namespace std;

//创建身份抽象基类
class Identity{
public:
    //操作菜单  不管哪一类人员都有这一接口
    virtual void operMenu() = 0; //声明中 添加 = 0 才是 纯虚函数

    string m_Name;//姓名
    string m_Password;//密码
};