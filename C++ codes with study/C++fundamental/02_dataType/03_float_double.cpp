#include<iostream>
using namespace std;
int main(){
    // 单精度 float
    float f1 = 3.14f;  //如果结尾不加f，系统会将小数默认为double类型
    // 双精度 double
    double d1 = 3.14;
    //默认情况下，输出一个小数，会显示出6位有效数字
    //查看占用内存  float 4字节， double 8字节
    cout<<sizeof(float)<<endl;
    cout<<sizeof(double)<<endl;
    //科学计数法
    float s1 = 3e2; // 3 * 10 ^ 2
    float s2 = 3e-2; // 3 * 0.1 ^ 2 (3 * 10 ^ -2)

    return 0;
} 