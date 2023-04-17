#include <iostream>
using namespace std;
// 作用：利用指针访问数组中元素


int main(){
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int * p = arr; //指向数组的指针
    cout << "第一个元素： " << arr[0] << endl;
    cout << "指针访问第一个元素： " << *p << endl;
    cout << "指针访问第一个元素： " << p[2] << endl; //指针和数组可以混用！！
    for (int i = 0; i < 10; i++)
    {
    //利用指针遍历数组
    cout << *p << endl;
    p++; //让指针向后偏移4个字节
    }

    // int arr[3] = {3,5,8};
    // long long  arr[3] = {3, 5, 8};
    // long long* p = arr;
    // cout<<arr[0]<<endl;
    // cout<<*p<<endl;
    // cout<<*(p+1)<<endl;    实验表明：指针的偏移量与所指向的数据类型有关
    // int a = 10;
    // int b = *&a;
    // cout<<b<<endl;
    return 0;
}