// 作用：引用是可以作为函数的返回值存在的
// 注意：不要返回局部变量引用
// 用法：函数调用作为左值


//返回局部变量引用
int& test01(){
    int a = 10;  //局部变量存放在四区中的  栈区
    return a;  /*有个疑问，不像其他类型那样，如果函数返回值为指针 就必须return 指针p，
                 这里返回值为引用时，直接返回变量就行了，而且在外面还必须用引用来接收 */
}

//返回静态变量引用 
int& test02() {
    static int a = 20;  //静态变量，存放在全局区，全局区上的数据由程序结束后系统进行释放
    return a; 
}


#include <iostream>
using namespace std;
int main(){
    //不能返回局部变量的引用
    int& ref = test01();
    // cout<<ref<<endl;
    // cout<<ref<<endl; 

    //如果函数做左值，那么必须返回引用
    int& ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;
    test02() = 1000;
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;


    return 0;
}