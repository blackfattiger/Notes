#include<iostream>
using namespace std;
//函数常见样式 //1、 无参无返 
void test01() { 
    //void a = 10; 
    //无类型不可以创建变量,原因无法分配内存 
    cout << "this is test01" << endl; 
    }
//2、 有参无返 
void test02(int a) { 
    cout << "this is test02" << endl; 
    cout << "a = " << a << endl; 
    }
//3、无参有返 
int test03() { 
    cout << "this is test03 " << endl; 
    return 10; 
    }
//4、有参有返 
int test04(int a, int b) {
    cout << "this is test04 " << endl; 
    int sum = a + b; 
    return sum; 
    }

int main(){
    test01();// 函数调用 
    test02(100);
    int t3 = test03();
    cout<<t3<<endl;
    int t4 = test04(5,8);
    cout<<t4<<endl;

    return 0;
}