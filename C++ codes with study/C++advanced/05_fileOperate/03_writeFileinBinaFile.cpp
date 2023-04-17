// 5.2 二进制文件
// 以二进制的方式对文件进行读写操作
// 打开方式要指定为 ==ios::binary==
// 5.2.1 写文件
// 二进制方式写文件主要利用流对象调用成员函数write
// 函数原型 ：ostream& write(const char * buffer,int len);
// 参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数

//二进制写文件可以写自定义的类

// 总结：文件输出流对象 可以通过write函数，以二进制方式写数据


#include<iostream>
using namespace std;
#include<fstream>
class Person{
// public:
//     Person(char name, int age){
//         m_Age = age;
//         m_Name = name;
//     }
public:
//C++中string本质是一个类，所以会把类写进文件，不建议使用string，就用C语言中的字符数组即可
    char m_Name[64] = "张三";
    int m_Age;
};
//1.包含头文件

void test01(){
    Person p ;
    p.m_Age = 18;
//2.创建流对象
    ofstream ofs;
//3.打开文件
    ofs.open("Person.txt", ios::out | ios::binary);
//4.写文件
    ofs.write((const char *)&p, sizeof(p));
//5.关闭文件
    ofs.close();
}

int main(){
    test01();

    return 0;
}
