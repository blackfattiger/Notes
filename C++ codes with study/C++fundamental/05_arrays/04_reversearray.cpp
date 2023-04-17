#include<iostream>
using namespace std;
int main(){
//     练习案例2：数组元素逆置
// 案例描述：请声明一个5个元素的数组，并且将元素逆置.
// (如原数组元素为：1,3,2,5,4;逆置后输出结果为:4,5,2,3,1)
    int arr[5] = {1,3,2,5,4};
    int i=0;
    int j= sizeof(arr)/sizeof(arr[0])-1;
    while (i<j) //i<j即可 不需要i<=j
    {
        int c = 0;
        c=arr[i];
        arr[i]=arr[j];
        arr[j]=c;
        i++;
        j--;  //经常后面一个指针我要写成j++，错在哪里还半天找不到
    }
    for(int k=0;k<=4;k++){
        cout<<arr[k];
    }

    return 0;
}