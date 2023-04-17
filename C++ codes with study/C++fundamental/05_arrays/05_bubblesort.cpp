#include<iostream>
using namespace std;
int main(){
// 作用： 最常用的排序算法，对数组内元素进行排序
// 1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
// 2. 对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。
// 3. 重复以上的步骤，每次比较次数-1，直到不需要比较
    int arr[9] = {1,3,2,5,4,8,9,7,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    int temp = 0;
    for(int i = len-1; i > 0; i--){
        // cout<<"i:"<<i<<endl;
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                // cout<<"j内:"<<j<<endl;
            }
            // cout<<"j外:"<<j<<endl;
        }
    }
    for(int i = 0; i < len ; i++){
        cout<<arr[i];
    }
    return 0;
}