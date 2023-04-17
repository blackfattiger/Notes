// 3.7.6 list 数据存取
// 功能描述：
// 对list容器中数据进行存取
// 函数原型：
// front(); //返回第一个元素。
// back(); //返回最后一个元素。

// 总结：
// list容器中不可以通过[]或者at方式访问数据
// 返回第一个元素 --- front
// 返回最后一个元素 --- back

#include<iostream>
using namespace std;
#include<list>

//数据存取
void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //cout << L1.at(0) << endl;//错误 不支持at访问数据
    //cout << L1[0] << endl; //错误 不支持[]方式访问数据
    cout << "第一个元素为： " << L1.front() << endl;
    cout << "最后一个元素为： " << L1.back() << endl;

    //验证迭代器是不支持随机访问的
    //list容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it = L1.begin();
    it++; //支持双向
    it--;
    //it = it + 1;//错误，不可以跳跃访问，即使是+1，如果 + 1或者 + 2 之类可以编译，则支持随机访问
    //此处是一个小技巧，容器太多你记每一个容器是否支持随机访问太麻烦，用这种方式直接验证即可
}

int main() {
    test01();
    system("pause");
    return 0;
}

