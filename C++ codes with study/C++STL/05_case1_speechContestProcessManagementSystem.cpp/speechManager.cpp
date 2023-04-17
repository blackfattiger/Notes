// 老师已经分了两个类了，其实类中实现就相当于面向过程。如果不嫌麻烦可以把每个你认为后期需要再维护的函数封装成一个类也行啊

#include"speechManager.h"
#include<vector>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
#include<fstream>

SpeechManager::SpeechManager(){
    // 一般不需要写this, 当成员函数的形参和成员数据名字一样时，且需要调用该成员数据时，需要写this来区分。
    //初始化属性
    this->initSpeech();
    //创建选手
    this->createSpeaker();  //在类对象构造的时候，这些东西就应该准备好，所以不在startSpeech函数里创建
    //在初始化时加载往届记录
    this->loadRecord();
}

void SpeechManager::show_Menu(){
    cout << "********************************************" << endl;
    cout << "************* 欢迎参加演讲比赛 ************" << endl;
    cout << "************* 1.开始演讲比赛 *************" << endl;
    cout << "************* 2.查看往届记录 *************" << endl;
    cout << "************* 3.清空比赛记录 *************" << endl;
    cout << "************* 0.退出比赛程序 *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void SpeechManager::exitSystem(){
    cout<<"欢迎下次使用！"<<endl;
    system("pause");
    exit(0);  //return是函数的退出，exit是线程的退出
}


    //初始化操作
void SpeechManager::initSpeech(){
    //容器保证为空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    //初始化比赛轮数
    this->m_Index = 1;

    //将记录的容器清空,不然之后每次里面都有数据
    this->m_Record.clear();
}

    //创建选手
void SpeechManager::createSpeaker(){
    string nameSeed = "ABCDEFGHJKLM";  
    for(int i = 0; i < nameSeed.size(); i++){
        Speaker sp;
        sp.m_Name = "选手";
        sp.m_Name += nameSeed[i];
        for(int j = 0; j < 2; j++){
            sp.m_Score[j] = 0;
        }

        //创建12名选手编号并放入到容器中
        this->v1.push_back(10001+i);
        //选手编号 以及对应的选手 存放到map容器中
        this->m_Speaker.insert(make_pair(10001+i, sp));
    }
}

    //抽签
