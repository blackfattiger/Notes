// 1.2.2 函数模板注意事项
// 注意事项：
// 自动类型推导，必须推导出一致的数据类型T,才可以使用
// 模板必须要确定出T的数据类型，才可以使用

//总结：
//使用模板时必须确定出通用数据类型T，并且能够推导出一致的类型

#include<iostream>
using namespace std;
//利用模板提供通用的交换函数

// C++的一般规则是，除了使用typename修饰外，template内的任何表示符号都被视为一个值而不是对象
template<class T> //typername 可以替换成class
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
// 1、自动类型推导，必须推导出一致的数据类型T,才可以使用
void test01()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    mySwap(a, b); // 正确，可以推导出一致的T
    //mySwap(a, c); // 错误，推导不出一致的T类型
}

// 2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()
{
    cout << "func 调用" << endl;    
}
void test02()
{
    //func(); //错误，模板不能独立使用，必须确定出T的类型————打个比方，一寸照片模板，要是没有把人的头像放上去，直接用模板，有意义吗？ 没有！
    func<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板
}

int main() {
    test01();
    test02();
    // system("pause");
    return 0;
}
