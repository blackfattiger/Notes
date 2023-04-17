// 设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。
// 通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
// 五名英雄信息如下：
// C++ {"刘备",23,"男"}, {"关羽",22,"男"}, {"张飞",20,"男"}, {"赵云",21,"男"}, {"貂蝉",19,"女"},

#include <iostream>
using namespace std;
struct Hero {
    string name;
    int age;
    string gender;
};


// void allocate(struct Teacher tea[], int len) {
//     //给老师赋值
//     string nameSeed = "ABCDE";
//     for (int i = 0; i < len; i++) {
//         tea[i].tname = "Teacher_";
//         tea[i].tname += nameSeed[i];
//         //每名老师有五个学生，还需要给学生赋值
//         for (int j = 0; j < 5; j++) {
//             tea[i].stu[j].sname = "Student_";
//             tea[i].stu[j].sname += nameSeed[j];
//             int random = rand() % 61 + 40;
//             tea[i].stu[j].score = random;
//         }

//     }
// }

void bubbleSort(struct Hero hero[],int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(hero[j].age > hero[j+1].age){
                struct Hero temp = hero[j];
                hero[j] = hero[j+1];
                hero[j+1] = temp;
            }
        }
    }

}

void printTeachers(struct Hero hero[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "英雄姓名： " << hero[i].name <<"年龄： "<<hero[i].age<<
        "性别： "<<hero[i].gender<< endl;
    }

}

int main() {
    struct Hero hero[5] = {
        {"刘备",23,"男"}, 
        {"关羽",22,"男"}, 
        {"张飞",20,"男"}, 
        {"赵云",21,"男"}, 
        {"貂蝉",19,"女"}
    };
    int len = sizeof(hero) / sizeof(hero[0]);
    // allocate(hero, len);
    //利用冒泡排序，按升序排列
    bubbleSort(hero, len);
    //打印信息
    printTeachers(hero, len);
    return 0;
}