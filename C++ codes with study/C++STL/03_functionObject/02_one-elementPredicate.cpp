// 4.2 谓词 —— pred
// 4.2.1 谓词概念
// 概念：
// 返回bool类型的仿函数称为谓词           //仿函数范围大于谓词
// 如果operator()接受一个参数，那么叫做一元谓词
// 如果operator()接受两个参数，那么叫做二元谓词

// 总结：参数只有一个的谓词，称为一元谓词

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class GreaterFive{
public:
    bool operator()(int v1){
        return v1 > 5;
    }
};

void test01(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //查找容器中有没有大于5的数字
    //GreatFive() 匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive()); //没有构造函数 使用默认构造，创建匿名对象,看起来像是函数调用
    if(it == v.end()){
        cout<<"没找到！"<<endl;
    }else{
        cout << "找到:" << *it << endl;
    }
}

int main() {
    test01();
    system("pause");
    return 0;
}
