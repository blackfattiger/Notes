// 4.5.5 关系运算符重载
// 作用：重载关系运算符，可以让两个自定义类型对象进行对比操作




#include <iostream>
using namespace std;

class Person{
public:
    Person(string name, int age){
        m_Name = name;
        m_Age = age;
    }

    //重载 == 号
    bool operator==(Person &p){
        if(m_Age == p.m_Age && m_Name == p.m_Name){
            return true;
        }
        return false;

    }

     //重载 != 号
    bool operator!=(Person &p){
        if(m_Age == p.m_Age && m_Name == p.m_Name){
            return false;
        }
        return true;

    }

public:
    string m_Name;
    int m_Age;
};

void test01(){
    Person p1("Tom",18);
    Person p2("Tom",18);
    if(p1 == p2){
        cout<<"p1与p2相等！"<<endl;
    }else{
        cout<<"p1与p2不相等！"<<endl;
    }
}

void test02(){
    Person p1("Tom",18);
    Person p2("Tom",18);
    if(p1 != p2){
        cout<<"p1与p2不相等！"<<endl;
    }else{
        cout<<"p1与p2相等！"<<endl;
    }
}

int main(){

    test01();
    test02();    
    return 0;
}