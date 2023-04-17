#include<iostream>
using namespace std;
int main(){
    //选择结构-单行if语句
    //输入一个分数，如果分数大于600分，视为考上一本大学，并在屏幕上打印
    int score = 0;
    cout << "请输入一个分数：" << endl;
    cin >> score;
    cout << "您输入的分数为： " << score << endl;
    //if语句
    //注意事项，在if判断语句后面，不要加分号
    if (score > 600)
    {
    cout << "我考上了一本大学！！！" << endl;
    }

    //if-else
    int score1 = 0;
    cout << "请输入考试分数：" << endl;
    cin >> score1;
    if (score1 > 600)
    {
    cout << "考上了一本大学" << endl;
    }
    else
    {
    cout << "未考上一本大学" << endl;
    }

    //if-else if -else
    int score2 = 0;
    cout<<"请输入你的分数："<<endl;
    cin>>score2;
    cout<<"你的分数为："<<score2<<endl;

    if(score2>600){
        cout<<"考上了一本大学！"<<endl;
    }else if(score2>500){
        cout<<"考上了二本大学！"<<endl;
    }else if(score2>400){
        cout<<"考上了三本大学！"<<endl;
    }else{
        cout<<"很遗憾，你可能要再读一年"<<endl;
    }

    //嵌套if语句
    int score3 = 0;
    cout << "请输入考试分数：" << endl;
    cin >> score3;
    if (score3 > 600)
    {
    cout << "我考上了一本大学" << endl;
    if (score3 > 700)
    {
    cout << "我考上了北大" << endl;
    }
    else if (score3 > 650)
    {
    cout << "我考上了清华" << endl;
    }
    else
    {
    cout << "我考上了人大" << endl;
    }
    }
    else if (score3 > 500)
    {
    cout << "我考上了二本大学" << endl;
    }
    else if (score3 > 400)
    {
    cout << "我考上了三本大学" << endl;
    }
    else
    {
    cout << "我未考上本科" << endl;
    }

    return 0;
}