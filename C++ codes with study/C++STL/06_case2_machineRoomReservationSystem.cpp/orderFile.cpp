#include"orderFile.h"


//构造函数
orderFile::orderFile(){
    //读文件
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);
    
    string date; //日期
    string interval; //时间段
    string stuId; //学号
    string stuName;  //姓名
    string roomId;  //机房号
    string status;  //预约状态

    this->m_Size = 0; //记录条数

    while(ifs>>date && ifs>>interval && ifs>>stuId && ifs>>stuName && ifs>>roomId && ifs>>status ){
        // cout<<date<<endl;
        // cout<<interval<<endl;
        // cout<<stuId<<endl;
        // cout<<stuName<<endl;
        // cout<<roomId<<endl;
        // cout<<status<<endl;
        // cout<<endl;

        //存放预约详细信息的容器
        map<string, string> m;
        string key;
        string value;
        //分割字符串的标识符
        int pos = 0;

        //分隔并插入 date
        pos = date.find(":");
        if(pos != -1){
            key = date.substr(0, pos);
            value = date.substr(pos+1, date.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //interval
        pos = interval.find(":");
        if(pos != -1){
            key = interval.substr(0, pos);
            value = interval.substr(pos+1, interval.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //stuId
        pos = stuId.find(":");
        if(pos != -1){
            key = stuId.substr(0, pos);
            value = stuId.substr(pos+1, stuId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //stuName
        pos = stuName.find(":");
        if(pos != -1){
            key = stuName.substr(0, pos);
            value = stuName.substr(pos+1, stuName.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        //roomId
        pos = roomId.find(":");
        if(pos != -1){
            key = roomId.substr(0, pos);
            value = roomId.substr(pos+1, roomId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        // status
        pos = status.find(":");
        if(pos != -1){
            key = status.substr(0, pos);
            value = status.substr(pos+1, status.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        
        //也可以封装成函数
        // void insertMap(string s){
        //     int pos = 0;
        //     string key;
        //     string value;
        //     pos = s.find(":");
        //     if(pos != -1){
        //         key = s.substr(0, pos);
        //         value = s.substr(pos+1, s.size() - pos - 1);
        //         m.insert(make_pair(key, value));
        //     }
        // }

        //全部插入完后，将小map容器插入大map容器中
        this->m_orderData.insert(make_pair(this->m_Size, m));
        this->m_Size++;
        // //清空小容器  循环体内部创建 不需要手动清空 ，如果在循环体内部创建则需要手动清空，否则会保留之前的数据
        // m.clear();
    }

    //测试代码
    // for(map<int, map<string, string>>::iterator it = this->m_orderData.begin(); it != this->m_orderData.end(); it++){
    //     cout<<"key = "<<it->first<<" value = "<<endl;
    //     for(map<string, string>::iterator mit = it->second.begin(); mit !=  it->second.end(); mit++){
    //         cout<<mit->first<<":"<<mit->second<<" ";
    //     }
    //     cout<<endl;
    // }

    ifs.close();
}

//更新订单信息
//并不是说在订单类里面会有新信息，而是创建好这个接口，在以后需要更新信息的时候，直接调用该接口即可
void orderFile::updateOrder(){
    if(this->m_Size == 0){
        return; //预约记录0条，直接return
    }

    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

    //这里的逻辑与学生类中的添加订单类似，我们也可以将学生类中的将预约信息保存到文件中这一功能集成到文件类中来
    for(int i = 0; i < this->m_Size; i++){
        // string date; //日期
        // string interval; //时间段
        // string stuId; //学号
        // string stuName;  //姓名
        // string roomId;  //机房号
        // string status;  //预约状态
        ofs<<"date:"<<this->m_orderData[i]["date"]<<" ";         //第一个[]是大map容器的键值用于索引到对应的小map容器
        ofs<<"interval:"<<this->m_orderData[i]["interval"]<<" ";  //第二个[]是指大map容器中小map容器的键值
        ofs<<"stuId:"<<this->m_orderData[i]["stuId"]<<" ";
        ofs<<"stuName:"<<this->m_orderData[i]["stuName"]<<" ";
        ofs<<"roomId:"<<this->m_orderData[i]["roomId"]<<" ";
        ofs<<"status:"<<this->m_orderData[i]["status"]<<endl;
    }

    ofs.close();
}

