// 5.2 常用查找算法
// 学习目标：
// 掌握常用的查找算法
// 算法简介：
// find //查找元素
// find_if //按条件查找元素
// adjacent_find //查找相邻重复元素
// binary_search //二分查找法
// count //统计元素个数
// count_if //按条件统计元素个数

// 5.2.1 find
// 功能描述：
// 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
// 函数原型：
// find(iterator beg, iterator end, value);
// // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// // beg 开始迭代器
// // end 结束迭代器
// // value 查找的元素

// 总结： 利用find可以在容器中找指定的元素，返回值是迭代器

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//查找内置数据类型
void test01(){
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i + 1);
    }
    //查找容器中是否有 5 这个元素

    vector<int>::iterator it = find(v.begin(), v.end(), 5);

    if (it == v.end())
    {
        cout << "没有找到!" << endl;
    }
    else
    {
        cout << "找到:" << *it << endl;
    }
}

class Person {
public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    //重载 ==  底层find才能知道如何对比Person数据类型
    bool operator==(const Person & p){
        if(this->m_Age = p.m_Age && this->m_Name == p.m_Name){
            return true;
        }else{
            return false;
        }
    }
public:
    string m_Name;
    int m_Age;
};

// 查找自定义的数据类型
void test02(){
    vector<Person> v;
    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //直接放p2， 容器中肯定有这个人
    // vector<Person>::iterator it = find(v.begin(), v.end(), p2);

    //实际用途应该是这样，对比外界的数据和容器中的数据有无重合
    Person pp("ddd", 40);
    vector<Person>::iterator it = find(v.begin(), v.end(), pp);

    if (it == v.end())
    {
        cout << "没有找到!" << endl;
    }
    else
    {
        cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;
    }
}

int main(){

    test01();
    test02();
    return 0;
}


