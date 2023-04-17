// 1.5 系统具体需求
// 首先进入登录界面，可选登录身份有：
// 学生代表
// 老师
// 管理员
// 退出
// 每个身份都需要进行验证后，进入子菜单
// 学生需要输入 ：学号、姓名、登录密码
// 老师需要输入：职工号、姓名、登录密码
// 管理员需要输入：管理员姓名、登录密码
// 学生具体功能
// 申请预约 --- 预约机房
// 查看自身的预约 --- 查看自己的预约状态
// 查看所有预约 --- 查看全部预约信息以及预约状态
// 取消预约 --- 取消自身的预约，预约成功或审核中的预约均可取消
// 注销登录 --- 退出登录
// 教师具体功能
// 查看所有预约 --- 查看全部预约信息以及预约状态
// 审核预约 --- 对学生的预约进行审核
// 注销登录 --- 退出登录
// 管理员具体功能
// 添加账号 --- 添加学生或教师的账号，需要检测学生编号或教师职工号是否重复
// 查看账号 --- 可以选择查看学生或教师的全部信息
// 查看机房 --- 查看所有机房的信息
// 清空预约 --- 清空所有预约记录
// 注销登录 --- 退出登录

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include"student.cpp" // #include"student.h" 每次都不行，必须要包含.cpp才行 ， 这是vsCode的bug么？
#include"teacher.cpp"
#include"manager.cpp"
#include<fstream>
#include"global.h"
#include"orderFile.cpp"

