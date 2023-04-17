
#include "circle.h" 

//.h 头文件中的一切都是用来声明的，包括成员属性和成员方法  .cpp文件中放具体的实现


//圆类

//设置半径
void Circle::setR(int r){
    m_R = r;
}
//获取半径
int Circle::getR(){
    return m_R;
}
//设置圆心
void Circle::setCenter(Point &Center){    //最开始我写的这个哈哈哈void setCenter(int x, int y) 
    // m_Center.setX(x);
    // m_Center.setY(y);
    m_Center = Center;
}
//获取圆心
Point Circle::getCenter(){
    return m_Center;
}
string Circle::relation(Point &p){
    if((m_Center.getX() - p.getX())*(m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY())*(m_Center.getY() - p.getY()) == m_R*m_R){
        return "点在圆上";
    }else if((m_Center.getX() - p.getX())*(m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY())*(m_Center.getY() - p.getY()) < m_R*m_R){
        return "点在圆内";
    }else{
        return "点在圆外";
    }
}
