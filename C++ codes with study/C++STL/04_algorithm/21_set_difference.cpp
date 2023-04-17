// 5.6.3 set_difference
// 功能描述：
// 求两个集合的差集
// 函数原型：
// set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// // 求两个集合的差集
// // 注意:两个集合必须是有序序列
// // beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 //
// dest 目标容器开始迭代器

// 总结：
// 求差集的两个集合必须的有序序列
// 目标容器开辟空间需要从两个容器取较大值
// set_difference返回值既是差集中最后一个元素的位置

//差集要看对象， 如果是v1与v2的差集，就是在v1中不在v2中的元素， 反之， 如果是v2与v1的差集，就是在v2中不在v1中的元素

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class myPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};

void test01(){
    vector<int> v1;
    vector<int> v2;

    for(int i = 0; i < 10; i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }

    vector<int> vTarget;
    //开辟目标容器的空间
    //最极端的情况是两个容器没有交集，或者小容器包含在大容器内部， 所以取两个里面较大的size值给目标容器开辟空间
    vTarget.resize(max(v1.size(), v2.size()));

    //v1和v2的差集为
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin()); //返回的是目标容器并集中的最后一个元素的位置的迭代器

    // for_each(vTarget.begin(), vTarget.end(), myPrint); //不用vTarget.end()也是因为并集并没有将vTarget容器填充满，导致后面一些元素的位置是0
    for_each(vTarget.begin(), itEnd, myPrint());
    cout<<endl;
    cout<<"-------------------------"<<endl;

    //v2和v1的差集为
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin()); //返回的是目标容器并集中的最后一个元素的位置的迭代器

    // for_each(vTarget.begin(), vTarget.end(), myPrint); //不用vTarget.end()也是因为并集并没有将vTarget容器填充满，导致后面一些元素的位置是0
    for_each(vTarget.begin(), itEnd, myPrint());
    cout<<endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}


