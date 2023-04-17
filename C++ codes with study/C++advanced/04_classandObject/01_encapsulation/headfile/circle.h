#pragma once
#include <iostream>
using namespace std;
#include "point.h"

//.h 头文件中的一切都是用来声明的，包括成员属性和成员方法  .cpp文件中放具体的实现

//圆类
class Circle
{
private:
    int m_R;//半径
    //此为该案例的核心点，即可以用另外的类充当本类中的成员
    Point m_Center;//圆心

public:
    //设置半径
    void setR(int r);
    //获取半径
    int getR();
    //设置圆心
    void setCenter(Point &Center);
    //获取圆心
    Point getCenter();
    string relation(Point &p);

};