// 4.6 继承
// 继承是面向对象三大特性之一
// 有些类与类之间存在特殊的关系，例如下图中：
// 我们发现，定义这些类时，下级别的成员除了拥有上一级的共性，还有自己的特性。
// 这个时候我们就可以考虑利用继承的技术，减少重复代码


// 4.6.1 继承的基本语法
// 例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处

//继承的好处：减少重复代码
//语法： class 子类 : 继承方式 父类
// 如：class A : public B;
// A 类称为子类 或 派生类
// B 类称为父类 或 基类
// 派生类中的成员，包含两大部分：
// 一类是从基类继承过来的，一类是自己增加的成员。
// 从基类继承过过来的表现其共性，而新增的成员体现了其个性。



#include <iostream>
using namespace std;


//普通实现
//Java页面 
// class Java 
// { 
// public: 
//     void header() { 
//         cout << "首页、公开课、登录、注册...（公共头部）" << endl; 
//     } 
//     void footer() { 
//         cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl; 
//     } 
//     void left() { 
//         cout << "Java,Python,C++...(公共分类列表)" << endl; 
//     } 
//     void content() { 
//         cout << "JAVA学科视频" <<endl; 
//     } 
// };

// //python页面 
// class Python 
// { 
// public: 
//     void header() { 
//         cout << "首页、公开课、登录、注册...（公共头部）" << endl; 
//     } 
//     void footer() { 
//         cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl; 
//     } 
//     void left() { 
//         cout << "Java,Python,C++...(公共分类列表)" << endl; 
//     } 
//     void content() { 
//         cout << "Python学科视频" <<endl; 
//     } 
// };

// //Cpp页面 
// class CPP 
// { 
// public: 
//     void header() { 
//         cout << "首页、公开课、登录、注册...（公共头部）" << endl; 
//     } 
//     void footer() { 
//         cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl; 
//     } 
//     void left() { 
//         cout << "Java,Python,C++...(公共分类列表)" << endl; 
//     } 
//     void content() { 
//         cout << "CPP学科视频" <<endl; 
//     } 
// };

//继承实现：把重复的东西都抽象成一个公共的页面
class BasePage{
public: 
    void header() { 
        cout << "首页、公开课、登录、注册...（公共头部）" << endl; 
    } 
    void footer() { 
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl; 
    } 
    void left() { 
        cout << "Java,Python,C++...(公共分类列表)" << endl; 
    } 
};

//Java页面
class Java: public BasePage{
public:
    void content() { 
        cout << "Java学科视频" <<endl; 
    } 
};

//Python页面
class Python: public BasePage{
public:
    void content() { 
        cout << "Python学科视频" <<endl; 
    } 
};

//CPP页面
class CPP: public BasePage{
public:
    void content() { 
        cout << "CPP学科视频" <<endl; 
    } 
};

void test01() { 
    //Java页面 
    cout << "Java下载视频页面如下： " << endl; 
    Java ja; 
    ja.header(); 
    ja.footer(); 
    ja.left(); 
    ja.content(); 
    cout << "--------------------" <<endl;
    //Python页面
    cout << "Python下载视频页面如下： " << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "--------------------" << endl;
    //C++页面
    cout << "C++下载视频页面如下： " << endl;
    CPP cp;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
}


int main(){

    test01();


    return 0;
}