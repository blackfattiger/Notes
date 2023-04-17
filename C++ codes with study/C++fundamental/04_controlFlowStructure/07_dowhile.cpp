#include<iostream>
using namespace std;
int main(){
//总结：与while循环区别在于，do...while先执行一次循环语句，再判断循环条件
    int num = 0;
    do
    {
    cout << num << endl;
    num++;
    } while (num < 10);
        return 0;
}