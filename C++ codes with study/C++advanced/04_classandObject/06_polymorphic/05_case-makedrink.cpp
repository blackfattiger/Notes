//看了老师的代码，我觉得我的代码很靠近面向过程，没有将各个模块分装出来

#include<iostream>
using namespace std;

// //制作饮品
// class drink{
// public:
//     virtual void make() = 0;

// };

// //冲咖啡
// class cafe: public drink{
// public:
// //我这样写，之后添加新功能也是需要改源码
//     void make(){
//         cout<<"1.煮水"<<endl;
//         cout<<"2.冲泡咖啡"<<endl;
//         cout<<"3.倒入杯中"<<endl;
//         cout<<"4.加糖和牛奶"<<endl;
//     }
// };

// //冲茶叶
// class tea: public drink{
// public:
//     void make(){
//         cout<<"1.煮水"<<endl;
//         cout<<"2.冲泡茶叶"<<endl;
//         cout<<"3.倒入杯中"<<endl;
//         cout<<"4.加柠檬"<<endl;
//     }
// };

// void test01(){
//     drink * d = new cafe;
//     d->make();
//     delete d;
//     d = new tea;
//     d->make();
//     delete d;
// }

class AbstractDrink{
public:
    //烧水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加入辅料
    virtual void PutSomething() = 0;
    //整合流程
    void make(){
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

//冲咖啡
class Cafe: public AbstractDrink{
public:
    //烧水 
    virtual void Boil() { 
        cout << "煮农夫山泉!" << endl; 
    } 
    //冲泡 
    virtual void Brew() { 
        cout << "冲泡咖啡!" << endl; 
    } 
    //倒入杯中 
    virtual void PourInCup() { 
        cout << "将咖啡倒入杯中!" << endl; 
    } 
    //加入辅料 
    virtual void PutSomething() { 
        cout << "加入牛奶!"<< endl; 
    }
};

//冲茶叶
class Tea: public AbstractDrink{
public:
    //烧水 
    virtual void Boil() { 
        cout << "煮矿泉水!" << endl; 
    } 
    //冲泡 
    virtual void Brew() { 
        cout << "冲泡茶叶!" << endl; 
    } 
    //倒入杯中 
    virtual void PourInCup() { 
        cout << "将茶水倒入杯中!" << endl; 
    } 
    //加入辅料 
    virtual void PutSomething() { 
        cout << "加入枸杞!"<< endl; 
    }
};

//业务函数，专门做这一项工作
void doWork(AbstractDrink * abs){
    abs->make();
    delete abs; //释放堆区内存，防止内存泄漏
}

void test01(){
    doWork(new Cafe);
    cout<<"--------------------"<<endl;
    doWork(new Tea);
}

int main(){
    test01();


    return 0;
}