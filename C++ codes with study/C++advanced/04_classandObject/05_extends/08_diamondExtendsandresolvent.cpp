// 4.6.8 菱形继承
// 菱形继承概念：
// 两个派生类继承同一个基类
// 又有某个类同时继承者两个派生类
// 这种继承被称为菱形继承，或者钻石继承

// 典型的菱形继承案例：
// 1. 羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。
// 2. 草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。

// 总结：
// 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
// 利用虚继承可以解决菱形继承问题

//虚继承的底层实现就是父类从虚基类继承的成员变为了指针，指向虚基类表，通过表内记录的偏移量，指向子类中的同名成员
#include <iostream>
using namespace std;

//动物类
class Animal{
public:
    int m_Age;
};

//利用虚继承可以解决菱形继承的问题
//继承之前 加上 关键字virtual 变为虚继承
//Animal成为虚基类
//羊类
class Sheep: virtual public Animal{};

//驼类
class Camel: virtual public Animal{};

//注意 虚继承不是在羊驼类继承时写virtu关键字，而是在其父类继承时写virtual关键字
//羊驼类
class SheepTuo: public Sheep, public Camel{};

void test01(){
    SheepTuo st;
    st.Sheep::m_Age = 100;
    st.Camel::m_Age = 200;
    //当菱形继承，两个父类拥有相同数据，需要加以作用域区分
    cout<<"st.Sheep::m_Age = "<<st.Sheep::m_Age<<endl;
    cout<<"st.Camel::m_Age = "<<st.Camel::m_Age<<endl;
    cout<<"st.m_Age = "<<st.m_Age<<endl;
    //这份数据我们只需要一份即可，但菱形继承导致数据有两份，资源浪费
}
int main(){
    test01();
    return 0;
}