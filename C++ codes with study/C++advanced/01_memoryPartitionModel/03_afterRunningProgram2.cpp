// 1.2.2 程序运行后
// 堆区：
// 堆区：
// 由程序员分配释放,若程序员不释放,程序结束时由操作系统回收
// 在C++中主要利用new在堆区开辟内存
#include <iostream>
using namespace std;
int * func() { 
    //利用new关键字，可以将数据开辟到堆区，而且返回的不是数据本身，而是返回堆区数据的地址
    //此处的指针本质上也是局部变量，存在于栈上，指针指向的数据才是放在堆区的
    int* p = new int(10); 
    return p; 
}

int main() {
    int *p = func(); //在堆区开辟数据
    cout << *p << endl; //main中的P和func中的p不同，这里是因为func中的指针已经返回给了main中的p,所以只要main函数不结束，那么这个指针P始终存在，一直指向那个地址
    cout << *p << endl; //而指针p指向的那个堆区中的数据，只要main函数不结束，堆区不会自动释放，除非编程的人手动释放
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    system("pause");
    return 0;
}
// 总结：
// 堆区数据由程序员管理开辟和释放
// 堆区数据利用new关键字进行开辟内存
