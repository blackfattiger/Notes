#include "point.h"
#include<iostream>


//point.cpp中只需要留住函数的实现,属性也不需要留下了


//设置X坐标
void Point::setX(int x){    //Point::  是指在Point这个类的作用域下，用于表明这些都是Point这个类的成员方法和成员变量
    m_X = x;
}
//获取X坐标
int Point::getX(){
    return m_X;
}
//设置Y坐标
void Point::setY(int y){
    m_Y = y;
}
    //获取Y坐标
int Point::getY(){
    return m_Y;
}