void SpeechManager::speechDraw(){
    cout<<"现在开始第"<<this->m_Index<<"轮比赛抽签"<<endl;
    cout<<"抽签后演讲顺序如下："<<endl;
    if(this->m_Index == 1){
        //第一轮比赛
        random_shuffle(v1.begin(), v1.end());
        for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }else{
        //第二轮比赛
        random_shuffle(v2.begin(), v2.end());
        for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------"<<endl;
    system("pause");
    cout<<endl;
}

// for_each里没法放非静态成员函数作为回调函数，用不了的
//     //打印操作
// void SpeechManager::operator()(int val){
//     cout<<val<<" ";
// }

    //比赛
    /*这个就是第一层循环遍历人，然后打分，把平均分放到刚开始定义的map中，然后再弄个临时map放分数和编号，
    取前三名第一轮放到v2里面第二轮放到vectory里面，差不多就这个逻辑，几分钟就像明白了*/
void SpeechManager::speechContest(){
    cout<<"--------------第"<<this->m_Index<<"轮比赛正式开始-----------------"<<endl;
    //用临时map容器存放 对应编号的分数
    multimap<double, int, greater<double>>  groupScore; // 第一个参数 分数 ，第二个参数 选手编号， 第三个参数指定排序规则
    int num = 0; //用于统计人员个数， 6个人分为一组

    //再用一个临时容器来指代v1、v2，就可以将if-else判断缩短
    vector<int> v_Src;
    if(this->m_Index == 1){
        v_Src = v1;
    }else{
        v_Src = v2;  
    }

    for(vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++){
        num++;

        deque<double> d;
        //10个评委打分
        for(int i = 0; i < 10; i++){
            double score = (rand()/401 +600) / 10.f; //为了有随机小数 
            // cout<<score<<" ";
            d.push_back(score);
        }
        // cout<<endl;
        //排序
        sort(d.begin(), d.end(), greater<double>());
        //去掉最高最低分
        d.pop_front();
        d.pop_back();
        //计算平均分
        double sum = accumulate(d.begin(), d.end(), 0.0f); //总分
        double avg = sum / (double)d.size();   //将分母强转为double类型 ， 否则浮点除以整型还是整型
        //把平均分放入map容器中
        //map可以通过键索引到值
        //每个人平均分
        //cout << "编号： " << *it << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均
        // 分为： " << avg << endl; //打印分数

        this->m_Speaker[*it].m_Score[m_Index - 1] = avg;    

        //将打分数据放入到临时小组容器中，直到放到六个人为止
        groupScore.insert(make_pair(avg, *it));
        //临时容器中有6个人时， 去除前三名的成绩，然后将容器清空
        if(num % 6 == 0){
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++){
                cout<<"编号："<<(*it).second<<"姓名："<<this->m_Speaker[it->second].m_Name<<"成绩："<<
                this->m_Speaker[it->second].m_Score[this->m_Index - 1]<<endl;
            }
            //取前三名
            int count = 0;
            for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++){
                //第二轮又会重新比拼，顾只需要添加晋级选手编号即可
                if(this->m_Index == 1){
                    v2.push_back(it->second);
                }else{
                    vVictory.push_back(it->second);
                }
            }
            groupScore.clear(); //小组容器清空
            cout<<endl;
        }
    }
    cout << "------------- 第" << this->m_Index << "轮比赛完毕 ------------- " << endl;
    system("pause");

    //         //第一轮完毕后 轮数加1
    //         this->m_Index++;
    //     }
    //遍历vector容器给选手打分
    // if(this->m_Index == 1){
    //     //第一轮比赛
    //     for(vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++){
    //         num++;

    //         deque<double> d1;
    //         //10个评委打分
    //         for(int i = 0; i < 10; i++){
    //             double score = (rand()/401 +600) / 10.f; //为了有随机小数
    //             // cout<<score<<" ";
    //             d1.push_back(score);
    //         }
    //         // cout<<endl;
    //         //排序
    //         sort(d1.begin(), d1.end(), greater<double>());
    //         //去掉最高最低分
    //         d1.pop_front();
    //         d1.pop_back();
    //         //计算平均分
    //         int num = accumulate(d1.begin(), d1.end(), 0.0f); //总分
    //         int avg = num / (double)d1.size();   //将分母强转为double类型 ， 否则浮点除以整型还是整型
    //         //把平均分放入map容器中
    //         //map可以通过键索引到值
    //         //每个人平均分
    //         //cout << "编号： " << *it << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均
    //         // 分为： " << avg << endl; //打印分数

    //         this->m_Speaker[*it].m_Score[m_Index - 1] = avg;    

    //         //将打分数据放入到临时小组容器中，直到放到六个人为止
    //         groupScore.insert(make_pair(avg, *it));
    //         //临时容器中有6个人时， 去除前三名的成绩，然后将容器清空
    //         if(num % 6 ==0){
    //             cout << "第" << num / 6 << "小组比赛名次：" << endl;
    //             for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++){
    //                 cout<<"编号："<<(*it).second<<"姓名："<<this->m_Speaker[it->second].m_Name<<"成绩："<<
    //                 this->m_Speaker[it->second].m_Score<<endl;
    //             }
    //             //取前三名
    //             int count = 0;
    //             for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++){
    //                 //第二轮又会重新比拼，顾只需要添加晋级选手编号即可
    //                 v2.push_back(it->second);
    //             }
    //             groupScore.clear();
    //         }


    //         //第一轮完毕后 轮数加1
    //         this->m_Index++; //不用在这里++， 可以在开始比赛函数里 第一轮结束后 ++
    //     }
    // }else{
    //     //第二轮比赛
    //     for(vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++){
    //         deque<double> d2;
    //         //10个评委打分
    //         for(int i = 0; i < 10; i++){
    //             double score = (rand()/401 +600) / 10.f; //为了有随机小数
    //             d2.push_back(score);
    //         }
    //         //排序
    //         sort(d2.begin(), d2.end());
    //         //去掉最高最低分
    //         d2.pop_front();
    //         d2.pop_back();
    //         //计算平均分
    //         int num = accumulate(d2.begin(), d2.end(), 0.0f);
    //         int avg = num / (double)d2.size();
    //         //把分数放入选手的成员属性
    //         //map可以通过键索引到值
    //         this->m_Speaker[*it].m_Score[m_Index - 1] = avg;

    //         groupScore.insert(make_pair(avg, *it));
            
    //         if(num % 6 ==0){
    //             cout << "第" << num / 6 << "小组比赛名次：" << endl;
    //             for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++){
    //                 cout<<"编号："<<(*it).second<<"姓名："<<this->m_Speaker[it->second].m_Name<<"成绩："<<
    //                 this->m_Speaker[it->second].m_Score<<endl;
    //             }
    //             //取前三名
    //             int count = 0;
    //             for(multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++){
                    
    //                 vVictory.push_back(it->second);
    //             }
    //             groupScore.clear();
    //         }
    //     }
    // }
    
}

    //显示晋级人员比赛分数
