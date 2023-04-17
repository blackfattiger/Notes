#include<iostream>
using namespace std;
int main(){
//注意：在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环
    int num = 0;
    while (num < 10)
    {
    cout << "num = " << num << endl;
    num++;
    }
    return 0;
}