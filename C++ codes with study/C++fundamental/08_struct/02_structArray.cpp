// 作用：将自定义的结构体放入到数组中方便维护
// 语法：struct 结构体名 数组名[元素个数] = { {} , {} , ... {} }
#include <iostream>
using namespace std;
#include<string>
struct Student{
    string name;
    int age;
    int score;
};

int main(){
    struct Student stu[3] ={
        {"张三", 18, 100},
        {"李四", 20, 90},
        {"王五", 66, 60}
    } ;
    stu[2].name = "老六"; //可以通过.访问成员变量的方式来修改变量值
    for(int i = 0; i < 3; i++){
        cout<<"姓名： "<< stu[i].name<<" 年龄： "<<stu[i].age<<" 分数： "<<stu[i].score<<endl;
    }
    return 0;
}