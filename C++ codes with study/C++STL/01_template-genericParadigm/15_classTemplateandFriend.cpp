// 1.3.8 类模板与友元
// 学习目标：
// 掌握类模板配合友元函数的类内和类外实现
// 全局函数类内实现 - 直接在类内声明友元即可
// 全局函数类外实现 - 需要提前让编译器知道全局函数的存在

// 总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别

#include<iostream>
using namespace std;

//2、全局函数配合友元 类外实现 - 先做函数模板声明，下方在做函数模板定义，再做友元
//如果此处没有类模板声明，那么下面的函数模板定义就会找不到Person类而报错
template<class T1, class T2> 
class Person;

//如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
//template<class T1, class T2> 
//void printPerson2(Person<T1, T2> & p);
template<class T1, class T2>
void printPerson2(Person<T1, T2> & p){
    cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
    // 这里public和private都已经写了，printPerson函数没写在private里面。要是没写private，这就是默认成员函数
    // 1、全局函数配合友元 类内实现
    friend void printPerson(Person<T1, T2> & p)
    {
        cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
    }

    //如果全局函数 是类外实现，需要让编译器提前知道这个函数的存在 
    //全局函数配合友元 类外实现,这里要加上<>空模板参数列表的尖括号，让这里知道是模板类型的全局函数
    friend void printPerson2<>(Person<T1, T2> & p);
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};

//如果全局函数在这里定义，那么编译器在类内不能识别到这个函数
// template<class T1, class T2>
// void printPerson2(Person<T1, T2> & p){
//     cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
// }

//1、全局函数在类内实现
void test01()
{
    Person <string, int >p("Tom", 20);
    printPerson(p);
}

//2、全局函数在类外实现
void test02()
{
    Person <string, int >p("Jerry", 30);
    printPerson2(p);
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
