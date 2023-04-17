// 练习案例1：设计立方体类
// 设计立方体类(Cube)
// 求出立方体的面积和体积
// 分别用全局函数和成员函数判断两个立方体是否相等。


#include <iostream>
using namespace std;

class Cube{
private:

    int m_L;//长
    int m_W;//宽
    int m_H;//高

public:
    //设置长度
    void setL(int length){
        m_L = length;
    }
    //获取长度
    int getL(){
        return m_L;
    }
    //设置宽度
    void setW(int width){
        m_W = width;
    }
    //获取宽度
    int getW(){
        return m_W;
    }
    //设置高度
    void setH(int height){
        m_H = height;
    }
    //获取高度
    int getH(){
        return m_H;
    }
    //获取立方体面积
    int calculateS(){
        return 2*(m_H * m_L + m_H * m_W + m_L * m_W);
    }
    //获取立方体体积
    int calculateV(){
        return m_H * m_L *m_W;
    }

    bool isSameinClass(Cube &c){  //成员函数只需要传入一个立方体即可比较，因为成员函数可以直接获取调用这个函数的对象本身的属性，只需要获取要和其比较的立方体对象即可
        int ret = 0;
        if(m_H == c.getH() && m_L == c.getL() && m_W == c.getW()) ret = 1;
        return ret;
    }


};

//利用全局变量判断两个立方体是否相等  ，  全局函数需要传入两个立方体才能比较
bool isSame(Cube &c1, Cube &c2){              //一开始我想的是传入两个立方体的面积或者体积bool isSame(int a, int b)，没有想过可以直接传入立方体对象
    int ret = 0; 
    if(c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW()) ret = 1;
    return ret;
}

int main(){
    //创建立方体对象
    Cube c1;
    c1.setH(10);
    c1.setL(10);
    c1.setW(10);
    cout<<"c1的面积为："<<c1.calculateS()<<endl;
    cout<<"c1的体积为："<<c1.calculateV()<<endl;

    Cube c2;
    c2.setH(10);
    c2.setL(10);
    c2.setW(10);
    cout<<"c2的面积为："<<c2.calculateS()<<endl;
    cout<<"c2的体积为："<<c2.calculateV()<<endl;

    //利用全局函数判断
    bool ret = isSame(c1,c2);
    if(ret == 1){
        cout<<"c1与c2相同"<<endl;
    }else{
        cout<<"c1与c2不同"<<endl;
    }

    //利用成员函数判断
    ret = c1.isSameinClass(c2);
    if(ret == 1){
        cout<<"成员函数判断： c1与c2相同"<<endl; 
    }else{
        cout<<"成员函数判断：c1与c2不同"<<endl;
    }

    return 0;
}