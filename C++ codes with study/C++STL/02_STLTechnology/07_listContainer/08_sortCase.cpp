// 3.7.8 排序案例
// 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
// 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

// 总结：
// 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
// 高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂

#include<iostream>
using namespace std;
#include<list>
#include<algorithm>

class Person{
public:
    Person(string name, int age, int height){
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }
    int m_Age;
    string m_Name;
    int m_Height;
};

//指定排序规则
bool comparePerson(Person &p1, Person &p2){
    //按照年龄 升序
    if(p1.m_Age == p2.m_Age){
        //年龄相同按照身高进行降序
        return p1.m_Height > p2.m_Height;
    }else{
        return p1.m_Age < p2.m_Age;
    }
}



// void sortPerson(const list<Person> & L){
//     L.sort(myCompare);
// }

void printList(const list<Person> & L ){
    for(list<Person>::const_iterator it = L.begin(); it != L.end(); it++){
        cout<<"姓名： "<<(*it).m_Name<<"\t年龄： "<<it->m_Age<<"\t身高： "<<it->m_Height<<endl;
    }
}

void test01(){
    list<Person> L; //创建容器
    //准备数据
   Person p1("刘备", 35 , 175);
    Person p2("曹操", 45 , 180);
    Person p3("孙权", 40 , 170);
    Person p4("赵云", 25 , 190);
    Person p5("张飞", 35 , 160);
    Person p6("关羽", 35 , 200);

    //将数据放入链表中
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    cout<<"排序前："<<endl;
    printList(L);

    // sortPerson(L)
    L.sort(comparePerson);
    cout<<"排序后："<<endl;
    printList(L);
}

int main(){
    test01();

    system("pause");
    return 0;
}