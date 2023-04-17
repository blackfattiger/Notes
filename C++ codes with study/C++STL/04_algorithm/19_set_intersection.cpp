// 5.6 常用集合算法
// 学习目标：
// 掌握常用的集合算法
// 算法简介：
// set_intersection // 求两个容器的交集
// set_union // 求两个容器的并集
// set_difference // 求两个容器的差集

// 5.6.1 set_intersection
// 功能描述：
// 求两个容器的交集
// 函数原型：
// set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// // 求两个集合的交集
// // 注意:两个集合必须是有序序列
// // beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 //
// dest 目标容器开始迭代器

// 总结：
// 求交集的两个集合必须的有序序列
// 目标容器开辟空间需要从两个容器中取小值
// set_intersection返回值既是交集中最后一个元素的位置

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void myPrint(int val){
    cout<<val<<" ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> vTarget;
    //目标容器需要提前开辟空间
    //最特殊的情况是 大容器包含小容器， 开辟空间时，取两个里面较小的size值给目标容器开辟空间
    // vTarget.resize(min(v1.size(), v2.size())); // 用min算法
    vTarget.resize(v1.size() > v2.size()? v2.size() : v1.size()); //用三目运算符

    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());//返回的是目标容器中交集的最后位置的迭代器

    // 如果不用ieEnd迭代器的话，多余的空间会赋值为0，比如目标容器大小为8个，但是交集只有4个，剩下的都会自动填0
    // for_each(vTarget.begin(), vTarget.end(), myPrint);
    for_each(vTarget.begin(), itEnd, myPrint);
    cout<<endl;
}





int main() {
    test01();
    system("pause");
    return 0;
}

