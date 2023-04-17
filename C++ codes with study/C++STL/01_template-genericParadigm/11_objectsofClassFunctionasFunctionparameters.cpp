// 1.3.4 类模板对象做函数参数
// 学习目标：
// 类模板实例化出的对象，向函数传参的方式
// 一共有三种传入方式：
// 1. 指定传入的类型 --- 直接显示对象的数据类型
// 2. 参数模板化 --- 将对象中的参数变为模板进行传递
// 3. 整个类模板化 --- 将这个对象类型 模板化进行传递

// 总结：
// 通过类模板创建的对象，可以有三种方式向函数中进行传参
// 使用比较广泛是第一种：指定传入的类型

#include<iostream>
using namespace std;

//类模板
template<class T1, class T2>
class Person{
public:
    Person(T1 name,T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};

//1.指定传入类型
void showPerson1(Person<string, int> &p){  //传入引用才是同一个对象
    p.showPerson();
}

void test01(){
    Person<string, int> p("孙悟空", 100);
    showPerson1(p);
}

//2.参数模板化
template<class T1, class T2>
void showPerson2(Person<T1, T2> &p){  
    p.showPerson();
    cout << "T1的类型为： " << typeid(T1).name() << endl;
    cout << "T2的类型为： " << typeid(T2).name() << endl;
}

// 这里的2是将函数变为函数模板，目的是为了使用函数模板的自动类型指导
// 函数模板可以自动推导，即使传入的类模板，也可以推导出T1T2
// 这里的参数模板化应该是用了前面的自动类型推导，编译器自己推出来是string和int
void test02(){
    Person<string, int> p("猪八戒", 90);
    showPerson2(p);
}

//3.整个类模板化
template<class T>
void showPerson3(T &p){  
    p.showPerson();
    cout<<"T的类型为："<<typeid(T).name()<<endl;
}

void test03(){
    Person<string, int> p("唐僧", 30);
    showPerson3(p);
}

int main(){
    test01();
    test02();
    test03();
    system("pause");
    return 0;
}