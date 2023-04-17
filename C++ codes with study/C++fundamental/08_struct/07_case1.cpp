// 案例描述：
// 学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
// 设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
// 学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
// 最终打印出老师数据以及老师所带的学生数据。
#include <iostream>
using namespace std;
struct Student{
    string sname;
    double score;
};
struct Teacher{
    string tname;
    struct Student stu[5];
};

void allocate(struct Teacher tea[], int len){
    //给老师赋值
    string nameSeed = "ABCDE";
    for(int i = 0; i < len; i++){
        // tea[i].tname = "Teacher_" + nameSeed[i];  为什么这种方法不行，下面的就可以呢？
        tea[i].tname = "Teacher_";
        tea[i].tname += nameSeed[i];
        //每名老师有五个学生，还需要给学生赋值
        for(int j = 0; j < 5; j++){
            // tea[i].stu[j].sname = "Student_" + nameSeed[j];
            tea[i].stu[j].sname = "Student_";
            tea[i].stu[j].sname += nameSeed[j];
            int random = rand()%61 + 40;
            tea[i].stu[j].score = random;
        }

    }
}

void printTeachers(struct Teacher tea[], int len){
    for(int i = 0; i < len; i++ ){
        cout<<"老师姓名： "<<tea[i].tname<<endl;
        for(int j = 0; j < 5; j++){
            cout<<"\t学生姓名： "<<tea[i].stu[j].sname<<"分数： "<<tea[i].stu[j].score<<endl;
        }
    }

}

int main(){
    struct Teacher tea[3];
    int len = sizeof(tea) / sizeof(tea[3]);
    allocate(tea, len); 
    printTeachers(tea, len);
    return 0;
}