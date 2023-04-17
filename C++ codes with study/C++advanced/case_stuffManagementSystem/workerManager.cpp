#include "wokerManager.h"
#include"employee.h"
#include "manager.h"
#include"boss.h"  //用到了就需要包含这些头文件
#include<fstream>

WorkerManager::WorkerManager(){

    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    //判断文件是否打开成功
    if(ifs.is_open() == false){
        // cout<<"文件不存在！"<<endl; //测试输出
        //如果文件不存在，那么需要对文件进行初始化操作
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_EmpArray = NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty = true;
        //关闭文件
        ifs.close();

        return;
    }

    //2.文件存在，但是没有记录的情况
    //文件为空时会有一个字符，需要读出再判断,读出一个字符后，文件就真的为空了，此时调用eof()函数就会返回true
    /*原理：刚打开文件时，文件状态标识都是初始化态，eof()函数是根据文件状态标识来判断是否读到文件尾，而不是用来
    判断文件是否为空。所以当读文件数据时，遇到文件尾系统会更改文件状态标识为文件尾，且返回EOF*/
    //建立一个字符变量，将文件的第一个字符读进去
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        // cout<<"文件为空！"<<endl; //测试输出
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_EmpArray = NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty = true;
        //关闭文件
        ifs.close();

        return;
    }

    //3.文件存在，并且有记录
    int num = this->get_EmpNum();//从文件中获取人数
    // cout<<"职工人数为："<<num<<endl;
    this->m_EmpNum = num; //获取当前记录的人数
    //根据人数来创建数组的大小——开辟空间 
    this->m_EmpArray = new Worker* [this->m_EmpNum];
    //进行初始化， 将文件中的数据存入数组中
    this->init_Emp(); //最开始我直接写的init_Emp(); 没有注意到指向问题，加上this->更加保险
    this->m_FileIsEmpty = false; //文件存在，就将这个文件状态标识设置为false
    //测试代码
    // for(int i = 0; i < this->m_EmpNum; i++ ){
    //     cout<<"员工编号："<<this->m_EmpArray[i]->m_Id  //一开始我在想为啥数组带有成员属性了，是因为在创建时new Worker 里面就有
    //         <<"\t姓名："<<this->m_EmpArray[i]->m_Name
    //         <<"\t部门编号："<<this->m_EmpArray[i]->m_DeptId<<endl;
    // }

}

void WorkerManager::Show_Menu(){
    cout << "********************************************" << endl; 
    cout << "********* 欢迎使用职工管理系统！ **********" << endl; 
    cout << "************* 0.退出管理程序 *************" << endl; 
    cout << "************* 1.增加职工信息 *************" << endl; 
    cout << "************* 2.显示职工信息 *************" << endl; 
    cout << "************* 3.删除离职职工 *************" << endl; 
    cout << "************* 4.修改职工信息 *************" << endl; 
    cout << "************* 5.查找职工信息 *************" << endl; 
    cout << "************* 6.按照编号排序 *************" << endl; 
    cout << "************* 7.清空所有文档 *************" << endl; 
    cout << "********************************************" << endl; 
    cout << endl;
}

//退出系统
void WorkerManager::exitSystem(){
    cout<<"欢迎下次使用"<<endl;
    // return ;
    system("pause");
    exit(0);
}

//保存文件
void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out ); //ios::app从尾部写入 ，防止被覆盖，但是有个问题，那就是每次都会把之前的重复写进去，后面实现了每次打开文件就显示的功能后，就不需要app在尾部添加的功能了

    //写入文件
    for(int i = 0; i < this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_Id<<"  "
            << this->m_EmpArray[i]->m_Name<<"  "
            << this->m_EmpArray[i]->m_DeptId<<endl;
    }
    //关闭文件
    ofs.close();
}

