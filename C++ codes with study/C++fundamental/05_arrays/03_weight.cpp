// 练习案例1：五只小猪称体重
// 案例描述：
// 在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250};
// 找出并打印最重的小猪体重。
#include<iostream>
using namespace std;
int main(){
    int arr[5] = {300,350,200,400,250};
    int max = 0;    //先认定一个最大值
    for(int i=0;i<5;i++){
        if(max<arr[i]){   //如果有比最大值大的值，就更新最大值
            max = arr[i];
        }
    }
    cout<<max<<endl;
    return 0;
}