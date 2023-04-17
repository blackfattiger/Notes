// 4.6.6 继承同名静态成员处理方式
// 问题：继承中同名的静态成员在子类对象上如何进行访问？
// 静态成员和非静态成员出现同名的处理方式一致
// 访问子类同名成员 直接访问即可
// 访问父类同名成员 需要加作用域

#include <iostream>
using namespace std;
//静态成员属性，类内声明，类外定义，类外之所以需要给一个类似于int的数据类型，是因为在函数体外只能定义变量或创建对象，不能执行语句操作 
class Base{
public:
    static int m_A;
    static void func(){
        cout<<"Base的静态函数"<<endl;
    }
    static void func(int a ){
        cout<<"Base的静态函数 int a "<<endl;
    }
};
int Base::m_A = 100;

class Son: public Base{
public:
    static int m_A;
    static void func(){
        cout<<"Son的静态函数"<<endl;
    }
};
int Son::m_A = 200;

//同名静态成员属性
void test01(){
    //通过对象访问
    cout<<"通过对象访问"<<endl;
    Son s;
    cout<<"Son 下的 m_A = "<<s.m_A<<endl;
    //第一个::表示通过类名的方式访问，  第二个::表示访问父类作用域下的
    cout<<"Base 下的m_A = "<<s.Base::m_A<<endl;

    //静态成员需要通过类名访问，而从类名访问需要作用域来访问  语法是  类名::成员   而不是  类名.成员
    cout<<"通过类名访问"<<endl;
    cout<<"Son 下的 m_A = "<<Son::m_A<<endl;
    cout<<"Base 下的m_A = "<<Son::Base::m_A<<endl;
    
}

//同名静态成员函数
void test02(){
    //通过对象访问
    cout<<"通过对象访问"<<endl;
    Son s;
    s.func();
    s.Base::func();

    //通过类名访问
    cout<<"通过类名访问"<<endl;
    Son::func();
    Son::Base::func();

    //子类出现和父类同名的静态成员函数，也会隐藏父类中所有同名成员函数
    //如果子类想访问父类中被隐藏的同名成员，需要加作用域
    // Son::func(100);
    Son::Base::func(100);
}

int main(){
    test01();
    test02();
    return 0;
}