//增加职工
void WorkerManager::addWorker(){
    int addNum = 0;
    cout<<"请输入添加员工数量："<<endl;
    cin>>addNum;
    if(addNum > 0){
        //计算新空间大小
        int newSize = this->m_EmpNum + addNum;
        // 将原来空间迁移到新空间,像两数交换一样，用一个临时指针来存储
        Worker ** newSpace = new Worker* [newSize];  //可以想象成还是创建了一个数组，数组里面还是存放指针
        //把已经有的放入临时指针
        // newSpace = this->woker; 不是这样放置
        //开始迁移
        if(this->m_EmpArray != NULL){
            for(int i = 0; i < this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray [i];
            }
        }

        //输入新数据
        for(int i = 0; i < addNum; i++){
            int id;
            string name;
            int dSelect;
            //查看员工编号是否重复
            bool ret = true;

            cout<<"正在添加第"<<1+i<<"位员工..."<<endl;
            cout<<"请输入员工编号："<<endl;

            while(ret = true){
                cin>>id;
                ret = this->IsRepeat(id);
                if(ret = true){
                    cout<<"员工编号重复，请重新输入："<<endl;
                }
            }
            

            cout<<"请输入姓名："<<endl;
            cin>>name;
            cout<<"请输入岗位："<<endl;
            cout<<"1、普通职工" <<endl;
            cout<<"2、经理" <<endl;
            cout<<"3、老板" <<endl;
            cin>>dSelect;

            //通过员工岗位编号进行对应员工类的新建
            //利用指针临时存储
            Worker * worker = NULL; 
            switch (dSelect)
            {
            //普通员工
            case 1:
                worker= new Employee(id,name,1);
                break;
            case 2:
                worker= new Manager(id,name,2);
                break;
            case 3:
                worker= new Boss(id,name,3);
                break;
            default:
                break;
            }
            //把临时指针存入新建立的指针数组里
            newSpace[this->m_EmpNum + i] = worker;
        }
        //释放原有空间
        delete [] this->m_EmpArray;
        //更新新空间的指向
        this->m_EmpArray = newSpace;
        //更新员工人数
        this->m_EmpNum = newSize;
        //提示信息
        cout<<"添加成功"<<addNum<<"名新员工！"<<endl;

        //保存文件不为空的状态
        this->m_FileIsEmpty = false;
        //添加完毕之后，进行保存
        this->save();

        }else{
        cout<<"输入有误！"<<endl;
        }

    system("pause");
    system("cls");
}

//查看是否已有相同的员工编号
bool WorkerManager::IsRepeat(int id){
    int ret = false;
    for(int i =0; i < this->m_EmpNum; i++){
        if(id == this->m_EmpArray[i]->m_Id){
            ret = true;
            break;
        }
    }
    return ret;
}


//统计文件中人数
int WorkerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //打开文件，读文件，本质上就是通过读文件有多少行记录来确定人数
    //要读取的数据
    int id;
    string name;
    int dId;
    //用于记录人数
    int num = 0;

    //还能读取，就说明文件还有内容
    while(ifs>>id && ifs>>name && ifs>>dId){ //cin>>  其实有一个隐含条件，就是读到空格时会自动结束，所以可以忽略空格读完一行
        num++;
    }
    return num;
}

    //初始化员工
void WorkerManager::init_Emp(){
    //还是得从文件获取员工数据
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //要读取出来的数据需要临时存放 
    int id;
    string name;
    int dId;
    //记录读取的数量
    int index = 0;
    //临时存放创建的员工指针
    Worker * worker = NULL;

    while (ifs>>id && ifs>>name && ifs>>dId)
    {
        if(dId == 1){
            worker = new Employee(id, name, dId);
        }else if (dId == 2)
        {
            worker =  new Manager(id, name, dId);
        }else if (dId == 3)
        {
            worker = new Boss(id, name, dId);
        }
        //将创建的指针放入数组中
        this->m_EmpArray[index] = worker;
        //记录的数量加一
        index++; 
    }
    
    //关闭文件
    ifs.close();
}

    //显示职工
