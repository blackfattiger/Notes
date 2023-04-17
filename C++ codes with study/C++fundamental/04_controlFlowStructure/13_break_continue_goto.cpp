#include<iostream>
using namespace std;
int main(){
// 作用: 用于跳出==选择结构==或者==循环结构==
// break使用的时机：
// 出现在switch条件语句中，作用是终止case并跳出switch
// 出现在循环语句中，作用是跳出当前的循环语句
// 出现在嵌套循环中，跳出最近的内层循环语句
 //2、在循环语句中用break 
for (int i = 0; i < 10; i++) { 
     if (i == 5) { 
         break; //跳出循环语句 
         } 
cout << i << endl;

//在嵌套循环语句中使用break，退出内层循环 
for (int i = 0; i < 10; i++) { 
    for (int j = 0; j < 10; j++) { 
        if (j == 5) { 
            break; 
        } 
            cout << "*" << " ";
} 
    cout << endl; 
}


// continue语句
// 作用：在==循环语句==中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
    for (int i = 0; i < 100; i++)
    {
    if (i % 2 == 0)
    {
    continue;
    }
    cout << i << endl;
    }
// 注意：continue并没有使整个循环终止，而break会跳出循环


// goto语句
// 作用：可以无条件跳转语句
// 语法： goto 标记;
// 解释：如果标记的名称存在，执行到goto语句时，会跳转到标记的位置
    cout << "1" << endl;
    goto FLAG;
    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;
    FLAG:
    cout << "5" << endl;
    return 0;
 }