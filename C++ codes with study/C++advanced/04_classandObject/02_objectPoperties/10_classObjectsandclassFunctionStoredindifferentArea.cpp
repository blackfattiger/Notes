
// 4.3 C++对象模型和this指针
// 4.3.1 成员变量和成员函数分开存储
// 在C++中，类内的成员变量和成员函数分开存储
// 只有非静态成员变量才属于类的对象上



#include <iostream>
using namespace std;

class Person{


};

class Person { 
public: 
    Person() { 
        m_A = 0; 
    } 
    //非静态成员变量 属于类的对象空间 
    int m_A; 
    //静态成员变量 不属于类的对象空间 
    static int m_B; 
    //非静态成员函数 也不属于类的对象空间，所有函数共享一个函数实例 
    void func() { 
        cout << "m_A:" << this->m_A << endl; 
    } 
    //静态成员函数也不占对象空间 
    static void func2() {

    } 
};


void test01(){
    Person p;
    //空对象占用内存空间为：1
    //C++编译器会给每个空对象也分配一个内存空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout<<"size of p: "<<sizeof(p)<<endl;
}

void test02(){
    Person p;
    cout<<"size of p: "<<sizeof(p)<<endl;
}

int main(){
    test01();
    test02();

    return 0;
}