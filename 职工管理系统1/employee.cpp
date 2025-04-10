#include<iostream>
#include<string>
#include"employee.h"	
using namespace std;
//构造函数
employee::employee(int id,string name,int depid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = depid;
}
//显示个人信息
 void employee::showInfo()
{
	 cout << "职工编号：" << m_Id << endl;
	 cout << "职工姓名：" << m_Name << endl;
	 cout << "岗位：" << this->getDeptName() << endl;
	 cout << "岗位职责：完成经理交给的任务" << endl;
}
//获取岗位名称
 string employee::getDeptName()
{
	 return string("普通员工");
}