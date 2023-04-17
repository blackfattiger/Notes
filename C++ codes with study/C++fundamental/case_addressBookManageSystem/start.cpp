// 通讯录是一个可以记录亲人、好友信息的工具。
// 本教程主要利用C++来实现一个通讯录管理系统
// 系统中需要实现的功能如下：
// 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
// 显示联系人：显示通讯录中所有联系人信息
// 删除联系人：按照姓名进行删除指定联系人
// 查找联系人：按照姓名查看指定联系人信息
// 修改联系人：按照姓名重新修改指定联系人
// 清空联系人：清空通讯录中所有信息
// 退出通讯录：退出当前使用的通讯录
#include <iostream>
#define Max 1000 //定义通讯录能存储的人数
using namespace std;


// 封装函数显示该界面 如 void showMenu()
// 在main函数中调用封装好的函数
void showMenu(){
    cout << "***************************" << endl; 
    cout << "*****  1、添加联系人  *****" << endl; 
    cout << "*****  2、显示联系人  *****" << endl; 
    cout << "*****  3、删除联系人  *****" << endl; 
    cout << "*****  4、查找联系人  *****" << endl; 
    cout << "*****  5、修改联系人  *****" << endl; 
    cout << "*****  6、清空联系人  *****" << endl; 
    cout << "*****  0、退出通讯录  *****" <<endl; 
    cout << "***************************" << endl;
}

//定义联系人结构体
struct Person{
string m_Name;
int m_Sex;  //1.男  2.女 string sex;
int m_Age;
string m_Phone; //int pnum;
string m_Addr;
};

//定义通讯录结构体
struct Addressbooks{
    struct Person person[Max];
    int m_Size; //通讯录中的成员个数
};

//1.封装添加联系人的函数
void addPerson(struct Addressbooks* abs){
    // if(len > 1000)
    //盘
    if(abs->m_Size == Max){
        cout<<"通讯录已存满，无法继续添加！"<<endl;
        return;
    }
    // string name;
    // string sex;
    // int age;
    // int pnum;
    // string address;
    //姓名、性别、年龄、联系电话、家庭住址
    cout<<"请输入联系人姓名："<<endl;
    cin>>abs->person[abs->m_Size].m_Name;
    int sex = 0;
    cout<<"请输入联系人性别：1.男，2.女"<<endl;
    while(true){
        cin>>sex;
        if(sex == 1 || sex == 2){
            abs->person[abs->m_Size].m_Sex = sex;
            break;
        }
        cout<<"输入有误，请重新输入："<<endl;
    }
        
    cout<<"请输入联系人年龄："<<endl;
    cin>>abs->person[abs->m_Size].m_Age;
    cout<<"请输入联系人的电话号码："<<endl;
    cin>>abs->person[abs->m_Size].m_Phone;
    cout<<"请输入联系人的家庭住址："<<endl;
    cin>>abs->person[abs->m_Size].m_Addr;
    abs->m_Size++;
    // cin>>contacts[].name<<endl;
    cout<<"添加成功！"<<endl;
    system("pause");//按任意键继续
    system("cls");//清空屏幕
}

//2.显示联系人
void showPerson(struct Addressbooks * abs){
    if(abs->m_Size == 0){
        cout<<"记录为空！"<<endl;
        return;
    }
    // 姓名、性别、年龄、联系电话、家庭住址
    for(int i = 0; i < abs->m_Size; i++ ){
        cout<<"姓名："<<abs->person[i].m_Name<<"\t";
        cout<<"性别："<<(abs->person[i].m_Sex == 1 ? "男" : "女" )<<"\t";
        cout<<"年龄："<<abs->person[i].m_Age<<"\t";
        cout<<"电话号码："<<abs->person[i].m_Phone<<"\t";
        cout<<"家庭住址："<<abs->person[i].m_Addr<<endl;
    }
    system("pause");
    system("cls");
}

//检测联系人是否存在，如果存在，返回联系人在数组中的具体位置,不存在返回-1
// 参数1  通讯录  参数2  对比姓名
int isExist(struct Addressbooks * abs, string name){ 
    // string name; 可以直接作为参数接收进来
    // cin>>name;
    for(int i = 0; i < abs->m_Size; i++){
        if(name == abs->person[i].m_Name){
            return i; //找到了对应姓名，返回其下标
        }
    }
    return -1; //如果没有找到对应姓名
} 

