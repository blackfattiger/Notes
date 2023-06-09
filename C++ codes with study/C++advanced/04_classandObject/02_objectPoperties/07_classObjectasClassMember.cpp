// 4.2.7 类对象作为类成员
// C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员
// 例如：
// C++ 
// class A {}; 
// class B { A a； };
// B类中有对象A作为成员，A为对象成员
// 那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？

// 例如创建一个人的对象，在人这个类中的其他类对象就像身体的各部分，需要先把各部分创建完成，最后才能组装成一个人

#include <iostream>
using namespace std;

class Phone { 
public: 
    Phone(string name) { 
        m_PhoneName = name; 
        cout << "Phone构造" << endl; 
    }
    ~Phone(){
    cout << "Phone析构" << endl;
    }

    string m_PhoneName;
};

class Person { 
public:
    //初始化列表可以告诉编译器调用哪一个构造函数
    Person(string name, string pName) :m_Name(name), m_Phone(pName)
    {
    cout << "Person构造" << endl;
    }
    ~Person()
    {
    cout << "Person析构" << endl;
    }
    void playGame()
    {
    cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
    }
    string m_Name;
    Phone m_Phone;
};

void test01() { 
    //当类中成员是其他类对象时，我们称该成员为 对象成员 
    //构造的顺序是 ：先调用对象成员的构造，再调用本类构造 
    //析构顺序与构造相反，即先析构本类构造，再析构本类中其他类的对象成员
    Person p("张三" , "苹果X"); p.playGame();
}

int main(){

    test01();
    system("pause");

    return 0;
}