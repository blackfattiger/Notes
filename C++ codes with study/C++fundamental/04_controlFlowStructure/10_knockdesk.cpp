#include<iostream>
using namespace std;
int main(){
    // int num = 0;

    for (int i = 0; i <= 100; i++)
    {
    if(i%10==7||i/10==7||i%7==0){
        cout<<"敲桌子,此时数字为："<<i<<endl;
    }else{
        cout<<"数字为："<<i<<endl;
    }
    }
    return 0;
 }