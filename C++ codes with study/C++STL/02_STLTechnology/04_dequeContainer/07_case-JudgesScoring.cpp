// 3.4 案例-评委打分
// 3.4.1 案例描述
// 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
// 3.4.2 实现步骤
// 1. 创建五名选手，放到vector中
// 2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
// 3. sort算法对deque容器中分数排序，去除最高和最低分
// 4. deque容器遍历一遍，累加总分
// 5. 获取平均分

// 总结： 选取不同的容器操作数据，可以提升代码的效率

#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

class Person{
public:
    Person(int score, string name){
        this->m_Name = name;
        this->m_Score = score;
    }

    int m_Score;
    string m_Name;
};

void createPerson(vector<Person> &v){ //利用引用修改实参
    string nameSeed = "ABCDE";
    for(int i = 0; i < 5; i++){
        string name = "选手";
        name += nameSeed[i];
        int score = 0;
        Person p(score,name);
        //将创建的Person对象放入容器中
        v.push_back(p);
    }
}

//打分
void setScore(vector<Person>& v){
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        //将评委的分数放入到deque容器中
        deque<int> d;
        for(int i = 0; i < 10; i++){
            int score = rand()%41 + 60; //随机分在60-100之间
            d.push_back(score);
        }

        // cout << "选手： " << it->m_Name << " 打分： " << endl;
        // for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        // {
        // cout << *dit << " ";
        // }
        // cout << endl;

        //对打分排序
        sort(d.begin(), d.end());
        //排好序后去除一个最高分和一个最低分
        d.pop_front();
        d.pop_back();
        int sum = 0;
        for(int i = 0; i < d.size(); i++){
            sum += d[i];  //累加每个评委的分数
        }
        int average = sum/d.size();
        (*it).m_Score = average;
    }

}

void showScore(vector<Person>&v){
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout<<(*it).m_Name<<" 平均分为："<<it->m_Score<<endl;
    }
}

int main(){
    //随机数种子
    srand((unsigned int)time(NULL));

    //1.创建5名选手
    vector<Person> v; //创建选手容器
    createPerson(v);

    //测试
    // for(int i = 0; i < v.size(); i++){  //错误是因为vector中存放的是Person类型，不能直接输出
    //     cout<<v[i]<<" ";
    // }
    // for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
    //     cout<<"姓名："<<(*it).m_Name<<" 分数："<<(*it).m_Score<<endl;
    // }

    //2.给5名选手打分
    setScore(v);

    //3.平均分打印
    showScore(v);

    return 0;
}