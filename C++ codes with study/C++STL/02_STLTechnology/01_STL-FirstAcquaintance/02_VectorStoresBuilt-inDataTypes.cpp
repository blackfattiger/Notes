// 2.5 容器算法迭代器初识
// 了解STL中容器、算法、迭代器概念之后，我们利用代码感受STL的魅力
// STL中最常用的容器为Vector，可以理解为数组，下面我们将学习如何向这个容器中插入数据、并遍历这个容器
// 2.5.1 vector存放内置数据类型
// 容器： vector
// 算法： for_each
// 迭代器： vector<int>::iterator


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void MyPrint(int val)
{
    cout << val << endl;
}

void test01(){
    //创建了一个vector容器，数组
    vector<int> v;

    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //通过迭代器访问容器中的数据
    //我这样理解: 容器/模板是 类，迭代器是类里的方法，该方法返回一个指针
    //每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
    //vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
    vector<int>::iterator itBegin = v.begin(); //起始迭代器 指向容器中第一个元素
    vector<int>::iterator itEnd = v.end();     //结束迭代器 指向容器中最后一个元素的下一个位置

    //第一种遍历方式
    while(itBegin != itEnd){
        cout<<*itBegin<<endl;
        itBegin++;
    }

    //第二种遍历方式
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<<*it<<endl;
    }

    //第三种遍历方式
    //使用STL提供标准遍历算法 头文件 algorithm
    for_each(v.begin(),v.end(),MyPrint); //这里的MyPrint称为回调函数    

}

int main(){
    test01();
    system("pause");
    return 0;
}

