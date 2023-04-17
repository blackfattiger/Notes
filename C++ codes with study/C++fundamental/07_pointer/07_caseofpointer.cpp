//1.学会如何将数组传入函数，传入的是数组的首地址，都需要用 int* arr 去接收首地址
//2.熟练冒泡排序
//3.传入数组长度不要写死
#include <iostream>
using namespace std;
// 案例描述：封装一个函数，利用冒泡排序，实现对整型数组的升序排序
// 例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

//冒泡排序函数  参数1 数组的首地址   参数2 数组的长度
void bublesort(int* arr, int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1 ; j++){
            // if(*arr > *(arr + 1)){
            //     int temp = *arr;
            //     *arr = *(arr + 1);
            //     *(arr + 1) = temp;
            //     arr++;//这样的话 arr一直在增加
            // }
            if(arr[j] > arr[j+1]){
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp;
            }
        }
    }

}

int main(){
    //1.先创建数组
    int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
    //数组长度
    int len = sizeof(arr)/sizeof(arr[0]);
    //2.创建函数，实现冒泡排序
    bublesort(arr, len);
    //打印排序后的数组
    for(int i = 0; i < len; i++){
        cout<<arr[i];
    }
    return 0;
}