//模仿老师递增写一个递减

#include <iostream>
using namespace std;

class MyInt{
    friend ostream& operator<<(ostream &cout, MyInt MyInt);

public:
    MyInt(){
        m_Num = 0;
    }
    //前置--
    MyInt& operator--(){
        --m_Num;
        return *this;
    }

    //后置--
    MyInt operator--(int){
        MyInt temp = *this;
        m_Num--;
        return temp;
    }

private:
    int m_Num;
};

//重载左移运算符
ostream& operator<<(ostream &cout, MyInt myint){
    cout<<myint.m_Num;
    return cout;
}

void test01(){
    MyInt myint;
    cout<<--myint<<endl;
    cout<<myint<<endl;
}

void test02(){
    MyInt myint;
    cout<<myint--<<endl;
    cout<<myint<<endl;
}

int main(){
    test01();
    test02();
    
    return 0;
}