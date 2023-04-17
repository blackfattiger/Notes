// 1.2 函数模板
// C++另一种编程思想称为 泛型编程 ，主要利用的技术就是模板
// C++提供两种模板机制:函数模板和类模板
// 1.2.1 函数模板语法
// 函数模板作用：
// 建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表。

// 语法：
// template<typename T>
// 函数声明或定义

// 解释：
// template --- 声明创建模板
// typename --- 表面其后面的符号是一种数据类型，可以用class代替
// T --- 通用的数据类型，名称可以替换，通常为大写字母

// 总结：
// 函数模板利用关键字 template
// 使用函数模板有两种方式：自动类型推导、显示指定类型
// 模板的目的是为了提高复用性，将 类型 参数化


//交换整型函数
void swapInt(int& a, int& b) {
int temp = a;
a = b;
b = temp;
}
//交换浮点型函数
void swapDouble(double& a, double& b) {
double temp = a;
a = b;
b = temp;
}

//这两个函数有一个特点：基本都差不多，可以整合为一个模板

//利用模板提供通用的交换函数
template<typename T>
void mySwap(T &a, T &b){
    //谨记：T为通用数据类型
    T temp = a;
    a = b;
    b = temp;
}

void test01(){
    int a = 10;
    int b = 20;
    //swapInt(a, b);

    //利用模板实现交换
    //1、自动类型推导
    mySwap(a, b);

    //2.显示指定类型
    mySwap<int>(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

#include<iostream>
using namespace std;

int main(){
    test01();

    return 0;
}
