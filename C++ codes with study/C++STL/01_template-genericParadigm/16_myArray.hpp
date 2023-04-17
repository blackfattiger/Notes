#pragma once
#include<iostream>
using namespace std;

template<class T>
class myArray{
public:
    //有参构造  参数：容量
    myArray(int capacity){
        cout<<"myArray有参构造调用"<<endl;
        // 理解：这里只需要new  一个指针（内存地址） 这个地址里面放着一个模板数组   大小是len
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    //拷贝构造,把一个对象的属性完全拷贝给另一个对象
    myArray(const myArray& arr){
        cout<<"myArray拷贝构造调用"<<endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->pAddress = arr.pAddress; //浅拷贝会出现问题
        //利用深拷贝
        this->pAddress = new T[arr.m_Capacity];
        //并将arr中的数据全部拷贝过来
        for(int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // 如果不写等号重载函数，只有拷贝构造函数的话，编译器会提示缓冲区溢出
    //operator= 防止浅拷贝问题
    myArray& operator=(const myArray& arr){  //返回类型为类对象引用，满足链式编程
        cout<<"myArray operator= 调用"<<endl;
        //先判断原来堆区是否有数据，如果有先释放
        if(this->pAddress != NULL){
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
         
        for(int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;  //返回自身对象
    }

    //尾插法
    void Push_Back(const T& val){  //防止数据被修改
        if(this->m_Size < this->m_Capacity){
            this->pAddress[this->m_Size] = val; //在数组的最后一个位置插入数据
            this->m_Size++; //更新数组大小
        }else{
            return;
        }
    }
    
    //尾删法
    void Pop_Back(){  //删除最后一个元素，不需要传入参数
        if(this->m_Size > 0){
            // this->pAddress[this->m_Size - 1] = 0;
            //逻辑删除： 让用户访问不到最后一个元素，即为尾删
            this->m_Size--;
        }else{
            return;
        }
    }

    //通过下标方式访问数组中的元素
    //如果想要对数组值进行更改,即将其当作可修改的左值使用,如：arr[0] = 100, 就需要返回类型为引用，这样返回的才是同一个对象，而不是临时创建的新对象
    T& operator[](int index){  //类里面不需要传入本对象 ，如：const myArray& arr
        return this->pAddress[index];
    }

    //返回数组的容量
    int getCapacity(){
        return this->m_Capacity;
    }
    //返回数组的大小
    int getSize(){
        return this->m_Size;
    }

    //析构函数
    ~myArray(){
        cout<<"myArray析构函数调用"<<endl;
        if(this->pAddress != NULL){
            delete[] this->pAddress;
            this->pAddress = NULL;
        }

    }

private:
    //数组
    T * pAddress; //指针指向堆区开辟的真实数组
    //容量
    int m_Capacity;
    //大小
    int m_Size;
};