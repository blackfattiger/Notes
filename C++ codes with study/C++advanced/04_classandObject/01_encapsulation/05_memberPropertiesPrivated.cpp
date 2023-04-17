// 4.1.3 成员属性设置为私有
// 优点1：将所有成员属性设置为私有，可以自己控制读写权限
// 优点2：对于写权限，我们可以检测数据的有效性

#include <iostream>
using namespace std;

//设计人类
class Person{
// 属性
    string m_Name;//姓名  可读可写 set get
    int m_Age;//年龄    只读 get 
    string m_Lover;//情人  只写 set

public:
    //设置姓名
    void setName(string name){
        m_Name = name;
    }
    //获取姓名
    string getName(){
        return m_Name;
    }
    //获取年龄  改为可读可写，如果想修改（年龄的范围为0~150之间）
    int getAge(){
        return m_Age;
    }
    void setAge(int age){
        if(age < 0 || age > 150){
            m_Age = 0;
            cout<<"你这个老妖精"<<endl;
            return;
        }
        m_Age = age;
    }
    //设置情人
    void setLover(string name){
        m_Lover = name;
    }
    
};


int main(){
    Person p;
    //姓名设置
    p.setName("张三");
    cout << "姓名： " << p.getName() << endl;
    //年龄设置
    p.setAge(18);
    cout << "年龄： " << p.getAge() << endl;
    //情人设置
    p.setLover("苍井");
    //cout << "情人： " << p.m_Lover << endl; //只写属性，不可以读取
    system("pause");

    return 0;
}