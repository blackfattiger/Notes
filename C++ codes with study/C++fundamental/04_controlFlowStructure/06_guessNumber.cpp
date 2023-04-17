#include<iostream>
#include<ctime>
using namespace std;
int main(){
    //添加随机数种子，利用系统时间生成随机数，防止每次随机数都是一样的
    srand((unsigned int)time(NULL));

    int gnum =0;
    int num = rand()%100 +1;    //对100取余只能生成0~99的随机数，所以要+1
    while (num != gnum)
    {
    cout << "请您猜一个数字"  << endl;
    cin>>gnum;
    if(gnum<num){
        cout<<"猜小了，请重猜"<<endl;
    }else if(gnum>num){
        cout<<"猜大了，请重猜"<<endl;
    }
    }
    cout<<"恭喜你，猜对了！"<<endl; //这一行也可以放在循环内部，猜对之后用break退出
    return 0;
}