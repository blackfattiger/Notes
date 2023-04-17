// 作用：将结构体作为参数向函数中传递
// 传递方式有两种：
// 值传递
// 地址传递

#include <iostream>
using namespace std;
//学生结构体定义 
struct student { 
    //成员列表 
    //姓名
    string name; 
    //年龄
    int age;
    //分数
    int score;  
};

//值传递
void printStudent1(struct student stu){
    stu.age = 28;
    cout << "子函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score <<
endl; 

}

//地址传递
void printStudent2(struct student* p){
    p->age = 28; 
    cout << "子函数中 姓名：" << p->name << " 年龄： " << p->age << " 分数：" << p->score <<
endl; 

}

int main(){
    student stu = { "张三",18,100};
    //值传递
    printStudent1(stu);
    cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;
    cout << endl;
    //地址传递
    printStudent2(&stu);
    cout << "主函数中 姓名：" << stu.name << " 年龄： " << stu.age << " 分数：" << stu.score << endl;



    return 0;
}