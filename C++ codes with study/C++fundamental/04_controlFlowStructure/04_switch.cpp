#include<iostream>
using namespace std;
int main(){
// 注意1：switch语句中表达式类型只能是整型或者字符型
// 注意2：case里如果没有break，那么程序会一直向下执行
// 总结：与if语句比，对于多条件判断时，switch的结构清晰，执行效率高，缺点是switch不可以判断区间
    int grad = 0;
    cout<<"请您为这部电影打分"<<endl;
    cin>>grad;
    // switch (grad)
    // {
    // case grad>=9：
    //     cout<<"这是一部经典影片"<<endl;
    //     break;
    // case grad>=7&&grad<9：
    //     cout<<"这是一部经典影片"<<endl;
    //     break;
    // case grad>=5&&grad<7：
    //     cout<<"这是一部经典影片"<<endl;
    //     break;
    // default:
    //     cout<<"这是一部烂片"<<endl;
    //     break;
    // }  case中不能比较,而且case后面的条件需要时整数类型
    switch (grad)
    {
    case 10:
    case 9:
    cout << "经典" << endl;
    break;
    case 8:
    cout << "非常好" << endl;
    break;
    case 7:
    case 6:
    cout << "一般" << endl;
    break;
    default:
    cout << "烂片" << endl;
    break;
}




    return 0;
}