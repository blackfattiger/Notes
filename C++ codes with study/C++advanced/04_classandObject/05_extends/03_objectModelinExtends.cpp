// 4.6.3 继承中的对象模型
// 问题：从父类继承过来的成员，哪些属于子类对象中？

// 结论： 父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到
// 还可以利用工具来查看类中的信息，详情看课件，VSCODE没发现这个工具 难受住

#include <iostream>
using namespace std;

class Base { 
public: 
    int m_A; 
protected: 
    int m_B; 
private: 
    int m_C; //私有成员只是被隐藏了，但是还是会继承下去 
};

//公共继承 
class Son :public Base { 
public: 
    int m_D; 
};

void test01() { 
    //父类中的非静态成员属性都会被子类继承下去
    //父类中的私有成员 是被编译器给隐藏了，因此访问不到，但是确实被子类继承下去了，它依然在那里  
    cout << "sizeof Son = " << sizeof(Son) << endl; 
}


int main(){

    test01();


    return 0;
}