#include<iostream>
using namespace std;
int main(){
    for(int j=1;j<10;j++){

        for(int i=1;i<=j;i++){
            cout<<i<<"x"<<j<<"="<<i*j<<" ";
            // if(i*j<10){
            //     cout<<" ";
            // }else{
            //     cout<<"  ";
            }
        
        cout<<endl;
    }
    return 0;
 }