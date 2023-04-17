// 练习案例2：点和圆的关系
// 设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。

// 重点：
//1.一个类中可以包含其他的类作为成员变量
//2.如何分文件编写，拆开写为.h与.cpp文件，方便项目管理


#include <iostream>
using namespace std;
#include "point.h"
#include "circle.h"
// //点类
// class Point{
// private:
//     int m_X;  //X坐标
//     int m_Y;  //Y坐标

// public:
//     //设置X坐标
//     void setX(int x){
//         m_X = x;
//     }
//     //获取X坐标
//     int getX(){
//         return m_X;
//     }
//     //设置Y坐标
//     void setY(int y){
//         m_Y = y;
//     }
//      //获取Y坐标
//     int getY(){
//         return m_Y;
//     }
// };

// //圆类
// class Circle
// {
// private:
//     int m_R;//半径
//     //此为该案例的核心点，即可以用另外的类充当本类中的成员
//     Point m_Center;//圆心

// public:
//     //设置半径
//     void setR(int r){
//         m_R = r;
//     }
//     //获取半径
//     int getR(){
//         return m_R;
//     }
//     //设置圆心
//     void setCenter(Point &Center){    //最开始我写的这个哈哈哈void setCenter(int x, int y) 
//         // m_Center.setX(x);
//         // m_Center.setY(y);
//         m_Center = Center;
//     }
//     //获取圆心
//     Point getCenter(){
//         return m_Center;
//     }
//     string relation(Point &p){
//         if((m_Center.getX() - p.getX())*(m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY())*(m_Center.getY() - p.getY()) == m_R*m_R){
//             return "点在圆上";
//         }else if((m_Center.getX() - p.getX())*(m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY())*(m_Center.getY() - p.getY()) < m_R*m_R){
//             return "点在圆内";
//         }else{
//             return "点在圆外";
//         }
//     }

// };





int main(){
    //创建圆对象
    Circle c;
    c.setR(10);
    //创建圆心对象
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);
    //创建点对象
    Point p;
    p.setX(10);
    p.setY(10);
    cout<<c.relation(p)<<endl;

    return 0;
}