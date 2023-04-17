// 4.2.6 初始化列表
// 作用：
// C++提供了初始化列表语法，用来初始化属性
// 语法：构造函数()：属性1(值1),属性2（值2）... {}
// 使用初始化列表的好处：
// 1.类成员中存在常量，如 const int a ; 这类常量只能初始化，不能被赋值；
// 2.类成员中存在引用，同样只能初始化不能赋值
// 3.提高效率


#include <iostream>
using namespace std;

class Person { 
public:////传统方式初始化
    //Person(int a, int b, int c) {
    // m_A = a;
    // m_B = b;
    // m_C = c;
    //}
//初始化列表方式初始化
    Person(int a, int b, int c): m_A(a), m_B(b), m_C(c)
    {

    }
    void PrintPerson() {
    cout << "mA:" << m_A << endl;
    cout << "mB:" << m_B << endl;
    cout << "mC:" << m_C << endl;
    }
private: 
    int m_A; 
    int m_B; 
    int m_C; 
};



int main(){


    return 0;
}