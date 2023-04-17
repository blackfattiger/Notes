
// 演讲比赛流程管理系统
// 1、 演讲比赛程序需求
// 1.1 比赛规则
// 学校举行一场演讲比赛，共有12个人参加。比赛共两轮，第一轮为淘汰赛，第二轮为决赛。
// 比赛方式：分组比赛，每组6个人；选手每次要随机分组，进行比赛
// 每名选手都有对应的编号，如 10001 ~ 10012
// 第一轮分为两个小组，每组6个人。 整体按照选手编号进行抽签后顺序演讲。
// 十个评委分别给每名选手打分，去除最高分与最低分，求的平均分为本轮选手的成绩。
// 当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮的比赛。
// 第二轮为决赛，前三名胜出
// 每轮比赛过后需要显示晋级选手的信息

// 1.2 程序功能
// 开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
// 查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
// 清空比赛记录：将文件中数据清空
// 退出比赛程序：可以退出当前程序

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
// #include"speechManager.h"
#include"speechManager.cpp"
#include"sperror.h"
#include<ctime>

int main(){
    //添加随机数种子
    srand((unsigned int)time(NULL));

    SpeechManager sm;

    // 这里最好把choice定义为char，否则输入的不是数字，choice就会是0
    int choice = 0; //用于存储用户的选择
    while (true)
    {
        sm.show_Menu();
        cout<<"请输入您的选择："<<endl;
        cin>>choice;  //接收用户选项

        // //测试12名选手的创建
        // for(map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++){
        //     cout<<"编号："<<(*it).first
        //     <<"\t姓名："<<(*it).second.m_Name
        //     <<"\t分数："<<(*it).second.m_Score[0]<<endl;
        // }

        while(choice != 0 && choice != 1 && choice != 2 && choice != 3){
            cout<<"请输入正确的选项:"<<endl;
            cin>>choice;  //接收用户选项
        }

        switch (choice)
        {
        case 1: //开始比赛
            sm.startSpeech();
            /* code */
            break;
        case 2: //查看记录
            sm.showRecord();
            /* code */
            break;
        case 3: //清空记录
            sm.clearRecord();
            /* code */
            break;
        case 0: //退出系统
            sm.exitSystem();
            // return 0;  不要在此处用return直接退出，提供一个方法来退出
            break;
        default:
            system("cls"); //清屏
            break;
        }
    }

    system("pause");
    return 0 ;
}

