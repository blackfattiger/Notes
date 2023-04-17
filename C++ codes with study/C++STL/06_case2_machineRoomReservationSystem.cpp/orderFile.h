#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"global.h"
#include<fstream>

class orderFile{
public:
    //构造函数
    orderFile();

    //更新预约记录
    void updateOrder();

    //记录订单信息的容器
    map<int, map<string, string>> m_orderData; //参数1 记录的条数， 参数2 订单号对应的具体订单键值对信息

    //预约记录条数
    int m_Size;
};