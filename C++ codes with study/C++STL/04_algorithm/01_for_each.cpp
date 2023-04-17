// 5 STL- 常用算法
// 概述:
// 算法主要是由头文件 <algorithm> <functional> <numeric> 组成。
// <algorithm> 是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
// <numeric> 体积很小，只包括几个在序列上面进行简单数学运算的模板函数
// <functional> 定义了一些模板类,用以声明函数对象。
// 5.1 常用遍历算法
// 学习目标：
// 掌握常用的遍历算法

// 算法简介：
// for_each //遍历容器
// transform //搬运容器到另一个容器中
// 5.1.1 for_each
// 功能描述：
// 实现遍历容器
// 函数原型：
// for_each(iterator beg, iterator end, _func);      //最后一个参数_func为回调函数，即函数返回时调用的函数
// 遍历算法 遍历容器元素
// beg 开始迭代器
// end 结束迭代器
// _func 函数或者函数对象
/* 查看源码可知，第三个参数回调函数，在for_each返回前，会将迭代器解引用，然后将解引用后得到
   的迭代器现在所指的对象交给回调函数_func，然后return时调用回调函数_func*/

// 总结：for_each在实际开发中是最常用遍历算法，需要熟练掌握

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//普通函数
void print01(int val){
    cout<<val<<" ";
}

//函数对象
class print02{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};

//for_each算法基本用法
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //遍历算法
    for_each(v.begin(), v.end(), print01); //普通函数只需放入名称
    cout<<endl;

    for_each(v.begin(), v.end(), print02()); //仿函数需要放入对象
    cout<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}
