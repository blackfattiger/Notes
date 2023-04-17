// 封装意义二：类在设计时，可以把属性和行为放在不同的权限下，加以控制
// 访问权限有三种：
// 1. public 公共权限
// 2. protected 保护权限
// 3. private 私有权限

#include <iostream>
using namespace std;

//访问权限
//三种
//公共权限 public       成员 类内可以访问 类外也可以访问
//保护权限 protected    成员 类内可以访问 类外不可以访问
//私有权限 private      成员 类内可以访问 类外不可以访问
//保护权限与私有权限之间的区别在学习继承时可以体会到（继承时，子类可以访问父类的保护权限，但不能访问父类的私有权限）
class Person{
public://姓名 公共权限
    string m_Name;
protected://汽车  保护权限
    string m_Car;
private://银行卡密码 私有权限
    int m_Password;

};

int main(){
    Person p;
    p.m_Name = "李四";
    //p.m_Car = "奔驰"; //保护权限类外访问不到
    //p.m_Password = 123; //私有权限类外访问不到
    system("pause");


    return 0;
}