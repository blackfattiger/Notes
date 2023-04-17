#include<iostream>
using namespace std;
int main(){
// 考试成绩统计：
// 案例描述：有三名同学（张三，李四，王五），在一次考试中的成绩分别如下表，请分别输出三名同学的总成绩
// | | 语文 | 数学 | 英语 | | ---- | ---- | ---- | ---- | | 张三 | 100 | 100 | 100 | | 李四 | 90 | 50 | 100 | | 王五 | 60 | 70 | 80 |
    int score[3][3] = {
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };
    // cout<<"张三的总成绩为："<<score[0][0] + score[0][1] + score[0][2]<<endl;
    // cout<<"李四的总成绩为："<<score[1][0] + score[1][1] + score[1][2]<<endl;
    // cout<<"王五的总成绩为："<<score[2][0] + score[2][1] + score[2][2]<<endl;
    string name[] = {"张三","李四","王五"};
    for(int i = 0; i < 3; i++){
        int sum = 0; //每一轮再重置一次
        for(int j = 0; j<3; j++){
            sum += score[i][j];
        }
        cout<<name[i]<<"的成绩为:"<<sum<<endl;
    }
    system("pause");
    return 0;
}