//大部分算法需要仿函数时，需要谓词的就重载 () 号， 现在遇到的其他的不需要谓词的与值操作有关的，如大小、相等操作基本都是重载 == 号
//根据实际情况吧， 如果需要直接输出之类的 还是重载 () 号

// 5.4.2 replace
// 功能描述：
// 将容器内指定范围的旧元素修改为新元素
// 函数原型：
// replace(iterator beg, iterator end, oldvalue, newvalue);
// // 将区间内旧元素 替换成 新元素
// // beg 开始迭代器
// // end 结束迭代器
// // oldvalue 旧元素
// // newvalue 新元素

// 总结：replace会替换区间内满足条件的元素

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);
    cout << "替换前：" << endl;
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;

    cout << "替换后：" << endl;
    //将容器中的20 替换成 2000
    replace(v.begin(), v.end(), 20,2000);              // 自定义数据类型需要重载==号
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}

int main() {
    test01();
    system("pause");
    return 0;
}

