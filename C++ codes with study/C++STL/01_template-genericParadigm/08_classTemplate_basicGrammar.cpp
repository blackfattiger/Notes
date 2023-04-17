// 1.3 类模板
// 1.3.1 类模板语法
// 类模板作用：
// 建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。
// 语法：
// template<typename T>    这对尖括号< >内部称为模板的参数列表
// 类

// 解释：
// template --- 声明创建模板
// typename --- 表面其后面的符号是一种数据类型，可以用class代替
// T --- 通用的数据类型，名称可以替换，通常为大写字母

//模板就是为了将类型参数化

// 总结：类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板

#include<iostream>
using namespace std;

//类模板
template<typename NameType, typename AgeType>  //成员中需要几个通用数据类型就再模板参数列表里声明几个参数
class Person{
public:
    Person(NameType name, AgeType age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void ShowPerson(){
        cout<<"姓名："<<this->m_Name<<"\t年龄："<<this->m_Age<<endl;
    }

    NameType m_Name;
    AgeType m_Age;
};

void test01(){
    // 指定NameType 为string类型，AgeType 为int类型
    // 下面<>中是给类型传值，()中是给有参构造中的形参传值 
    Person<string, int> p("孙悟空", 999);
    p.ShowPerson();
}

int main(){
    test01();
    system("pause");
    return 0;
}