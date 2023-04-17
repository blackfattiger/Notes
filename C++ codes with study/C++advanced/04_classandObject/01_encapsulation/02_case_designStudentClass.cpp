



#include <iostream>
using namespace std;

class Student{
public: //公共权限

//类中的属性和行为 我们统一称为 成员
//属性： 成员变量 成员属性
//行为： 成员函数 成员方法
    //属性
    int m_Num;  //学号
    string m_Name;  //姓名

    //行为
    //显示学号与姓名
    void show(){
        cout<<"学号是： "<<m_Num<<endl;
        cout<<"姓名是： "<<m_Name<<endl;
    }
    //还可以通过行为给属性赋值
    //给姓名赋值
    void setName(string name){
        m_Name = name;
    }
    //给学号赋值
    void setNum(int num){
        m_Num = num;
    }


};


int main(){
    Student stu1;
    // stu1.m_Num = 1;
    stu1.setNum(1);
    // stu1.m_Name = "张三";
    stu1.setName("张三");
    //可以发现通过行为给属性赋值与直接给属性赋值效果是一样的，往后就会体会到其作用
    stu1.show();

    return 0;
}