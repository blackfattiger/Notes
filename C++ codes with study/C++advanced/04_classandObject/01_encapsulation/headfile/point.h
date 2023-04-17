#pragma once
#include<iostream>


//头文件中不需要函数的具体实现，只需要留住声明即可

//点类
class Point{
private:
    int m_X;  //X坐标
    int m_Y;  //Y坐标

public:
    //设置X坐标
    void setX(int x);
    //获取X坐标
    int getX();
    //设置Y坐标
    void setY(int y);
     //获取Y坐标
    int getY();
};
