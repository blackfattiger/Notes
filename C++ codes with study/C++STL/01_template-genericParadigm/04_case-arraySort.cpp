// 1.2.3 函数模板案例
// 案例描述：
// 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
// 排序规则从大到小，排序算法为选择排序
// 分别利用char数组和int数组进行测试

// 总结：模板可以提高代码复用，需要熟练掌握

#include<iostream>
using namespace std;

//交换的函数模板
template<typename T>
void mySwap(T &a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}

//利用模板封装排序函数，针对不同类型的数组
template<typename T>
void mySort(T arr[], int len){
    //升序排序，利用选择排序————要把最小的放在前面
    // int len = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < len; i++){
        int max = i; //指定最大的数
        for(int j = i + 1; j < len; j++){   //j每一轮都从 i + 1 开始，因为i之前的位置已经被固定住了，不需要再比较
            if(arr[j] > arr[max]){
                max = j;   //因为这个最大值都只是暂时的，知道循环结束才能确定这一轮的最小值
            }
        }
        // if(max != i){   //如果记录最小值的数和最开始指定的不同就需要交换他们在数组中的位置
        //     int temp = arr[max];
        //     arr[max] = arr[i];
        //     arr[i] = temp;
        // }
        mySwap(arr[max], arr[i]);
    }
    // return arr;  //最开始我的返回类型是T，但是数组不能被直接赋值，得用一个循环，所以还是定义返回类型为空好了

}

template<typename T> 
void printArray(T arr[], int len) {   //T arr[] 与 T *arr 相同，后者传入的是数组arr首位置元素的指针
    for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
}
    cout << endl;
}

//用int 和 char 数组进行测试
void test01()
{
    //测试char数组
    char charArr[] = "bdcfeagh";
    int num = sizeof(charArr) / sizeof(char);
    // char sortArray[] = choiceSort(charArr);
    mySort(charArr, num);
    printArray(charArr, num);
    // for (int i = 0; i < len; i++) {
    // cout << sortarr[i] << " ";
    // }
    // cout << endl;

}

void test02()
{
    //测试int数组
    int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}
