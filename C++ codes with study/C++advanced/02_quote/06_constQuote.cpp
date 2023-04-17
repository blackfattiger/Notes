// 作用：常量引用主要用来修饰形参，防止误操作
// 在函数形参列表中，可以加==const修饰形参==，防止形参改变实参

void showValue(const int& ref){
    //ref = 100;
    cout<<"ref = "<<ref<<endl;
}


#include <iostream>
using namespace std;
int main(){
    //int& ref = 10; 引用本身需要一个合法的内存空间，10只是一个字面量并没有内存空间，因此这行错误
    //加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
    const int& ref = 10;
    //ref = 100; //加入const后不可以修改变量
    cout << ref << endl;
    //函数中利用常量引用防止误操作修改实参
    int a = 10;
    showValue(a);
    system("pause");

    return 0;
}
