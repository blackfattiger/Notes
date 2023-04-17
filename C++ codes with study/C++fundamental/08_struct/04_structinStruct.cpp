// 总结：在结构体中可以定义另一个结构体作为成员，用来解决实际问题
#include <iostream>
using namespace std;
// 作用：结构体中的成员可以是另一个结构体
// 例如：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体

//学生结构体
struct Student
{
    string name;
    int age;
    int score;
};
//老师结构体
struct Teacher
{
    int id;//教室编号
    string name;
    int age;//年龄
    struct Student stu;//子结构体，学生
};

int main(){
    struct Teacher t1;
    t1.id = 10000;
    t1.name = "老王";
    t1.age = 40;
    t1.stu.name = "张三";
    t1.stu.age = 18;
    t1.stu.score = 100;
    cout << "教师 职工编号： " << t1.id << " 姓名： " << t1.name << " 年龄： " << t1.age << endl;
    cout << "辅导学员 姓名： " << t1.stu.name << " 年龄：" << t1.stu.age << " 考试分数： " << t1.stu.score << endl;

    return 0;
}