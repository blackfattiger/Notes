#include <iostream>
using namespace std;
// 提问：指针也是种数据类型，那么这种数据类型占用多少内存空间？
int main(){
    int a = 10;
    int * p;
    p = &a; //指针指向数据a的地址
    cout << *p << endl; //* 解引用

    //在32位操作系统下，不管是什么数据类型，指针占4个字节空间大小
    //在64位操作系统下，不管是什么数据类型，指针占8个字节空间大小
    cout << sizeof(p) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(float *) << endl;
    cout << sizeof(double *) << endl;

    return 0;
}