void SpeechManager::showScore(){
    cout << "---------第" << this->m_Index << "轮晋级选手信息如下：-----------" << endl;
    //我写的是全体人员的信息
    // for(map<int, Speaker>::iterator it = m_Speaker.begin(); it != m_Speaker.end(); it++){
    //     // if(this->m_Index == 1){
    //     //     cout<<it->second.m_Score[this->m_Index - 1];
    //     // }else{
    //     //     cout<<it->second.m_Score[this->m_Index - 1];
    //     // } 好像不用判断
    //     cout<<"姓名："<<it->second.m_Name<<" 分数："<<it->second.m_Score[this->m_Index - 1];
    // }
    // cout<<endl;
    vector<int> v;
    if(this->m_Index == 1){
        v = v2;
    }else{
        v = vVictory;
    }

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << "选手编号：" << *it << " 姓名： " << this->m_Speaker[*it].m_Name << " 得分： " <<
        this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    system("pause");
    system("cls");
    this->show_Menu();
}

    //保存分数
void SpeechManager::saveRecord(){
    ofstream ofs;
    //csv格式的文件每个数据都是用逗号进行分割
    ofs.open("speech.csv", ios::out | ios::app);// 用输出的方式打开文件 -- 写文件

    for(vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++){
        ofs<<*it<<","<<this->m_Speaker[*it].m_Score[this->m_Index - 1]<<","; //其实这里保存获胜者的分数直接m_Score[1]也可
    }
    ofs<<endl;
    //关闭文件
    ofs.close();
    cout << "记录已经保存" << endl;

    //在运行时动态更改文件不为空的状态
    //其实也可也把loadRecord函数放在showRecord中，这样每次选择显示往届记录就会重新加载一次，每次都可以更新
    this->fileIsEmpty = false;
}

    //开始比赛   比赛整个流程控制函数   
void SpeechManager::startSpeech(){
    // string nameSeed = "ABCDEFGHJKLM";   //这一部分也封装成一个函数
    // for(int i = 0; i < 12; i++){
    //     Speaker s;
    //     s.m_Name = "选手";
    //     s.m_Name += nameSeed[i];
    //     s.m_Score[1] = 0;
    //     v1.push_back(s);
    // }

    //第一轮比赛
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示晋级结果
    this->showScore();

    //第一轮结束 标识轮数的参数加一
    this->m_Index++;

    //第二轮比赛
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示最终结果
    this->showScore();
    //4、保存分数到csv文件中
    this->saveRecord();

    //重置比赛
    //初始化属性
    this->initSpeech();
    //创建选手
    this->createSpeaker();  //在类对象构造的时候，这些东西就应该准备好，所以不在startSpeech函数里创建
    //在初始化时加载往届记录
    this->loadRecord();

    cout<<"本届比赛完毕!"<<endl;
    system("pause");
    system("cls");
}

    //读取记录
