#include <iostream>
using namespace std;
//引用相当于指针常量  int* const p = ....
// **作用： **给变量起别名
// 语法： 数据类型 &别名 = 原名
int main(){
    int a = 10;
    int &b = a;
    cout<<a<<endl;
    cout<<b<<endl;
    b = 100;
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}