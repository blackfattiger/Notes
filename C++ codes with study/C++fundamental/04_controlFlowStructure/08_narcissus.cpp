#include<iostream>
using namespace std;
// 练习案例：水仙花数
// 案例描述：水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身
// 例如：1^3 + 5^3+ 3^3 = 153
// 请利用do...while语句，求出所有3位数中的水仙花数
int main(){
    int num = 999;
    do
    {
    int a= num/100; //百位
    int b= (num/10)%10;//十位
    int c= num%10; //个位
    if(a*a*a+b*b*b+c*c*c == num){
        cout<<num<<endl;
    }
    num--;
    } while (num > 100);
        return 0;
}