//3.删除指定联系人
void deletePerson(struct Addressbooks *abs){
    string name;
    cout<<"请输入想要删除的联系人："<<endl;
    cin>>name;
    int ret = isExist(abs, name); //此时abs已经是指针形式了
    if(ret == -1){
        cout<<"查无此人！"<<endl;
    }else{
        for(int i = ret; i < abs->m_Size - 1; i++){ //这里前移操作必须要abs->m_Size-1，不然会越界
            abs->person[i] = abs->person[i+1];
        }
        abs->m_Size--;
    }
    cout<<"删除成功！"<<endl;
    system("pause");
    system("cls");
}

//4.查找联系人
void findPerson(struct Addressbooks * abs){
    string name;
    cout<<"请输入要查找的联系人："<<endl;
    cin>>name;
    int ret = isExist(abs, name);
    if(ret == -1){
        cout<<"查无此人！"<<endl;
    }else{
        cout<<"姓名："<<abs->person[ret].m_Name<<"\t";
        cout<<"性别："<<(abs->person[ret].m_Sex == 1 ? "男" : "女" )<<"\t";
        cout<<"年龄："<<abs->person[ret].m_Age<<"\t";
        cout<<"电话号码："<<abs->person[ret].m_Phone<<"\t";
        cout<<"家庭住址："<<abs->person[ret].m_Addr<<endl;
    }
    system("pause");
    system("cls");
}

//5.修改联系人
void modifyPerson(struct Addressbooks * abs){
    string name;
    cout<<"请输入要修改的联系人姓名："<<endl;
    cin>>name;
    int ret = isExist(abs, name);
    if(ret == -1){
        cout<<"查无此人！"<<endl;
    }else{
        cout<<"请输入联系人姓名："<<endl;
        cin>>abs->person[ret].m_Name;
        int sex = 0;
        cout<<"请输入联系人性别：1.男，2.女"<<endl;
        while(true){
            cin>>sex;
            if(sex == 1 || sex == 2){
                abs->person[ret].m_Sex = sex;
                break;
            }
            cout<<"输入有误，请重新输入："<<endl;
        }
        cout<<"请输入联系人年龄："<<endl;
        cin>>abs->person[ret].m_Age;
        cout<<"请输入联系人的电话号码："<<endl;
        cin>>abs->person[ret].m_Phone;
        cout<<"请输入联系人的家庭住址："<<endl;
        cin>>abs->person[ret].m_Addr;
        cout<<"修改成功！"<<endl;
    }
    system("pause");
    system("cls");
}

//6.清空联系人
void clearPerson(struct Addressbooks * abs){
    cout<<"确定是否清空联系人？"<<endl;
    cout<<"1--是，2--否"<<endl;
    while(true){
        int check = 0;
        cin>>check;
        if(check == 1){
            abs->m_Size = 0;  //将当前记录的联系人数量置为0，做一个逻辑上的清空即可！
            cout<<"已清空所有联系人！"<<endl;
            system("pause");
            system("cls");
            break;
        }else if(check == 2){
            cout<<"已取消清空所有联系人的操作,正为您返回主界面！"<<endl;
            system("pause");
            system("cls");
            break;
        }else{
            cout<<"输入错误，请重新输入！"<<endl;
        }
    }
    

}


int main(){
    //创建一个用户选择输入的变量
    int select = 0;
    //创建通讯录变量
    struct Addressbooks abs;
    abs.m_Size = 0;
    while(true){
        showMenu();
        //根据用户的选择进行跳转
        cin>>select;
         switch (select)
        {
        case 1:  //1、添加联系人
            addPerson(&abs);  //只有传入地址才能修改实参
            break;
        case 2:  //2、显示联系人
            showPerson(&abs); //其实此处可以使用值传递，但是会增加内存x开销
            break;
        case 3:  //3、删除联系人,按照姓名进行删除指定联系人的操作
            deletePerson(&abs);
            break;
        case 4:  //4、查找联系人
            findPerson(&abs);
            break;
        case 5:  //5、修改联系人
            modifyPerson(&abs);
            break;
        case 6:  //6、清空联系人
            clearPerson(&abs);
            break;
        case 0:  //0、退出通讯录
            cout<<"欢迎下次使用！"<<endl;
            system("pause");
            return 0;  //这一步就退出程序了
            // break;
        }
    }
   

    system("pause");
    return 0;
}