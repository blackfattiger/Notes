// 2.5.2 Vector存放自定义数据类型
// 学习目标：vector中存放自定义数据类型，并打印输出

#include<iostream>
using namespace std;
#include<vector>

//自定义数据类型
class Person {
public:
    Person(string name, int age) {
        m_Name = name;
        m_Age = age;
    }
public:
    string m_Name;
    int m_Age;
};

//存放对象
void test01(){
    vector<Person> v;
    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    //遍历数据
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){ 
        // cout<<"姓名："<<(*it).m_Name<<" 年龄："<<(*it).m_Age<<endl; // 小技巧：想看 *it 是什么，就看vector<>尖括号模板参数列表里面是什么
        cout<<"姓名："<<it->m_Name<<" 年龄："<<it->m_Age<<endl;        // *it 即为<>里面对应的类型
    }
}

//放对象指针
void test02() {
    vector<Person*> v;
    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

     //遍历数据
    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
        // cout<<"::姓名："<<(*(*it)).m_Name<<" 年龄："<<(*(*it)).m_Age<<endl; //只要能清楚的知道指针指向的是什么类型，就能把里面的数据拿到手
        cout<<"::姓名："<<(*it)->m_Name<<" 年龄："<<(*it)->m_Age<<endl;        
    }
}

/* 做一下解释： vector<存放数据类型>：：迭代器 it=v.begin()，只需要记住 it是一个迭代器指针，
指向一个vector容器（里面是定义的数据类型）=理解为int *it=10*/
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
