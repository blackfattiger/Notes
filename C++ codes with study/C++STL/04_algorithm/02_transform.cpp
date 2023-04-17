// 5.1.2 transform
// 功能描述：
// 搬运容器到另一个容器中
// 函数原型：
// transform(iterator beg1, iterator end1, iterator beg2, _func); //最后一个参数为仿函数或回调函数
// //beg1 源容器开始迭代器
// //end1 源容器结束迭代器
// //beg2 目标容器开始迭代器
// //_func 函数或者函数对象

// 总结： 搬运的目标容器必须要提前开辟空间，否则无法正常搬运

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int transform(int val){
    return val;
}

class Transform
{
public:
    int operator()(int val)
    {
        return val;
    }
};

void print(int val){
    cout<<val<<" ";
}

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
}
};

void test01(){
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> v2;   //目标容器
    v2.resize(v.size());   // 目标容器需要提前开辟空间

    // transform(v.begin(), v.end(), v2.begin(), transform);
    transform(v.begin(), v.end(), v2.begin(), Transform());  //迁移时指定操作，因为放入的是int类型，如果保持原来的数据迁移，返回值与传入的值保持一致即可

    // for_each(v2.begin(), v2.end(), print);
    for_each(v2.begin(), v2.end(), MyPrint());
    cout<<endl;

}

int main() {
    test01();
    system("pause");
    return 0;
}
