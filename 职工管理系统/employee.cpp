#include<iostream>
#include<string>
#include"employee.h"	
using namespace std;
//���캯��
employee::employee(int id,string name,int depid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = depid;
}
//��ʾ������Ϣ
 void employee::showInfo()
{
	 cout << "ְ����ţ�" << m_Id << endl;
	 cout << "ְ��������" << m_Name << endl;
	 cout << "��λ��" << this->getDeptName() << endl;
	 cout << "��λְ����ɾ�����������" << endl;
}
//��ȡ��λ����
 string employee::getDeptName()
{
	 return string("��ͨԱ��");
}