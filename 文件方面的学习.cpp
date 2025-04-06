#include<fstream>//文件操作需要包含的头文件
#include<iostream>
#include<string>
//文本文件，写文件
using namespace std;
void test01()
{
    //1.包含头文件
    //2.创建流对象
    ofstream ofs;
    //3.指定打开方式
    ofs.open("test.txt", ios::out | ios::app);//ios::out表示写文件，ios::app表示追加写入
    //4.写内容
     ofs<<"我要努力成为最棒的"<<endl;
     ofs<<"程序员"<<endl;
     //5.关闭文件
     ofs.close();   

}
//文本文件，读文件
void test02()
{
    //1.包含头文件
    //2.创建流对象
    ifstream ifs;
    //3.打开文件
    ifs.open("test.txt", ios::in);//ios::in表示读文件
    //3.1.判断文件是否打开成功
    if(!ifs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        return;
    }  
    //4.读内容
    string str;
    // getline(ifs, str); //读一行
    // cout<<str<<endl; //输出读到的内容
    while(getline(ifs, str)) //读一行
    {
        cout<<str<<endl; //输出读到的内容
    }
    //5.关闭文件
    ifs.close();   
}
//通过二进制的方式读写文件
class Person
{
    public:
    char m_name[64]; //姓名
    int m_age;//年龄
};
void test03()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out | ios::binary);//ios::binary表示二进制文件
    Person p1={"张三", 18};
    ofs.write((const char *)&p1, sizeof(Person));//将对象写入文件
    ofs.close();//关闭文件
}
void test04()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in | ios::binary);//ios::binary表示二进制文件
    if(!ifs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        return;
    }
    Person p2;
    ifs.read(( char *)&p2, sizeof(Person));//从文件中读取对象
    cout<<"姓名："<<p2.m_name<<endl;
    cout<<"年龄："<<p2.m_age<<endl;
    ifs.close();//关闭文件
}



int main()
{
   // test01();
   // test02();
   // test03();
   // test04();
    return 0;
}

