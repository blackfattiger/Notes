// 4.1.2 struct和class区别
// 在C++中 struct和class唯一的区别就在于 默认的访问权限不同
// 区别：
// struct 默认权限为公共
// class 默认权限为私有

#include <iostream>
using namespace std;

class C1 { 
    int m_A; //默认是私有权限 
};
struct C2 { 
    int m_A; //默认是公共权限 
};

int main(){
    C1 c1;
    // c1.m_A = 10; //错误，class中默认的访问权限是私有，因此类外不能访问
    C2 c2;
    c2.m_A = 10; //正确，struct中默认的访问权限是公共，因此类外可以访问
    system("pause");

    return 0;
}