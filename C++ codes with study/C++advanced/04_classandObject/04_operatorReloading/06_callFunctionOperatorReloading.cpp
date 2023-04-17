// 4.5.6 函数调用运算符重载
// 函数调用运算符 () 也可以重载
// 由于重载后使用的方式非常像函数的调用，因此称为仿函数
// 仿函数没有固定写法，非常灵活


#include <iostream>
using namespace std;

class MyPrint{
public:
    //重载函数调用运算符
    void operator()(string test){
        cout<<"test"<<endl;
    }
};

 void MyPrint02(string test){
        cout<<"test"<<endl;
}

void test01(){
    MyPrint myprint;

    myprint("hello world!"); //由于使用起来非常类似于一个函数调用，因此称为仿函数

    MyPrint02("hello world!");
}

//仿函数非常灵活，没有固定的写法
//加法类
class Add{
public:
    int operator()(int num1, int num2){
        return num1 + num2;
    }

};

void test02(){
    Add add;
    int ret = add(5,8);
    cout<<ret<<endl;

    //匿名函数对象 类名+(),括号里有参无参都可以根据构造函数创建出不同的匿名函数对象， 匿名函数对象特点：当前行执行完了立即被释放！
    //如果我不像去创建一个对象，而且这个仿函数只用一次，那么完全可以使用匿名函数对象
    cout<<Add()(5,8)<<endl;
}

int main(){
    test01();
    test02();
    return 0;
}   