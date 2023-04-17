#include"manager.h"
#include<fstream>
#include"global.h"
#include<algorithm>

//默认构造
Manager::Manager(){

}

//有参构造
Manager::Manager(string name, string pwd){
    this->m_Name = name;
    this->m_Password = pwd;

    //初始化容器 获取到所有文件中学生和老师的信息
    this->initVector();

    //获取机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    computerRoom com;
    while (ifs>>com.m_id && ifs>>com.m_num)
    {
        vCom.push_back(com);
    }
    cout<<"当前机房的数量为："<<vCom.size();
    ifs.close();
}

//显示菜单
void Manager::operMenu(){
    cout << "欢迎管理员："<<this->m_Name << "登录！" << endl; 
    cout << "\t\t ------------------------------------\n"; 
    cout << "\t\t|                                    |\n"; 
    cout << "\t\t|              1.添加账号            |\n"; 
    cout << "\t\t|                                    |\n"; 
    cout << "\t\t|              2.查看账号            |\n"; 
    cout << "\t\t|                                    |\n"; 
    cout << "\t\t|              3.查看机房            |\n"; 
    cout << "\t\t|                                    |\n"; 
    cout << "\t\t|              4.清空预约            |\n"; 
    cout << "\t\t|                                    |\n"; 
    cout << "\t\t|              0.注销登录            |\n"; 
    cout << "\t\t|                                    |\n"; 
    cout << "\t\t ------------------------------------\n"; 
    cout << "请选择您的操作： " << endl;
}

//添加账号
void Manager::addPerson(){
    cout<<"请选择想要添加的账号类型："<<endl;
    cout<<"1.学生"<<endl;
    cout<<"2.教师"<<endl;

    //接收用户信息
    int id;
    string name;
    string pwd;

    ofstream ofs;
    //为减少重复操作申请的变量
    string fileName; //操作文件名
    string tip;     //提示id号
    string erroTip; //错误提示信息

    int select = 0;
    cin>>select; //接收用户选项
    if(select == 1){
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
        erroTip = "学号重复，请重新输入";
    }else if(select == 2){
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        erroTip = "职工编号重复，请重新输入";
    }
    //以下操作其实可以融合成一个，多申请几个变量来代替重复操作
    // if(select == 1){
    //     ofs.open(STUDENT_FILE, ios::app);
    //     cout<<"请输入要添加的学号："<<endl;
    //     cin>>id;
    //     cout<<"请输入要添加的姓名："<<endl;
    //     cin>>name;
    //     cout<<"请输入要添加的密码："<<endl;
    //     cin>>pwd;
    //     ofs<<id<<" "<<name<<" "<<pwd<<endl;
    // }else if(select == 2){
    //     ofs.open(TEACHER_FILE, ios::app);
    //     cout<<"请输入要添加的职工号："<<endl;
    //     cin>>id;
    //     cout<<"请输入要添加的姓名："<<endl;
    //     cin>>name;
    //     cout<<"请输入要添加的密码："<<endl;
    //     cin>>pwd;
    //     ofs<<id<<" "<<name<<" "<<pwd<<endl;
    // }

    //利用追加的方式 写文件
    ofs.open(fileName, ios::out | ios::app);

    cout<<tip<<endl;
    while (true)
    {
        cin>>id;
        bool ret = this->checkRepeat(id,select);
        if(ret){  //有重复
            cout<<erroTip<<endl;
        }else{
            break;
        }
    }

    cout<<"请输入姓名："<<endl;
    cin>>name;

    cout<<"请输入密码："<<endl;
    cin>>pwd;

    ofs<<id<<" "<<name<<" "<<pwd<<endl;
    cout<<"添加成功！"<<endl;

    system("pause");
    system("cls"); 
    
    ofs.close();

    //重新初始化一次容器，使得此次添加的信息更新在容器中
    this->initVector();
}

//没有加作用域 ，也没有再类内部声明，故不是成员函数
//打印学生信息
// void printStudent(Student & s){
//     cout<<"学号："<<s.m_Id<<"\t姓名："<<s.m_Name<<"\t密码："<<s.m_Password<<endl;
// }

// //打印教师信息
// void printTeacher(Teacher & t){
//     cout<<"职工编号："<<t.m_EmpId<<"\t姓名："<<t.m_Name<<"\t密码："<<t.m_Password<<endl;
// }

//查看账号  
void Manager::showPerson(){
    cout<<"请输入想要查看的账号类型："<<endl;
    cout<<"1.学生"<<endl;
    cout<<"2.教师"<<endl;

    //接收用户选择
    int choice = 0;
    cin>>choice;
    // while (choice != 1 || choice != 2)
    // {
    //     cout<<"选择有误，请重新输入："<<endl;
    //     cin>>choice;
    // }
    
    if(choice == 1){
        //查看学生信息
        cout<<"所有学生信息如下："<<endl;
        // for_each(vStu.begin(), vStu.end(), printStudent); //我使用这种方法会出错
        for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++){
            cout<<"学号："<<it->m_Id<<"\t姓名："<<it->m_Name<<"\t密码："<<it->m_Password<<endl;
        }
    }else if(choice == 2){
        //查看老师信息
        cout<<"所有教师信息如下："<<endl;
        // for_each(vTea.begin(), vTea.end(), printTeacher);
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            cout<<"学号："<<it->m_EmpId<<"\t姓名："<<it->m_Name<<"\t密码："<<it->m_Password<<endl;
        }
    }
    system("pause");
    system("cls");
}

//查看机房信息
void Manager::showComputer(){
    cout<<"机房信息如下："<<endl;
    for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
    {
        cout<<"机房编号："<<it->m_id<<"\t机房最大容量："<<it->m_num<<endl;
    }
    system("pause");
    system("cls");
}

//清空预约记录
void Manager::cleanFile(){
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();

    cout<<"清空成功！"<<endl;
    system("pause");
    system("cls");
}

//初始化容器
void Manager::initVector(){
    //容器清空
    vStu.clear();
    vTea.clear();

    //读取学生文件中的信息
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"文件读取失败！"<<endl;
        return;
    }

    //创建学生对象
    Student s;
    while (ifs>>s.m_Id && ifs>>s.m_Name && ifs>>s.m_Password)
    {
        //将读取到的对象放入学生信息容器中
        vStu.push_back(s);
    }

    cout<<"当前学生数量为："<<vStu.size()<<endl;
    ifs.close(); //学生信息初始化完毕

    //读取教师文件中的信息
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"文件读取失败！"<<endl;
        return;
    }

    //创建教师对象
    Teacher t;
    while (ifs>>t.m_EmpId && ifs>>t.m_Name && ifs>>t.m_Password)
    {
        //将读取到的对象放入学生信息容器中
        vTea.push_back(t);
    }

    cout<<"当前教师数量为："<<vTea.size()<<endl;
    ifs.close(); //教师信息初始化完毕
}

//检测重复   参数1 检测学号/教师号  参数2 检测类型
bool Manager::checkRepeat(int id, int type){
    //根据type确定检测对象为学生还是教师
    if(type == 1){
        //检测学生
        for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++){
            if(id == it->m_Id){
                return true;
            }
        }
    }else{
        //检测老师
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            if(id == it->m_EmpId){
                return true;
            }
        }
    }
    return false;
}

