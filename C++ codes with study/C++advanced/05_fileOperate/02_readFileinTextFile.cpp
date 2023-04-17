// 5.1.2读文件
// 读文件与写文件步骤相似，但是读取方式相对于比较多
// 读文件步骤如下：
// 1. 包含头文件
// #include <fstream>
// 2. 创建流对象
// ifstream ifs;
// 3. 打开文件并判断文件是否打开成功
// ifs.open("文件路径",打开方式);
// 4. 读数据
// 四种方式读取
// 5. 关闭文件
// ifs.close();


// 总结：
// 读文件可以利用 ifstream ，或者fstream类
// 利用is_open函数可以判断文件是否打开成功
// close 关闭文件


#include<iostream>
using namespace std;
#include<fstream>

void test01(){
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    //判断打开是否成功
    if(!ifs.is_open()){
        cout<<"打开文件失败！"<<endl;
        return;
    }
    //第一种  //第一种读取方式会把空格识别为换行
    // char buf[1024] = {0};
    // while(ifs>>buf){
    //     cout<<buf<<endl;
    // }

    //第二种 
    // char buf[1024] = {0};
    // while(ifs.getline(buf, sizeof(buf))){  //参数为： 数据放入的地址， 最多读多少字节数（准备的空间大小）
    //     cout<<buf<<endl;
    // }

    //第三种
    string buf;
    while(getline(ifs, buf)){ //这些函数都会返回是否后面还有可读内容，如果没有就会返回false ，从而就退出了循环
        cout<<buf<<endl;
    }

    //第四种   不推荐，因为是一个字节一个字节读速度比一行一行读慢
    // char c;
    // while ((c = ifs.get()) != EOF)  //EOF： end of file
    // {
    //     cout<<c;
    // }
    
    ifs.close();
}

int main(){
    test01();
    return 0;
}
