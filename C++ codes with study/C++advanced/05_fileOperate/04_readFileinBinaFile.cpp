//读与写是相对的，我们要读，那么在内存里就要先写进去，写进内存，编译器才能给我们显示出来

//总结： 文件输入流对象 可以通过read函数，以二进制方式读数据

#include<iostream>
using namespace std;
#include<fstream>

class Person{
public:
    char m_Name[64] = "张三";
    int m_Age;
};

void test01(){
    Person p;
    ifstream ifs;
    ifs.open("Person.txt", ios::in | ios::binary);
    if(!ifs.is_open()){
        cout<<"文件打开失败！"<<endl;
        return;
    }
    ifs.read((char *)&p, sizeof(p));
    cout<<p.m_Name<<endl;
    cout<<p.m_Age<<endl;
}

int main(){
    test01();
    return 0;
}