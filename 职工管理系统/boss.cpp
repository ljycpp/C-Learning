#include<iostream>
#include<string>
#include"boss.h"	
using namespace std;
//构造函数
boss::boss(int id, string name, int depid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = depid;
}
//显示个人信息
void boss::showInfo()
{
	cout << "职工编号：" << m_Id << endl;
	cout << "职工姓名：" << m_Name << endl;
	cout << "岗位：" << this->getDeptName() << endl;
	cout << "岗位职责：管理公司所有事务" << endl;
}
//获取岗位名称
string boss::getDeptName()
{
	return string("老板");
}