// 1.3.6 类模板成员函数类外实现
// 学习目标：能够掌握类模板中的成员函数类外实现

// 总结：类模板中成员函数类外实现时，需要加上模板参数列表

#include<iostream>
using namespace std;

//类模板中成员函数类外实现
template<class T1, class T2>
class Person {
public:
    //成员函数类内声明
    Person(T1 name, T2 age);
    void showPerson();
public:
    T1 m_Name;
    T2 m_Age;
};

//构造函数 类外实现
template<class T1, class T2>
Person<T1,T2>::Person(T1 name, T2 age){  //要强调是类模板的成员函数在类外实现，所以需要在类名后面加上模板参数列表，否则和普通的成员函数类外实现没有区别
    this->m_Name = name;
    this->m_Age = age;
}

//成员函数 类外实现
template<class T1, class T2>
void Person<T1,T2>::showPerson(){
    cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}

void test01()
{
    Person<string, int> p("Tom", 20);
    p.showPerson();
}

int main() {
    test01();
    system("pause");
    return 0;
}

