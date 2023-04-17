// 4.5 运算符重载
// 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
// 4.5.1 加号运算符重载
// 作用：实现两个 自定义 数据类型 相加的运算


// 总结1：对于内置的数据类型的表达式的的运算符是不可能改变的
// 总结2：不要滥用运算符重载


#include <iostream>
using namespace std;

class Person{
public:
    // 1.成员函数重载+号     
    // Person operator+(Person &p){
    //     Person temp;
    //     temp.m_A = this->m_A + p.m_A; //this即指向调用它这个成员函数的对象，所以只用传入一个Person对象
    //     temp.m_B = this->m_B + p.m_B;
    //     return temp;
    // }

public:
    int m_A;
    int m_B;
};

// 2.全局函数重载+号
Person operator+(Person &p1, Person &p2){ //全局函数没有成员函数的特性，所以需要传入两个对象才能完成加法运算
    Person temp;
    temp.m_A = p1.m_A + p2.m_B;
    temp.m_B = p1.m_B + p2.m_B;
    return temp;
}

// 3.函数重载的版本
Person operator+(Person &p, int num){
    Person temp;
    temp.m_A = p.m_A + num;
    temp.m_B = p.m_B + num;
    return temp;
}


void test01(){
    Person p1;
    Person p2;
    p1.m_A = 10;
    p1.m_B = 10;
    p2.m_A = 10;
    p2.m_B = 10;
    //成员函数重载本质调用
    // Person p3 = p1.operator+(p2);
    
    //全局函数重载本质调用
    // Person p3 = operator+(p1,p2);

    Person p3 = p1 + p2;
    cout<<"p3.m_A = "<<p3.m_A<<endl;
    cout<<"p3.m_B = "<<p3.m_B<<endl;

    //运算符重载 也可以发生函数重载
    Person p4 = p1 +100;  //  Person + int
    cout<<"p4.m_A = "<<p4.m_A<<endl;
    cout<<"p4.m_B = "<<p4.m_B<<endl;
}

int main(){
    test01();


    return 0;
}