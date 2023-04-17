// 4.3.3 空指针访问成员函数
// C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
// 如果用到this指针，需要加以判断保证代码的健壮性


#include <iostream>
using namespace std;

class Person{
public:
    void ShowClassName() {
    cout << "我是Person类!" << endl;
    }
    void ShowPerson() {
        if (this == NULL) {
        return;
    }
    cout << m_Age << endl;  //因为此处会有默认的 this-> m_Age，当指针为空，就访问不到这个m_Age
    }

public:
    int m_Age;
};

void test01() { 
    Person * p = NULL; 
    p->ShowClassName(); //空指针，可以调用成员函数 
    // p->ShowPerson(); //但是如果成员函数中用到了this指针，就不可以了，此时为了增加程序健壮性需要在成员函数中增加判断语句
}


int main(){
    test01();
    // Person p;
    // Person * p1 = &p;
    // cout<<p1->m_Age<<endl;
    // cout<<(*p1).m_Age<<endl;   两种方式都可以获取正确的值，但是用 -> 更简单一点 哈哈
    system("pause");
    return 0;
}