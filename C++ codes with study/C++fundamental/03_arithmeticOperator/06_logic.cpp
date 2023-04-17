#include<iostream>
using namespace std;
int main(){
    //逻辑运算符 --- 非 
    int a = 10;
    cout << !a << endl; // 0
    cout << !!a << endl; // 1

    //逻辑运算符 --- 与 
    int a1 = 10;
    int b1 = 10;
    cout << (a1 && b1) << endl;// 1
    a1 = 10;
    b1 = 0;
    cout << (a1 && b1) << endl;// 0
    a1 = 0;
    b1 = 0;
    cout << (a1 && b1) << endl;// 0

    //逻辑运算符 --- 或 
    int a2 = 10;
    int b2 = 10;
    cout << (a2 || b2) << endl;// 1
    a2 = 10;
    b2 = 0;
    cout << (a2 || b2) << endl;// 1
    a2 = 0;
    b2 = 0;
    cout << (a2 || b2) << endl;// 0

    return 0;
}