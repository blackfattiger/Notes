#include <iostream>
using namespace std;
// C++中利用==new==操作符在堆区开辟数据
// 堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 ==delete==
// 语法：new 数据类型
// 利用new创建的数据，会返回该数据对应的类型的指针
int* func(){
    int* p = new int(10);
    return p;
}


int main(){
    int * p = func();
    cout<<*p<<endl;
    delete p;
    cout<<*p<<endl;  //之前版本应该为释放的空间不可访问，现在为什么随机给了p一个地址，P相当于野指针了

    int *arr = new int[10];
    for(int i = 0; i < 10; i++){
        arr[i] = i + 100;         //数组并不能完全等同于指针，只是说当参数时可以将指针像数组一样使用，指针只是指向了数组开头的第一个元素的地址
    }
    for(int i = 0; i < 10; i++){
        cout<<arr[i]<<endl;
    }
    delete[] arr;



    return 0;
}