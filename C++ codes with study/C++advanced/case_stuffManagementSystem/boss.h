#pragma once
#include"worker.h" //包含这个头文件并不相当于继承，只是说可以在这个文件中使用包含的头文件

class Boss: public Worker{
public:
    Boss(int Id, string name, int DeptId); //构造函数，给属性赋值

    virtual void showInfo(); //显示个人信息 , 子类处virtual可写可不写

    virtual string getDeptName(); //显示岗位名称


};
