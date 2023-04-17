// 4.2.3 拷贝构造函数调用时机
// C++中拷贝构造函数调用时机通常有三种情况
// 使用一个已经创建完毕的对象来初始化一个新对象
// 值传递的方式给函数参数传值
// 以值方式返回局部对象


#include <iostream>
using namespace std;

class Person{
public:
    Person(){
        cout<<"无参构造函数!" << endl; 
    }
    Person(int age){
        cout<<"有参构造函数!" << endl; 
    }
    Person(const Person & p){
        m_Age = p.m_Age;
        cout<<"拷贝构造函数!" << endl; 
    }

    //析构函数在释放内存之前调用
    ~Person(){
        cout << "析构函数!" << endl;
    }

public:
    int m_Age;

};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01(){
    Person p1; 
    Person p2(10);  //p对象已经创建完毕
    Person p3(p2);  //调用拷贝构造函数
    Person p4 = p2; //拷贝构造

    //Person p5;
    //p5 = p2; //不是调用拷贝构造函数，这是一个赋值操作
}

//2. 值传递的方式给函数参数传值 
//相当于Person p1 = p;  此处运用了隐式构造函数调用！ 不要忘记每次函数调用的时候，形参都是在刚进入函数时才被创建！
void doWork(Person p1) {} 

void test02() { 
    Person p; 
    //无参构造函数 
    doWork(p); 
}

//3.值方式返回局部对象
Person doWork2(){
    Person p1;
    cout<<&p1<<endl;
    return p1;//此处以值方式返回的并不是对象p1，而是p1拷贝的一个新对象返回给外面，p1在函数结束时已被销毁
}

void test03(){
    Person p = doWork2();
    cout<<&p<<endl; /*和很多弹幕一样，我也是两个地址都一样，并没有调用拷贝构造，可能时编译器不同导致的问题（后面再回头来看看吧）
    老师那里显示地址不一样，所以说明之前函数调用返回的p1不是函数里面创建的p1对象，*/
}


int main(){
    test01();
    test02();
    test03();

    return 0;
}