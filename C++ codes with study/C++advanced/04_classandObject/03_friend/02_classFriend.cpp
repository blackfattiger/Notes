
#include <iostream>
using namespace std;

class Building;

class GoodGay{
public:
    GoodGay();
    void visit();
public:
    Building * building;
};

class Building{
    friend class GoodGay;

public:
    Building();

public:
    string m_sittingRoom;  //客厅
private:
    string m_bedRoom;       //卧室

};

//类外实现成员函数
Building::Building(){
    m_sittingRoom = "客厅";
    m_bedRoom = "卧室";
}

void GoodGay::visit(){
    cout<<"好基友正在访问： "<<building->m_sittingRoom<<endl;
    cout<<"好基友正在访问： "<<building->m_bedRoom<<endl;  //没有添加友元的时候私有属性是无法访问的
}

GoodGay::GoodGay(){
    building = new Building;
}

void test01(){
    GoodGay gg;
    gg.visit();

}


int main(){
    test01();

    return 0;
}