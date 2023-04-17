
// 4.5.3 递增运算符重载
// 作用： 通过重载递增运算符，实现自己的整型数据

// 总结： 前置递增返回引用，后置递增返回值

#include <iostream>
using namespace std;

class MyInteger{
    // friend MyInteger operator++(MyInteger &myint);
    friend ostream& operator<<(ostream &cout, MyInteger myint);

public:
    MyInteger(){
        m_Num = 0;
    }
    //重载前置++运算符  ，返回引用
    MyInteger& operator++(){  //如果不返回引用，那么就会不断创建新的对象，原来的对象始终还在原地踏步，返回引用是为了一直对一个数据进行递增操作
        ++m_Num;
        return *this;
    }

    //重载后置++运算符  ， 返回值
    //MyInteger operator++(int)  这个int代表占位参数，可以用于区分前置和后置递增
    MyInteger operator++(int){  //此处不能返回引用，因为temp是局部对象，函数结束后就被销毁了，后面再用此对象就是非法操作了
        //先返回
        MyInteger temp = *this;
        //后递增
        m_Num++;
        //最后将记录的结果做返回,此处返回临时对象即可，不需要返回引用
        return temp; 
    }

private:
    int m_Num;
};

// MyInteger operator++(MyInteger &myint){
//     myint.m_Num = myint.m_Num + 1;
//     return myint;

// }
//重载左移运算符
ostream& operator<<(ostream &cout, MyInteger myint){
    cout<<myint.m_Num;
    return cout;
}

void test01(){
    MyInteger myint;
    // MyInteger myint2 = myint++;
    cout<<++myint<<endl;
    cout<< myint<<endl;
}

void test02(){
    MyInteger myint;
    // MyInteger myint2 = myint++;
    cout<<myint++<<endl;
    cout<< myint<<endl;
}

int main(){
    int a = 0;
    // cout<<++a<<endl;
    // cout<<++(++a)<<endl; 
    // cout<<a<<endl;  可以发现++a始终在对同一个对象递增，联系到成员函数里，前置++需要返回引用

    test01();   
    test02();

    return 0;
}