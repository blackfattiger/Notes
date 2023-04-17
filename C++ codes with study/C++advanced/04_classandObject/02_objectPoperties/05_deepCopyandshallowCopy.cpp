// 深浅拷贝是面试经典问题，也是常见的一个坑
// 浅拷贝：简单的赋值拷贝操作 （编译器提供的等号赋值操作）
// 深拷贝：在堆区重新申请空间（申请一块新的空间），再进行拷贝操作

// 如果堆区有内存，那么析构函数就派上用场了

// 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题


#include <iostream>
using namespace std;

class Person { 
public: 
    //无参（默认）构造函数 
    Person() { 
        cout << "无参构造函数!" << endl; 
    } 
    //有参构造函数 
    Person(int age ,int height) {
        cout << "有参构造函数!" << endl;
        m_age = age;
        m_height = new int(height);
    }   
    //拷贝构造函数
    //浅拷贝的问题要利用深拷贝进行解决
    //自己实现一个拷贝构造函数，解决浅拷贝带来的问题
    Person(const Person& p) {
        cout << "拷贝构造函数!" << endl;
        m_age = p.m_age;
    //如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
        //m_height = p.m_height;  在编译器默认实现的拷贝构造函数中，就是这行代码
        m_height = new int(*p.m_height); //把要拷贝的对象里的指针p.m_height解引用获取指向的值，再放入新开辟的堆区空间中
    }
    //析构函数
    ~Person() {
        cout << "析构函数!" << endl;
        if (m_height != NULL){
            delete m_height;
            m_height = NULL;
        }
    }
public: 
    int m_age; 
    int* m_height; 
};


void test01() { 
    Person p1(18, 180); 
    Person p2(p1);  //若为浅拷贝，那么此处 p2与p1的m_height会指向同一个堆区，在析构函数中进行清理时会出现堆区内存重复释放的问题
    cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
    cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}


int main(){
    test01();
    system("pause");

    return 0;
}