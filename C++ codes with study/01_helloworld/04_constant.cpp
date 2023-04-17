#include<iostream>
#define max 100     // #define 变量名 变量值  （此处定义的为宏常量，通常定义在文件的上方）

using namespace std;
int main(){
    const int min = 1;  // const 变量名 = 变量值 （此处为const修饰的变量，通常定义在文件内部）
   /* min = 2; 常量不可修改，否则会报错
    max = 99; 
    */

    cout<<"max="<<max<<endl;
    cout<<"min="<<min<<endl;
    return 0;
} 

