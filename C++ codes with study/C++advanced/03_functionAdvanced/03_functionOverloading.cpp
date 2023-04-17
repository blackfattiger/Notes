// 3.3 函数重载
// 3.3.1 函数重载概述
// 作用：函数名可以相同，提高复用性
// 函数重载满足条件：
// 同一个作用域下
// 函数名称相同
// 函数参数 类型不同 或者 个数不同 或者 顺序不同
// 注意: 函数的返回值不可以作为函数重载的条件

#include <iostream>
using namespace std;

//函数重载需要函数都在同一个作用域下 
void func() { 
    cout << "func 的调用！" << endl; 
} 
void func(int a) { 
    cout << "func (int a) 的调用！" << endl; 
}
void func(double a) { 
    cout << "func (double a)的调用！" << endl; 
} 
void func(int a ,double b) { 
    cout << "func (int a ,double b) 的调用！" << endl; 
} 
void func(double a ,int b) { 
    cout << "func (double a ,int b)的调用！" << endl; 
}
//函数返回值不可以作为函数重载条件 
//int func(double a, int b) {    上一个函数返回值类型为void，此处为int，但是返回值类型不同不能作为函数重载的条件，在调用函数时也会造成编译器的二义性
    // cout << "func (double a ,int b)的调用！" << endl; 
//}

int main(){
    func();
    func(10);
    func(3.14);
    func(10,3.14);
    func(3.14 , 10);

    return 0;
}
