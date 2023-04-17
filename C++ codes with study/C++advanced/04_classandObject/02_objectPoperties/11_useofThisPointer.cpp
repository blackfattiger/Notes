
// 4.3.2 this指针概念
// 通过4.3.1我们知道在C++中成员变量和成员函数是分开存储的
// 每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
// 那么问题是：这一块代码是如何区分那个对象调用自己的呢？
// c++通过提供特殊的对象指针，this指针，解决上述问题。this指针指向被调用的成员函数所属的对象，this指针是隐含在每一个非静态成员函数内的一种指针

// this指针隐含在每一个 成员函数 内部，不需要定义，直接使用即可

// this指针的用途：
// 当形参和成员变量同名时，可用this指针来区分
// 在类的非静态成员函数中返回对象本身，可使用return *this

// this指针指向被调用的成员函数所属的对象

#include <iostream>
using namespace std;

class Person { 
public:
    Person(int age)
    {
    //1、当形参和成员变量同名时，可用this指针来区分
        this->age = age;
    }
    Person& PersonAddPerson(Person p)      //如果不用引用的方式返回，会另外分配一块儿内存，相当于返回的是与p2不同的另一个Person（只是age都为20），后续的加年龄操作与p2就没有关系了
    {                                      //引用指向本身内存，不用引用就是拷贝了，而拷贝指向另一个内存
        this->age += p.age;                //取引用，保证传回来的还是同一个对象
        //返回对象本身
        return *this;
    }
    int age;
};

void test01() { 
    Person p1(10); 
    cout << "p1.age = " << p1.age << endl;
    Person p2(10);
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1); //如果不使用引用，此处第一次函数调用返回的就是p2'，以此类推，每次都会返回一个全新的对象
    cout << "p2.age = " << p2.age << endl;
}



int main(){
    test01();
    system("pause");

    return 0;
}

