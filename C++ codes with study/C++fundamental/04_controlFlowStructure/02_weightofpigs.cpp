#include<iostream>
using namespace std;
int main(){
    double pig1 = 0, pig2 = 0, pig3 = 0;
    cout<<"请输出三只小猪的体重"<<endl;
    cin>>pig1>>pig2>>pig3;
    if(pig1>pig2){
        if(pig1>pig3){
            cout<<"最重的是：pig1,有"<<pig1<<"斤"<<endl;
        }else{
            cout<<"最重的是：pig3,有"<<pig3<<"斤"<<endl;
        }
    }else{
        if(pig2>pig3){
            cout<<"最重的是：pig2,有"<<pig2<<"斤"<<endl;
        }else{
            cout<<"最重的是：pig3,有"<<pig3<<"斤"<<endl;
        }
    }
    return 0;
}