#include "swap.h"  //双引号表示头文件为自定义的头文件，用此方法将swap.h与swap.cpp关联起来

void swap(int num1, int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout<<"num1 = "<<num1<<endl; 
    cout<<"num2 = "<<num2<<endl;
}