// 1.2.1 程序运行后
// 栈区：
// 由编译器自动分配释放, 存放函数的参数值,局部变量等
// 注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
#include <iostream>
using namespace std;
int * func() { 
    int a = 10; 
    return &a; 
}

int main() {
    int *p = func();
    cout << *p << endl;//第一次可以输出正确数值，是因为编译器在栈区为我们保留了一次值
    cout << *p << endl;//第二次栈区中的值已经清空了，所以不能输出正确数值
    system("pause");
    return 0;
}