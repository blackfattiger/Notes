// 5.5.2 fill
// 功能描述：
// 向容器中填充指定的元素
// 函数原型：
// fill(iterator beg, iterator end, value);
// // 向容器中填充元素
// // beg 开始迭代器
// // end 结束迭代器
// // value 填充的值

// 总结：利用fill可以将容器区间内元素填充为 指定的值

#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>

class MyPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};

void test01(){
    vector<int> v;
    v.resize(10); //resize的重载版本也可用于前期填充

    fill(v.begin(), v.end(), 100); //fill 用于后期填充

    for_each(v.begin(), v.end(), MyPrint());
}   

int main(){
    test01();
    return 0;
}


