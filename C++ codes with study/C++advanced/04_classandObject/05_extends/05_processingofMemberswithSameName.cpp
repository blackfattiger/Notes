// 4.6.5 继承同名成员处理方式
// 问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？
// 访问子类同名成员 直接访问即可
// 访问父类同名成员 需要加作用域

// 总结：
// 1. 子类对象可以直接访问到子类中同名成员
// 2. 子类对象加作用域可以访问到父类同名成员
// 3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数

#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        m_A = 100;
    }
    void func(){
        cout<<"Base - func()调用"<<endl;
    }
     void func(int a){
        cout<<"Base - func(int a)调用"<<endl;
    }
public:
    int m_A;
};

class Son : public Base{
public:
    Son(){
        m_A = 200;
    }
    void func(){
        cout<<"Son - func()调用"<<endl;
    }
public:
    int m_A; //= 200;
};

//同名成员属性处理
void test01(){
    Son s;
    cout<<"Son下的m_A = "<<s.m_A<<endl;
    //如果通过子类对象，需要访问到父类中的 同名 成员，需要加上作用域
    cout<<"Base下的m_A = "<<s.Base::m_A<<endl;
}

//同名成员函数处理
void test02(){
    Son s;
    s.func(); //直接调用，调用的是子类中的同名成员
    //如何调用父类的成员函数？
    s.Base::func(); //加上作用域，调用父类中的同名成员
    
    //如果子类中出现和父类同名的成员函数，那么子类的同名成员函数就会隐藏掉父类中的所有成员函数
    //即时是父类中重载的同名函数也不能直接访问到，如果想访问被隐藏的同名成员函数，需要加作用域
    // s.func(100);
    s.Base::func(100);
}

int main(){
    test01();
    test02();
    return 0;
}