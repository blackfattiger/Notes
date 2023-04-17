// 4 STL- 函数对象 ————仿函数
// 4.1 函数对象
// 4.1.1 函数对象概念
// 概念：
// 重载函数调用操作符的类，其对象常称为函数对象
// 函数对象使用重载的()时，行为类似函数调用，也叫仿函数
// 本质：
// 函数对象(仿函数)是一个类，不是一个函数

// 4.1.2 函数对象使用
// 特点：
// 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
// 函数对象超出普通函数的概念，函数对象可以有自己的状态
// 函数对象可以作为参数传递

// 总结：
// 仿函数写法非常灵活，可以作为参数进行传递。

#include<iostream>
using namespace std;

// 1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd{
public:
    int operator()(int v1, int v2){
        return v1 + v2;
    }
};

void test01(){
    MyAdd myAdd; //创建对象
    cout<<myAdd(3,5)<<endl; //对象使用仿函数
}

// 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint{  //在类中创建成员变量记录仿函数状态
public:
    void operator()(string test){
        cout<<test<<endl;
        this->m_Count++;
    }
    int m_Count;
};

void test02(){
    MyPrint myPrint;
    myPrint("hello");
    myPrint("hello");
    myPrint("hello");
    cout<<myPrint.m_Count<<endl;
}

// 3.函数对象可以作为参数传递
void test03(MyPrint & myPrint, string test){
    myPrint(test);
}

int main(){
    // test01();
    // test02();
    MyPrint myPrint;
    test03(myPrint, "hello");
    return 0;
}