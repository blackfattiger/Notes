// 4.5.4 赋值运算符重载
// c++编译器至少给一个类添加4个函数
// 1. 默认构造函数(无参，函数体为空)
// 2. 默认析构函数(无参，函数体为空)
// 3. 默认拷贝构造函数，对属性进行值拷贝
// 4. 赋值运算符 operator=, 对属性进行值拷贝
// 如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题

//赋值 主要利用深拷贝解决浅拷贝出现的内存问题


#include <iostream>
using namespace std;

class Person{
public:
    Person(int age){
      m_Age = new int(age);
    }

    ~Person(){
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }

    //重载 赋值运算符
    Person& operator=(Person &p){
        //编译器提供的是浅拷贝
        // m_Age = p.m_Age;

        // m_Age = new int (*p.m_Age);
        //应该先判断是否有属性存放再堆区，如果有就先释放干净，然后再深拷贝
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
        //然后再做深拷贝操作
        m_Age = new int (*p.m_Age);
        //返回对象本身
        return *this;
    }

public:
    int *m_Age;
};

void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1; //赋值操作，如果重载赋值运算符那里返回的是void，那么这里p2调用函数后就返回的void，此时让p3 = void 显然不正确！
    cout<<"p1的年龄为："<<*p1.m_Age<<endl;
    cout<<"p2的年龄为："<<*p2.m_Age<<endl;
    cout<<"p3的年龄为："<<*p3.m_Age<<endl;

}

int main(){
    test01();
    int a = 10;
    int b = 20;
    int c = 30;
    c = b = a;              //可以发现编译器支持这种连等的操作
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl; //要想重载的赋值运算符也能实现这种操作，就需要符合这种操作的类型，所以老师一直在教我们链式编程的思维！

    system("pause");
    return 0;
}