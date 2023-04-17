// 4.5.2 左移运算符重载
// 作用：可以输出自定义数据类型


// 总结：重载左移运算符配合友元可以实现输出自定义数据类型


#include <iostream>
using namespace std;

class Person{
    friend ostream& operator<<(ostream &cout,Person & p); //当属性定义为private时，就需要友元技术了

public:
    Person(int num1, int num2){
        m_A = num1;
        m_B = num2;
    }
    //利用成员函数重载 左移运算符， p.operator<<(cout)  简化版本为 p << cout
    //所以不回利用成员函数重载<<运算符，因为无法实现 cout在左侧
    // void operator<<(Person &p){

    // }

// public:
private:
    int m_A;
    int m_B;
};

//只能利用全局函数重载左移运算符 
//记住：流对象不能复制，只能引用
//相当于用间接的方式输出了p里面的数据，但是可以直接写为cout<<p
ostream& operator<<(ostream &cout,Person & p){   //本质： operator<<(cout, p)  简化： cout<<p
    cout<<"p.m_A = "<<p.m_A<<", "<<"p.m_B = "<<p.m_B;
    // cout<<p.m_B;
    return cout;
}

void test01(){
    Person p(10,10);
    cout<<p<<endl;  //要想满足输入<<endl 就需要进行链式编程，需要cout<<p返回的还是一个cout类型才行，所以上面运算符重载时，返回类型就需要为cout的类型

}

int main(){

    test01();

    return 0;
}