void SpeechManager::loadRecord(){
    ifstream ifs;
    ifs.open("speech.csv", ios::in);
    //判断文件是否为空
    if(!ifs.is_open()){
        this->fileIsEmpty = true;
        // cout<<"文件不存在！"<<endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch; //读入一个字符进行判断
    if(ifs.eof()){
        // cout<<"文件为空！"<<endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;          //return 表示结束当前函数，即使函数没有返回值
    }

    //文件不为空
    this->fileIsEmpty = false;

    //文件不为空就读取文件，显示结果
    ifs.putback(ch);    // 因为每读一个字符，就会向后移一个位置,所以要将读取的单个字符放回去

    int index = 0; //index要放在外面才能成功计数，不然每次循环会被重新定义
    string data; //存放读取的内容
    while (ifs >> data)
    {   
        // cout<<data<<endl;
        vector<string> v; //将分隔好的同一届的字符串放入的容器

        //需要两个标志位来截取字符串的部分内容，将逗号去掉
        int pos = -1;
        int start = 0;

        while (true)
        {
            pos = data.find(",", start);    //从0开始查找 ','
            if(pos == -1){
                //没找到
                break;
            }else{
                //找到了,进行分割 参数1 起始位置，参数2 截取长度
                string temp = data.substr(start, pos - start); //将截取出来的字符串临时保存起来
                
                v.push_back(temp);
                start = pos + 1; //将start位置更新
            }
        }
        //将临时容器中的数据放入m_Record
        m_Record.insert(make_pair(index, v));
        index++;
        // cout<<index;
        // ifs.close();  //只打印一届的bug在这里，在记录容器中添加一次后就将文件夹关闭了，怎么可能读取到后续的数据！
    }
    ifs.close();
}

    //显示记录
void SpeechManager::showRecord(){
    if(this->fileIsEmpty == true){
        cout<<"文件不存在或记录为空！"<<endl;
    }else{
        //1.用迭代器遍历
        for(map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++){
            cout<<"--------第"<<it->first + 1<<"届比赛-----------"<<endl;
            cout<<"冠军编号："<<it->second[0]<<" 得分："<<it->second[1]<<endl;
            cout<<"亚军编号："<<it->second[2]<<" 得分："<<it->second[3]<<endl;
            cout<<"季军编号："<<it->second[4]<<" 得分："<<it->second[5]<<endl;
        }

        //2.用[]方式遍历
        // for(int i = 0; i < m_Record.size(); i++){
        //     cout<<"--------第"<<i + 1<<"届比赛-----------"<<endl;
        //     cout<<"冠军编号："<<m_Record[i][0]<<" 得分："<<m_Record[i][1]<<endl;
        //     cout<<"亚军编号："<<m_Record[i][2]<<" 得分："<<m_Record[i][3]<<endl;
        //     cout<<"季军编号："<<m_Record[i][4]<<" 得分："<<m_Record[i][5]<<endl;
        // }
    }
    system("pause");
    system("cls");
}

//清空记录
void SpeechManager::clearRecord(){
    cout<<"请确认是否清空："<<endl;
    cout<<"1.确认清空"<<endl;
    cout<<"2.取消"<<endl;
    int choice = 0;
    cin>> choice;
    while (choice != 1 || choice != 2)
    {
        cout<<"请输入正确选项："<<endl;    
        cin>> choice;
    }
    
    if(choice == 1){
        return;
    }else{
        //打开模式 ios::trunc 如果存在删除文件并重新创建
        ofstream ofs("speech.csv", ios::trunc); //用有参构造的方式创建流对象
        ofs.close();

        //初始化属性
        this->initSpeech();   //如果不初始化 可能一些容器里面还保存着数据，会导致误读
        //创建选手
        this->createSpeaker();
        //获取往届记录
        this->loadRecord();

        cout << "清空成功！" << endl;
    }
    
    this->fileIsEmpty == true;
    system("pause");
    system("cls");
}

SpeechManager::~SpeechManager(){

}