//进入管理员子菜单界面
//将管理员菜单中后续的一系列操作封装在这个函数中了
// C++Primer第五版52页上面写着引用本身不是一个对象，因此不能定义指向引用的指针。但指针是对象，所以存在对指针的引用
void managerMenu(Identity * & manager){
    while(true){
        //通过父类指针调用公共接口,显示菜单
        manager->operMenu();
        //父类指针指向子类对象，此时父类指针只能调用公共接口，强制类型转换成子类指针，才能调用子类特有的接口
        Manager* man = (Manager*)manager;

        int select = 0;
        cin >> select;

        if(select == 1){ //添加账号
            //cout << "添加账号" << endl;
            man->addPerson();
        }else if(select == 2){ //查看账号
            //cout << "查看账号" << endl;
            man->showPerson();
        }else if(select == 3){ //查看机房
            //cout << "查看机房" << endl;
            man->showComputer();
        }else if(select == 4){ //清空预约
            //cout << "清空预约" << endl;
            man->cleanFile();
        }else if(select == 0){  //注销账号
            delete manager;  //销毁掉堆区对象  man和manager都指向一个对象，delete谁都一样
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
    
}

//进入学生子菜单主界面
void studentMenu(Identity* & student){
    while(true){
        student->operMenu();

        Student * stu = (Student*)student;
        int select = 0;
        cin>>select;

        if(select == 1){ //申请预约
            stu->applyOrder();
        }else if(select == 2){//查看我的预约
            stu->showMyOrder();
        }else if(select == 3){//查看所有预约
            stu->showAllOrder();
        }else if(select == 4){//取消预约
            stu->cancelOrder();
        }else{ //注销登录
            delete student;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }

    }
}

//进入教师子菜单主界面
void teacherMenu(Identity* & teacher){
    while(true){
        //教师菜单
        teacher->operMenu();

        Teacher * tea = (Teacher*)teacher;
        int select = 0;
        cin>>select;

        if(select == 1){ //查看所有预约
            tea->showAllOrder();
        }else if(select == 2){//审核预约
            tea->validOrder();
        }else{ //注销登录
            delete teacher;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }

    }
}

//登录功能   参数1 要操作的文件名， 参数2 登录的身份
void LoginIn(string fileName, int type){
    // ifstream ifs("学生用户.txt", ios::in);
    // if(!ifs.is_open()){
    //     cout<<"现在没有学生用户！"<<endl;
    //     return;
    // }

    //先创建一个父类指针，不清楚到底会创建哪一个具体的子类对象
    Identity * person = NULL;

    ifstream ifs;
    ifs.open(fileName, ios::in);
    if(!ifs.is_open()){
        cout<<"文件不存在！"<<endl;
        ifs.close();
        return;
    }

    //准备接收用户的信息
    int id = 0;
    string pwd;
    string name;

    //判断身份
    if(type == 1){ //学生登录
        cout<<"请输入你的学号："<<endl;
        cin>>id;
    }else if(type == 2){  //教师登录
        cout<<"请输入你的职工号："<<endl;
        cin>>id;
    }

    // cout<<"请输入学号："<<endl;
    // cin>>id;
    cout<<"请输入用户名："<<endl;
    cin>>name;

    cout<<"请输入密码："<<endl;
    cin>>pwd;
    //读取文件中的信息，进行比对

    if(type == 1){
        //学生登录验证
        //获取文件中的信息
        int fid; //从文件中读取的id号
        string fname;
        string fpwd;

        while(ifs>>fid && ifs>>fname && ifs>>fpwd){ //一行一行的读，读到空格以为换行所以可以将一行中的所有信息分别读出来
            //测试
            // cout<<fid<<endl;
            // cout<<fname<<endl;
            // cout<<fpwd<<endl;
            // cout<<endl;
            //将用户输入的信息与文件中的信息相比较
            if (id == fid && name == fname && pwd == fpwd)
            {
                // 如果中文验证不成功：记事本->文件->另存为->下方编码格式->ascl
                cout<<"学生验证登录成功！"<<endl;
                system("pause");
                system("cls");
                //将数据保存起来就行，不需要将对象保存起来，在每次登录时，将数据提取出来然后创建新的对象，再将数据注入就是特定的对象
                person = new Student(name, id, pwd); //父类指针指向子类对象
                //进入学生身份的子菜单
                studentMenu(person);
                
                return;
            }
            
        }
    }else if(type == 2){
        //教师登录验证
        //获取文件中的信息
        int fid; //从文件中读取的id号
        string fname;
        string fpwd;

        while(ifs>>fid && ifs>>fname && ifs>>fpwd){ 
            //测试
            // cout<<fid<<endl;
            // cout<<fname<<endl;
            // cout<<fpwd<<endl;
            // cout<<endl;
            //将用户输入的信息与文件中的信息相比较
            if (id == fid && name == fname && pwd == fpwd){
                cout<<"教师验证登录成功！"<<endl;
                system("pause");
                system("cls");
                
                person = new Teacher(name, id, pwd); //父类指针指向子类对象
                //进入教师身份的子菜单
                teacherMenu(person);

                return;
            }
        }
    }else if(type == 3){
        //管理员登录验证
        string fname;
        string fpwd;

        while(ifs>>fname && ifs>>fpwd){ 
            //测试
            // cout<<fid<<endl;
            // cout<<fname<<endl;
            // cout<<fpwd<<endl;
            // cout<<endl;
            //将用户输入的信息与文件中的信息相比较
            if (name == fname && pwd == fpwd){
                cout<<"管理员验证登录成功！"<<endl;
                system("pause");
                system("cls");
                
                person = new Manager(name, pwd); //父类指针指向子类对象
                //进入管理员身份的子菜单
                // person->operMenu();
                managerMenu(person);
                
                return;
            }
        }
    }   

    // string buf;    
    // int pos = -1;
    // int start = 0;
    // while (true)
    // {
    //     while (getline(ifs, buf))
    //     {
    //         pos = buf.find(" ", start);
    //         string tempid = buf.substr(start, pos-start);
    //         start = pos + 1;
    //         string temppwd = buf.substr(start, buf.size()-start);
    //         int count = 0; //登陆计数器

    //         if(id == tempid){  
    //             // if(pwd == temppwd){
    //             //     cout<<"登陆成功！"<<endl;
    //             // }else{
    //             //     cout<<"密码错误请重新输入："<<endl;
    //             //     cin>>pwd;
    //             while (pwd != temppwd)
    //             {
    //                 if(count == 3){
    //                     cout<<"已超过输入次数限制！"<<endl;
    //                     return;
    //                 }
    //                 cout<<"密码错误请重新输入："<<endl;
    //                 cin>>pwd;
    //                 count++;
    //             }
    //             cout<<"登陆成功！"<<endl;
    //             //登陆成功后，根据选择的身份进入不同的菜单界面
    //             count = 0;
    //         }
    //     }
    //     cout<<"没有该账号，请重新输入："<<endl;
    //     cin>>id;
    // }

    cout<<"登录验证失败！"<<endl;
    system("pause");
    system("cls");
}

int main(){

    while (true)
    {
        cout << "====================== 欢迎来到机房预约系统 ====================="
        << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|            1.学生代表         |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|            2.老 师            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|            3.管 理 员         |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|            0.退 出            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        int select = -1;
        cin>>select;

        // //判断是否输入正确
        // while(select != 1 || select != 2 || select != 3 || select != 0){
        //     cout<<"输入错误，请输入正确的选项："<<endl;
        //     cin>>select;
        // }

        switch (select)
        {
        case 1:
        {
            //先登陆，在实现后续功能
            LoginIn(STUDENT_FILE, 1);
            // Student stu;     //学生身份
            // stu.operMenu();
            break;
        }
        case 2:
            LoginIn(TEACHER_FILE, 2);
                //老师身份
            break;
        case 3:
            LoginIn(ADMIN_FILE, 3);
                //管理员身份
            break;
        case 0:
            //退出系统
            cout<<"欢迎下次使用！"<<endl;
            // exit(0);  //这段代码也可以正常运行
            return 0; //个人理解： exit(0)多用于类或者函数中， 在main函数中，return 0 相当于退出整个系统
            break;
        default:
            //也可以在此处实现判断输入是否有误的功能
            cout<<"输入有误，请重新选择！"<<endl;
            break;
        }

    }
       
    system("pause");
    return 0;
}

