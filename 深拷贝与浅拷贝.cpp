#include<iostream>
using namespace std;
class Person
{
    public:
    Person()
    {
        cout<<"Person的无参构造函数"<<endl;
    }
    Person(int weight ,int height)
    {
       m_height = new int (height);
       m_weight = weight;
        cout<<"Person的有参构造函数"<<endl;
    }
    ~Person()
    {
        cout<<"Person的析构函数"<<endl;
        delete m_height;
    }
    Person(const Person &p)
    {
     cout<<"Person的拷贝构造函数"<<endl;
        // m_height = p.m_height; // 浅拷贝，导致堆区内存重复释放，这是编译器默认的操作
        m_height = new int(*p.m_height); // 深拷贝，避免了内存重复释放的问题
        m_weight = p.m_weight;
    }
int *m_height;
int m_weight;
};
int main()
{
    
    Person p1(180, 70);
    Person p2 = p1; // 浅拷贝会导致堆区内存重复释放
    cout<<"p1的身高："<<*p1.m_height<<endl;
    cout<<"p2的身高："<<*p2.m_height<<endl;
    cout<<"p1的体重："<<p1.m_weight<<endl;
    cout<<"p2的体重："<<p2.m_weight<<endl;
    return 0;
}