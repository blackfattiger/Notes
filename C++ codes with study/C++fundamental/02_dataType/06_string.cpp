#include<iostream>
using namespace std;
int main(){
    //1.C语言风格的字符串
    char ctype[] = "thisisctype\n";  //字符串处，1.char 字符串名 [] ; 2.用双引号而不是单引号，

    //2.C++语言风格的字符串；  老版本需要#include<string>
    string cpptype = "thisiscpptype";

    cout<<ctype<<cpptype<<endl;

    return 0;
}
