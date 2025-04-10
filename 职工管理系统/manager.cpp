#include"manager.h"
//构造函数
manager::manager(int id, string name, int depid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = depid;
}
//显示个人信息
void manager::showInfo()
{
	cout << "职工编号：" << m_Id << endl;
	cout << "职工姓名：" << m_Name << endl;
	cout << "岗位：" << this->getDeptName() << endl;
	cout << "岗位职责：完成老板交给的任务" << endl;
}
//获取岗位名称
string manager::getDeptName()
{
	return string("经理");
}