// 5.2.6 count_if
// 功能描述：
// 按条件统计元素个数
// 函数原型：
// count_if(iterator beg, iterator end, _Pred);
// // 按条件统计元素出现次数
// // beg 开始迭代器
// // end 结束迭代器
// // _Pred 谓词

// 总结：按值统计用count，按条件统计用count_if

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Greater4
{
public:
    bool operator()(int val)
    {
        return val >= 4;
    }
};

//内置数据类型
void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    int num = count_if(v.begin(), v.end(), Greater4()); //第三个参数为谓词， 放入匿名函数对象
    cout << "大于4的个数为： " << num << endl;
}

//自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

class Greater20{  
public:
    bool operator()(const Person & p){  /*这个谓词也可以放在Person类里实现，但是由于其中有构造函数了，默认构造被取消，
                                        所以需要自己写一个默认构造的空实现，才可以在创建匿名函数对象时不填写参数*/
        return p.m_Age > 20;
    }
};

void test02(){
    vector<Person> v;
    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 25);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    int num = count_if(v.begin(), v.end(), Greater20());
    cout << "大于20岁的个数：" << num << endl;

}

int main() {
    //test01();
    test02();
    system("pause");
    return 0;
}
