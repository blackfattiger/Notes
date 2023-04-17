// 总结：结构体指针可以通过 -> 操作符 来访问结构体中的成员
#include <iostream>
using namespace std;
//结构体定义 
struct student { 
    //成员列表
    //姓名 
    string name;
    //年龄  
    int age; 
    //分数 
    int score;  };

int main(){
    //创建学生结构体变量
    struct student stu = { "张三",18,100, };
    // int* p = &stu;  这是错的!
    //通过指针指向结构体变量
    struct student * p = &stu;
    p->score = 80; //结构体指针通过 -> 操作符可以访问成员
    //如果是结构体数组，如struct student stu[3]，struct student * p = stu;
    //就不用&这个取地址符了，而且不需要p->name来访问成员，直接p[2].name即可
    //所以说指针和数组其实是一类东西
    cout << "姓名：" << p->name << " 年龄：" << p->age << " 分数：" << p->score << endl;

    return 0;
}