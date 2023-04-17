#include<iostream>
using namespace std;
// 功能：使用定义好的函数
// 语法：函数名（参数）

int add(int num1, int num2){  //定义中的num1,num2称为形式参数，简称形参
        int sum = num1 + num2;
        return sum;
    }
int main(){
    int a = 3;
    int b = 5;
    int c = add(a,b); //调用时的a，b称为实际参数，简称实参
    //当函数调用时，实参的值会传递给形参
    cout<<c;
    // cout<<sum; sum是一个局部变量，出了函数体之后就没有定义了，
    //所以不能直接使用sum，而需要用一个变量来接收函数的返回值
    return 0;
}
// 总结：函数定义里小括号内称为形参，函数调用时传入的参数称为实参