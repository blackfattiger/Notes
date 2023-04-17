#include<iostream>
using namespace std;
int main(){
    //前置递增，先将变量加1，再计算表达式
    int a1 = 10;
    int b = ++a1 * 10;
    cout<<b<<endl;
    //后置递增，先计算表达式，在将变量加1
    int a2 = 10;
    int c = a2++ * 10;
    cout<<c<<endl;

    return 0;
}