#include<iostream>
using namespace std;
int main(){
    int a=10,b=20,c=0;
    a>b? c=a :c=b;// c = (a>b? a :b);
    cout<<c<<endl;
    //C++中三目运算符返回的是变量,可以继续赋值
    (a > b ? a : b) = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    return 0;
}