// 2.3 引用做函数参数
// 作用：函数传参时，可以利用引用的技术让形参修饰实参
// 优点：可以简化指针修改实参

//1. 值传递 
void mySwap01(int a, int b) { int temp = a; a = b; b = temp; }
//2. 地址传递 
void mySwap02(int* a, int* b) { int temp = *a; *a = *b; *b = temp; }
//3.引用传递
void mySwap03(int& a, int& b) { int temp = a; a = b; b = temp; }


#include <iostream>
using namespace std;
int main(){
    int a = 10;
    int b = 20;
    mySwap01(a, b);
    cout << "a:" << a << " b:" << b << endl;
    mySwap02(&a, &b);// mySwap02(int* a, int* b) 中 int* a = &a
    cout << "a:" << a << " b:" << b << endl;
    mySwap03(a, b);   //看函数mySwap03(int& a, int& b),把实参a给了形参int& a,相当于int& a = a,然后在函数中再对引用进行操作
    cout << "a:" << a << " b:" << b << endl;
    system("pause");
    return 0;
}

// 总结：通过引用参数产生的效果同按地址传递是一样的。引用的语法更清楚简单