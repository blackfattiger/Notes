// 3.7.7 list 反转和排序
// 功能描述：
// 将容器中的元素反转，以及将容器中的数据进行排序
// 函数原型：
// reverse(); //反转链表
// sort(); //链表排序

// 总结：
// 反转 --- reverse
// 排序 --- sort （成员函数）

#include<iostream>
using namespace std;
#include<list>
#include<algorithm>

void printList(const list<int>& L){
    for(list<int>::const_iterator it = L.begin(); it != L.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

bool myCompare(int val1 , int val2)
{
    //降序就让 第一个数 > 第二个数
    return val1 > val2;
}

void test01(){
    list<int> L;
    L.push_back(90);
    L.push_back(30);
    L.push_back(20);
    L.push_back(70);
    printList(L);

    //反转容器的元素
    L.reverse();
    printList(L);

    //排序
    cout<<"排序前："<<endl;
    printList(L);

    //所有不支持随机访问迭代器的容器，不可以用标准算法
    //不支持随机访问迭代器的容器，内部会提供一些对应算法
    // sort(L.begin(), L.end());

    L.sort();  //默认排序规则，从小大大升序
    cout<<"排序后："<<endl; 
    printList(L);

    L.sort(myCompare); //指定规则，从大到小
    printList(L);
}

int main(){
    test01();
    system("pause");
    return 0;

}