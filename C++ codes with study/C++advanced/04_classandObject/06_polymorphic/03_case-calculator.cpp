// 4.7.2 多态案例一-计算器类
// 案例描述：
// 分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
// 多态的优点：
// 代码组织结构清晰
// 可读性强
// 利于前期和后期的扩展以及维护

// 总结：C++开发提倡利用多态设计程序架构，因为多态优点很多

#include <iostream>
using namespace std;

//普通写法
//如果要提供新的运算，需要修改源码
class Calculator{
public:
    int getResult(string oper){
        if(oper == "+"){
            return m_Num1 + m_Num2;
        }else if(oper == "-"){
            return m_Num1 - m_Num2; 
        }else if(oper == "*"){
            return m_Num1 * m_Num2; 
        }
    }
public:
    int m_Num1;
    int m_Num2;
};

void test01(){
    Calculator ca;
    ca.m_Num1 = 10;
    ca.m_Num2 = 10;
    cout<<ca.m_Num1<< "+"<< ca.m_Num2<<" = "<<ca.getResult("+")<<endl;
}


//多态实现 
//抽象计算器类 
//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
class AbstractCalculator{
public:
    virtual int getResult(){
        return 0;
    }
public:
    int m_Num1;
    int m_Num2;
};

//加法计算器
class AddCalculator: public AbstractCalculator{
public:
    virtual int getResult(){
        return m_Num1 + m_Num2;
    }
};

//减法计算器
class SubCalculator: public AbstractCalculator{
public:
    virtual int getResult(){
        return m_Num1 - m_Num2;
    }
};

//乘法计算器
class MulCalculator: public AbstractCalculator{
public:
    virtual int getResult(){
        return m_Num1 * m_Num2;
    }
};

//即时后面要增加一个计算器 不用去修改源码
class DevCalculator: public AbstractCalculator{
public:
    int getResult(){
        if(m_Num2 != 0){
            return (m_Num1 / m_Num2);
        }
    }
};

void test02(){
    AbstractCalculator * abc = new AddCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout<<abc->m_Num1<<" + "<<abc->m_Num2<<" = "<<abc->getResult()<<endl;
    delete abc; //用完了记得销毁

    abc = new DevCalculator;
    abc->m_Num1 = 100;
    abc->m_Num2 = 100;
    cout<<abc->m_Num1<<" / "<<abc->m_Num2<<" = "<<abc->getResult()<<endl;
    delete abc; //用完了记得销毁

}

int main(){
    test01();
    test02();
    return 0;
}
