// 4.3 内建函数对象
// 4.3.1 内建函数对象意义
// 概念：
// STL内建了一些函数对象
// 分类:
// 算术仿函数
// 关系仿函数
// 逻辑仿函数
// 用法：
// 这些仿函数所产生的对象，用法和一般函数完全相同
// 使用内建函数对象，需要引入头文件 #include<functional>

// 4.3.2 算术仿函数
// 功能描述：
// 实现四则运算
// 其中negate是一元运算，其他都是二元运算
// 仿函数原型：
// template<class T> T plus<T> //加法仿函数
// template<class T> T minus<T> //减法仿函数
// template<class T> T multiplies<T> //乘法仿函数
// template<class T> T divides<T> //除法仿函数
// template<class T> T modulus<T> //取模仿函数
// template<class T> T negate<T> //取反仿函数

// 总结：使用内建函数对象时，需要引入头文件 #include <functional>

#include<iostream>
using namespace std;
#include<functional>

//内建函数对象 算术运算
//negate
void test01(){
    negate<int> n;  //除了实现方式是模板以外， 其他实现方式和自己编写的仿函数一样， 都是先创建对象，然后通过对象来调用仿函数
    cout<<n(66)<<endl;
    /*如果大家能理解negate<>就是个用来执行仿函数的类，而如果你只想执行类的函数不想创建一个类的实例化对象，
    可以不用创建这个n，直接输出的时候写cout<<negate<int>()(50)<<end*/
    cout<<negate<int>()(50)<<endl;  //先创建匿名对象，然后使用匿名对象的仿函数
}

void test02(){
    plus<int> p;
    cout<<p(10,20)<<endl;
}




int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
