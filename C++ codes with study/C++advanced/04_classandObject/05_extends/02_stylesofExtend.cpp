// 4.6.2 继承方式
// 继承的语法：class 子类 : 继承方式 父类
// 继承方式一共有三种：
// 公共继承 public
// 保护继承 protected
// 私有继承 private

class Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};


//公共继承
class Son1: public Base{
public:
    void func(){
        m_A = 10; //父类中的公共权限成员，到了子类中依然是公共权限
        m_B = 10; //父类中的保护权限成员，到了子类中依然是保护权限
        // m_C = 10;  //父类中的私有权限成员，子类中不能访问
    }
};

void test01(){
    Son1 s1;
    s1.m_A = 100;
    // s1.m_B = 100;//到Son1中m_B是保护权限，类外不能访问
}

//保护继承
class Son2: protected Base{
public:
    void func(){
        m_A = 10; // 父类中公共成员，到子类中变为保护权限
        m_B = 10; // 父类中保护成员，到子类中还是保护权限
        // m_C = 10; // 父类中私有成员，子类访问不到
    }
};

void test02(){
    Son2 s2;
    // s2.m_A = 100; //在Son2中 m_A变为了保护权限，因此类外访问不到
    // s2.m_B = 100; //在Son2中 m_B为保护权限，类外不能访问
}

//私有继承
class Son3: private Base{
public:
    void func(){
        m_A = 10;//父类中公共成员， 子类中变为私有成员
        m_B = 10;//父类中保护成员， 子类中变为私有成员
        // m_C = 10;//父类中私有成员，子类访问不到
    }
};

class GrandSon3 : public Son3{
    friend void test04();//即时成为儿子的友元，也不能访问其父亲的私有成员
public:
    void func(){
        // m_A = 10;//到了Son3中 m_A变为私有成员，即时是Son3的儿子，也访问不到
        // m_B = 10;//到了Son3中 m_B变为私有成员，即时是Son3的儿子，也访问不到
    }
};

void test03(){  
    Son3 s3;
    // s3.m_A = 100; //到Son3中变为私有成员，类外不能访问
    // s3.m_B = 100; //到Son3中变为私有成员，类外不能访问
}

void test04(){
    GrandSon3 gd3;
    // gd3.m_A = 10;
}

#include <iostream>
using namespace std;




int main(){



    return 0 ;
}