void WorkerManager::show_Emp(){ 
    //先判断文件是否为空
    if(this->m_FileIsEmpty == true){
        cout<<"文件不存在或者为空！"<<endl;
    }else{
        for(int i =0; i < this->m_EmpNum; i++){
            //利用多态调用程序接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

//删除职工
void WorkerManager::del_Emp(){
    if(this->m_FileIsEmpty == true){
        cout<<"文件为空或不存在！"<<endl;
    }else{
        int id = 0 ;
        cout<<"请输入想要删除的职工编号："<<endl;
        cin>> id;
        int index = this->ISEXist(id);
        if(index != -1){
            //首先删除这个位置的堆区内存，否则数组元素指向的空间不会被释放，导致内存泄漏
            //不再会被使用的对象的内存不能被回收,就是内存泄露
            delete this->m_EmpArray[index];
            //index不等于-1说明职工存在
            //如果该员工存在，就将其删除，方法是将该索引号后面的所有数据往前移动一个位置
            //数组中的删除，本质就是前移
            for(int i = index; i < this->m_EmpNum - 1; i++){
            this->m_EmpArray[i] = this->m_EmpArray[i+1];
            //并将最后一位指针指向空
            this->m_EmpArray[i+1] = NULL;
            }
            //更新人数
            this->m_EmpNum--;
            //如果人数为0，需要将文件是否为空置为true
            if(this->m_EmpNum == 0){
                this->m_FileIsEmpty = true;
            }
            //删除完毕之后对文件进行更新保存
            this->save();

            cout<<"删除成功!"<<endl;
        }else{
            cout<<"删除失败，为找到该员工！"<<endl;
        }

    }
    system("pause");
    system("cls");
}

//判断职工是否存在,根据传入的id员工编号来判断
int WorkerManager::ISEXist(int id){
    int index = -1;
    //通过指针来对比有无相同的id，找到了就返回对应的数组中的位置
    for(int i =0; i < this->m_EmpNum; i++){
        if(id == this->m_EmpArray[i]->m_Id){
            index = i;
            break;
        }
    }
    //循环完都没有匹配的就返回-1
    return index;
}

//修改员工信息
void WorkerManager::Mod_Emp(){
    //首先查看文件是否为空
    if(this->m_FileIsEmpty == true){
        cout<<"文件不存在或为空！"<<endl;
    }else
    {
        int id = 0;
        //其次查找该员工是否存在
        cout<<"请输入要修改的员工的id："<<endl;
        cin>>id;
        //进行判断
        int index = this->ISEXist(id); 
        if(index != -1){
            //找到了先将这一块儿内存释放 全部更新
            //切勿直接修改，如果进行直接修改的话，那么只是属性对应的值变了，但是普通职工的对象还是普通职工，并不能变成经理对象或者老板对象
            //如果新new一个对象进行覆盖，确实可以实现需求，但是会出现内存泄漏问题，因为以前的那块内存并没有被释放掉！
            delete this->m_EmpArray[index];

            //输入要修改的所有信息
            int newId;
            string newName;
            int newDid;
            cout<<"查找到编号为"<<id<<"的职工，请输入新的员工编号："<<endl;
            cin>>newId;
            cout<<"请输入新的员工姓名："<<endl;
            cin>>newName;
            cout<<"请输入新的员工岗位号："<<endl;
            cout<<"1、普通职工" <<endl;
            cout<<"2、经理" <<endl;
            cout<<"3、老板" <<endl;
            cin>>newDid;

            Worker * worker = NULL;
            switch (newDid)
            {
            case 1:
                worker= new Employee(newId,newName,1);
                break;
            case 2:
                worker= new Manager(newId,newName,2);
                break;
            case 3:
                worker= new Boss(newId,newName,3);
                break;
            default:
                break;
            }

            //更新数据到数组中
            this->m_EmpArray[index] = worker;
            
            cout<<"员工信息修改成功！"<<endl;
            //文件保存更新
            this->save();

        }else{
            cout<<"修改失败，该员工不存在！"<<endl;
        }

        system("pause");
        system("cls");

    }

}

//查找职工
void WorkerManager::Find_Emp(){
    if(this->m_FileIsEmpty == true){
        cout<<"文件为空或不存在！"<<endl;
    }else
    {
        //给用户两种查找方式
        int select = 0;

        cout<<"请输入查找方式："<<endl;
        cout<<"1.按照员工编号进行查找"<<endl;
        cout<<"2.按照员工姓名进行查找"<<endl;
        while(select != 1 || select != 2){
            cin>>select;
            if(select != 1 || select != 2){
                cout<<"输入有误，请重新输入！"<<endl;
            }
        }

        //根据所选择的方式进行查找
        if(select == 1){
            //1.按照编号查找
            int id = 0;
            cout<<"请输入想要查找的员工编号："<<endl;
            cin>>id;
            int index = this->ISEXist(id);
            if(index != -1){
                cout<<"已为您查找到该用户，信息如下："<<endl;
                //调用显示信息的接口
                this->m_EmpArray[index]->showInfo();
            }else{
                cout<<"抱歉，查无此人！"<<endl;
            }
        }else if (select == 2){
            //2.按照姓名查找
            string name;
            //设置一个查找到的标识
            bool flag =false;
            cout<<"请输入想要查找的员工姓名："<<endl;
            cin>>name;
            //遍历数组指针，查找该姓名，有信息即可输出
            for(int i = 0; i < this->m_EmpNum; i++){
                if(name == this->m_EmpArray[i]->m_Name){
                    cout<<"已为您查找到该用户，信息如下："<<endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
                // else  //不能这样输出查无此人，因为循环每一轮都会进行，没有查到那一轮的人名就会输出一次，有问题
                // {        //需要在循环外进行输出！
                //     cout<<"抱歉，查无此人！"<<endl;
                // }
            }
            if(flag == false){
                cout<<"抱歉，查无此人！"<<endl;
            }

        }
    }
    
    
    system("pause");
    system("cls");
}

//按照职工编号排序
void WorkerManager::Sort_Emp(){
    if(this->m_FileIsEmpty == true){
        cout<<"文件为空或不存在！"<<endl;
    }else{
        //根据用户选择进行升序或者降序操作
        int select = 0;
        cout<<"请选择排序方式："<<endl;
        cout<<"1.按照升序排序"<<endl;
        cout<<"2.按照降序排序"<<endl;

        while(select != 1 || select != 2){
            cin>>select;
            if(select != 1 || select != 2){
                cout<<"输入有误，请重新输入！"<<endl;
            }
        }

        /*此处利用选择排序，首先指定一个最小值或最大值，根据后续循环的对比，每循环一轮就可以确定一个最大或最小值，然后将
          确定的数交换到数组头部，这样进行第二次循环的时候就可以将下一个数定义为最小或最大的数了*/
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            //定义最小或最大的数下标
            int minormax = i;
            //要将定义的最大或最小值不停与后面的数进行对比，所以需要双循环，而不是一个循环出去就完了
            for(int j = i+1; j < this->m_EmpNum; j++){
                if(select == 1){
                    //升序,需要将最小值放在前面
                    if(this->m_EmpArray[minormax]->m_Id > this->m_EmpArray[j]->m_Id ){
                        //出现了更小的值，将minormax更新为小的那一个值
                        minormax = j;
                    }
                }else {    //if(select == 2) 前面做了处理了，此处不需要再判断 ，会降低时间
                    //降序，需要将最大值放在前面
                    if(this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id ){
                        //出现了更大的值，将minormax更新为大的那一个值
                        minormax = j;
                    }
                }

            }
            //如果最大值或最小值做过更改，不是一开始认定的下标，那么需要将最新的最小或最大值放在数组前面
            if(minormax != i){
                Worker * temp = this->m_EmpArray[i]; //这里只是一个指针临时存储另一个指针，不涉及用数组来存储指针，所以只需要Worker*即可，不需要**
                this->m_EmpArray[i] = this->m_EmpArray[minormax];
                this->m_EmpArray[minormax] = temp;
            }


        }

        cout << "排序成功,排序后结果为：" << endl;
        this->save();  // 排序后的结果保存到文件中，这一行根据实际业务需求来看要不要加
        this->show_Emp();
    }

    // system("pause");          在 this->show_Emp(); 中已经有了按任意键继续和清屏操作了 不需要再用此操作
    // system("cls");
}

//清空文件实现
void WorkerManager::Clean_File(){
    if(this->m_FileIsEmpty == true){
        cout<<"文件已经为空，不需要清空！"<<endl;
    }else{
        //告知用户是否确定
        int select = 0;

        cout<<"是否确定进行删除操作？"<<endl;
        cout<<"1.确定"<<endl;
        cout<<"2.放弃"<<endl;

        while(select != 1 || select != 2){
            cin>>select;
            if(select != 1 || select != 2){
                cout<<"输入有误，请重新输入！"<<endl;
            }
        }

        if(select == 1){
            //先将文件清空
            ofstream ofs;
            //打开模式：ios::trunc 为如果文件存在删除文件并重新创建 
            ofs.open(FILENAME, ios::trunc);
            ofs.close();

            //这里就是真实的清空操作！清空内存！
            //再将所有指针所指的对象清空
            //如果不这样，那么只是将堆区的数组指针释放了，并没有实现将用户创建的每一个堆区数据释放干净
            //数组是new出来的，数组里面的元素也是new出来的！
            if(this->m_EmpArray != NULL){
                //删除堆区的每个职工对象
                for (int i = 0; i < this->m_EmpNum; i++)
                {
                    if(this->m_EmpArray[i] != NULL){  //先判断的话可以防止非法操作
                        //删除后记得将指针置空！
                        delete this->m_EmpArray[i];
                        this->m_EmpArray[i] = NULL;
                    }
                }
                /*如果只delete[]的话，只是释放了数组指针，但数组中存放的指针指向的对象还没有释放（此处是数组里面存放的指针，并不是具体的对象 ），
                因为开辟的数组放在堆区，而数组里面存放的指针所指向的对象也都开辟在堆区*/
                delete [] this->m_EmpArray; 
                this->m_EmpArray = NULL;
                //将成员数量置零
                this->m_EmpNum = 0;
                this->m_FileIsEmpty = true;

            }
        }
        cout<<"清空成功！"<<endl;
        system("pause");
        system("cls");
    }

}

WorkerManager::~WorkerManager(){
    if(this->m_EmpArray != NULL){
        for(int i = 0; i < this->m_EmpNum; i++){
            if(this->m_EmpArray[i] != NULL){
                delete this->m_EmpArray[i];
            }
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray =NULL;
    }
}