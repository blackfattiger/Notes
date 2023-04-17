// 4.3.4 const修饰成员函数
// 常函数：
// 成员函数 后 加const后我们称为这个函数为常函数
// 常函数内不可以修改成员属性
// 成员属性声明时加关键字mutable后，在常函数中依然可以修改
// 常对象：
// 声明对象 前 加const称该对象为常对象
// 常对象只能调用常函数


#include <iostream>
using namespace std;

class Person{
public:

    //this指针的本质 是指针常量， 指针的指向是不可以修改的
    //const Person* const this;
    //在成员函数后加const，修饰的是this的指向，让指针指向的值也不可以修改
    //常函数
    void showPerson() const  
    {
        // m_A = 100;
        // this->m_A = 100;
        // this = NULL; //this指针不可以修改指针的指向
                        /*指针指向其实是一个很抽象的词，指针无非就是分配了一块内存，里面存放了地址，
                        指向就是这个地址代表了一个变量的地址或者其他类型的地址，所以让一个指针指向其他位置，
                        只需要给这个指针赋一个其他位置的地址即可*/  
        m_B = 100;
    }
    void func(){

    }

public:
    int m_A;
    mutable int m_B; //特殊变量，即使在常函数中，也可以修改这个值，只需要加上关键字mutable
                     //可以把mutable当作root权限

};

void test01(){
    Person p;
    p.showPerson();
}

//常对象                但是常对象可以修改静态变量的值！ 静态成员并不包括在对象内，所以不受对象修饰的影响，可以直接修改     
void test02(){
    const Person p; //在对象前加const，变为常对象
    // p.m_A = 100;      但是常对象可以修改静态变量的值！
    p.m_B = 100; //m_B是特殊值，在常对象下也可以修改
    //常对象只能调用常函数
    p.showPerson();
    // p.func();  //常对象不可以调用普通的成员函数，因为普通成员函数可以修改属性

}

int main(){


    return 0;
}