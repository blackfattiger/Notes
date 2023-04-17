
// 在整个比赛中，需要一个东西来管理整个比赛流程，所以要创建管理类，用面向对象的技术来实现
// 其实就是把面向过程中封装的一些控制函数放入管理类中，而不是放在主函数文件中，避免主函数文件过于繁琐
// 创建管理类
// 功能描述： 
// 提供菜单界面与用户交互
// 对演讲比赛流程进行控制————封装函数
// 与文件的读写交互


#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"speaker.h"
#include<vector>

class SpeechManager{
public:     
    //构造函数  
    SpeechManager();

    //展示菜单
    void show_Menu();

    //退出系统
    void exitSystem();

    //初始化操作
    // 封装、多态、继承，这样子封装成一个专门的函数更有条理，而且之后也可以复用  ————解耦合
    void initSpeech();

    //创建选手
    void createSpeaker();

    //开始比赛   比赛整个流程控制函数   
    void startSpeech();

    //抽签
    void speechDraw();

    // //打印操作
    // void operator()();

    //比赛
    void speechContest();

    //显示比赛分数
    void showScore();

    //保存分数
    void saveRecord();

    //读取记录
    void loadRecord();

    //显示记录
    void showRecord();

    //清空记录
    void clearRecord();

    //析构函数
    ~SpeechManager();

public: //成员属性
    //把容器写成成员属性 
    vector<int> v1; //存放选手的编号容器    比赛选手容器 12人
    vector<int> v2; //第一轮晋级的选手   6人
    vector<int> vVictory; //获得前三的选手 3人
    map<int, Speaker> m_Speaker; //存放 编号以及对应的选手

    int m_Index; //记录比赛的轮数
    
    //文件为空的标志
    bool fileIsEmpty;

    //存放往届记录的容器
    map<int, vector<string>> m_Record;
};