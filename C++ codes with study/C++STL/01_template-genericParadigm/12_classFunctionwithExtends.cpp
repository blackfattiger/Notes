// 1.3.5 类模板与继承
// 当类模板碰到继承时，需要注意一下几点：
// 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
// 如果不指定，编译器无法给子类分配内存
// 如果想灵活指定出父类中T的类型，子类也需变为类模板

// 总结：如果父类是类模板，子类需要指定出父类中T的数据类型，才可以拿到父类中的对象

#include<iostream>
using namespace std;

template<class T>
class Base
{
    T m;
};

//class Son:public Base //错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son :public Base<int> //必须指定一个类型
{
};

void test01()
{
    Son c;
}

//类模板继承类模板 ,可以用T2指定父类中的T类型
template<class T1, class T2>
class Son2 :public Base<T2>
{
public:
    Son2()
    {
        cout << "T1的类型为："<<typeid(T1).name() << endl;
        cout << "T2的类型为："<<typeid(T2).name() << endl;
    }

    T1 obj;
};

void test02()
{
    Son2<int, char> child1; //此处相当于给T1指定为int,给T2指定为char,然后T1的int用来定义成员属性obj,T2的char用来定义继承时父类的模板参数类型
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
