#include<iostream>
using namespace std;
//声明可以多次，定义只能一次 
//声明 int max(int a, int b); 
int max(int a, int b);  //老师的版本还需要声明，但是我这个版本已经不需要声明了，编译器越来越智能了

int main(){
    int a = 100;
    int b = 200;
    cout << max(a, b) << endl;

    return 0;
}

 //定义 
 int max(int a, int b) { 
    return a > b ? a : b; 
}