#include"student.h"
#include"global.h"
#include<fstream>
#include"orderFile.h"
    //提供一个默认构造来方便显示菜单
    Student::Student(){

    }

    //有参构造函数
    Student::Student(string name, int id, string pwd){
        this->m_Name = name;
        this->m_Id = id;
        this->m_Password = pwd;

        //初始化机房信息
        ifstream ifs;
        ifs.open(COMPUTER_FILE, ios::in);
        computerRoom com; //临时的机房对象
        while(ifs>>com.m_id && ifs>>com.m_num){
            vCom.push_back(com);
        }
        ifs.close();
    }

    //菜单界面
    void Student::operMenu(){
        cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl; 
        cout << "\t\t --------------------------------------\n"; 
        cout << "\t\t|                                      |\n"; 
        cout << "\t\t|             1.申请预约               |\n"; 
        cout << "\t\t|                                      |\n"; 
        cout << "\t\t|             2.查看我的预约           |\n"; 
        cout << "\t\t|                                      |\n"; 
        cout << "\t\t|             3.查看所有预约           |\n"; 
        cout << "\t\t|                                      |\n"; 
        cout << "\t\t|             4.取消预约               |\n"; 
        cout << "\t\t|                                      |\n"; 
        cout << "\t\t|             0.注销登录               |\n"; 
        cout << "\t\t|                                      |\n"; 
        cout << "\t\t --------------------------------------\n"; 
        cout << "请选择您的操作： " << endl;
    }

    //申请预约
    void Student::applyOrder(){
        cout << "机房开放时间为周一至周五！" << endl; 
        cout << "请输入申请预约的时间：" << endl; 
        cout << "1、周一" << endl; 
        cout << "2、周二" << endl; 
        cout << "3、周三" << endl; 
        cout << "4、周四" << endl; 
        cout << "5、周五" << endl; 
        int date = 0; 
        int interval = 0;
        int room = 0;

        //判断输入是否合理
        while(true){
            cin>>date;

            if(date >= 1 && date <= 5){
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        cout << "请输入申请预约的时间段：" << endl;
        cout << "1、上午" << endl;
        cout << "2、下午" << endl;

        while(true){
            cin>>interval;

            if(interval >= 1 && interval <= 2){
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        cout << "请选择机房：" << endl;
        for(int i = 0; i < vCom.size(); i++){
            cout << vCom[i].m_id<<"号机房容量：" << vCom[i].m_num << endl;
        }
        // cout << "1号机房容量：" << vCom[0].m_num << endl;
        // cout << "2号机房容量：" << vCom[1].m_num << endl;
        // cout << "3号机房容量：" << vCom[2].m_num << endl;

        while(true){
            cin>>room;

            if(room >= 1 && room <= 3){
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        cout << "预约成功！审核中" << endl;

        //将预约信息保存到文件中
        ofstream ofs;
        ofs.open(ORDER_FILE, ios::out | ios::app);
        ofs << "date:" << date <<" ";
        ofs << "interval:" << interval << " ";
        ofs << "stuId:" << this->m_Id << " ";
        ofs << "stuName:" << this->m_Name << " ";
        ofs << "roomId:" << room << " ";
        ofs << "status:" << 1 << endl; //1 默认为审核中

        ofs.close();
        system("pause");
        system("cls");
    }

    //查看我的预约
    void Student::showMyOrder(){
        //为了查看预约需要建立一个order类
        orderFile of;
        if(of.m_Size == 0){
            cout<<"暂无预约！"<<endl;
            system("pause");
            system("cls");
            return;
        }

        //有预约，遍历预约信息，找到自己的预约信息
        for(int i = 0; i < of.m_Size; i++){
            // atoi (表示 ascii to integer)是把字符串转换成整型数的一个函数
            // atoi是const char*转int
            // 将string对象，转化为char*对象，而c_str()提供了这样一种方法，它返回const char*类型(可读不可改)的指向字符数组的指针。
            // string 转 int
            if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())){
                cout<<"预约日期：周"<<of.m_orderData[i]["date"];
                cout<<" 时间段："<<(of.m_orderData[i]["interval"] == "1" ? "上午": "下午");
                cout<<" 机房号："<<of.m_orderData[i]["roomId"];
                string status = " 状态：";  // 0 取消的预约 1 审核中 2 已预约 -1 预约失败
                if(of.m_orderData[i]["status"] == "1"){  //atoi((of.m_orderData[i]["status"].c_str())) == 1
                    status += "审核中";
                }else if(of.m_orderData[i]["status"] == "2"){
                    status += "预约成功";
                }else if(of.m_orderData[i]["status"] == "-1"){
                    status += "预约失败，审核未通过";
                }else{
                    status += "预约已取消";
                }
                cout<<status<<endl;
            }
        }
        system("pause");
        system("cls");
    }

    //查看所有预约
    void Student::showAllOrder(){
        orderFile of;
        if(of.m_Size ==0){
            cout<<"暂无预约！"<<endl;
            system("pause");
            system("cls");
            return;
        }

        for(int i = 0; i < of.m_Size; i++){
            cout<<i + 1<<"、";
            
            cout<<"预约日期：周"<<of.m_orderData[i]["date"];
            cout<<" 时间段："<<(of.m_orderData[i]["interval"] == "1" ? "上午": "下午");
            cout<<" 姓名："<<of.m_orderData[i]["stuName"];
            cout<<" 学号："<<of.m_orderData[i]["stuId"];
            cout<<" 机房号："<<of.m_orderData[i]["roomId"];
            string status = " 状态：";  // 0 取消的预约 1 审核中 2 已预约 -1 预约失败
            if(of.m_orderData[i]["status"] == "1"){  //atoi((of.m_orderData[i]["status"].c_str())) == 1
                status += "审核中";
            }else if(of.m_orderData[i]["status"] == "2"){
                status += "预约成功";
            }else if(of.m_orderData[i]["status"] == "-1"){
                status += "预约失败，审核未通过";
            }else{
                status += "预约已取消";
            }
            cout<<status<<endl;
        }
        system("pause");
        system("cls");
    }

    //取消预约
    void Student::cancelOrder(){
        orderFile of;
        if(of.m_Size == 0){
            cout<<"暂无预约！"<<endl;
            system("pause");
            system("cls");
            return;
        }

        //还是先进行查看自我预约的那一套，只是多了一个开头的选择序号
        int index = 1;
        //记录位置信息
        vector<int> v;
        for(int i = 0; i < of.m_Size; i++){
            //先判断自身记录
            if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())){
                //审核状态为 1审核中 以及 2已预约才可以取消
                if(of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2" ){
                    //将符合条件的信息记录下来
                    v.push_back(i);
                    cout<< index++ <<"、";
                    cout<<"预约日期：周"<<of.m_orderData[i]["date"];
                    cout<<" 时间段："<<(of.m_orderData[i]["interval"] == "1" ? "上午": "下午");
                    cout<<" 机房号："<<of.m_orderData[i]["roomId"];
                    string status = " 状态：";  // 0 取消的预约 1 审核中 2 已预约 -1 预约失败
                    if(of.m_orderData[i]["status"] == "1"){  //atoi((of.m_orderData[i]["status"].c_str())) == 1
                        status += "审核中";
                    }else if(of.m_orderData[i]["status"] == "2"){
                        status += "预约成功";
                    }
                    cout<<status<<endl;
                }              
            }
        }   

        /*进行删除操作，这个时候意识到一个问题，如何知道选择的select对应的预约记录在map容器中的位置呢？
          这个时候需要用数组来存储搜索到的自己的预约的位置信息，普通数组不行，需要动态数组，即vector容器
          而且需要在上面循环的时候就记录 */
        cout<<"请输入想要取消的预约，0表示返回："<<endl;
        int select = 0;

        while (true)
        {
            cin>>select;
            if(select >= 0 && select <= v.size()){
                if(select == 0 ){
                    break;
                }
                //更改预约状态为取消预约
                of.m_orderData[v[select - 1]]["status"] == "0";
                //更新文件
                of.updateOrder();
                cout<<"已取消预约"<<endl;
                break;
            }
            
            cout<<"输入错误，请重新输入："<<endl;
        }
        
        system("pause");
        system("cls");
    }
    

