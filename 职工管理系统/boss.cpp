#include<iostream>
#include<string>
#include"boss.h"	
using namespace std;
//���캯��
boss::boss(int id, string name, int depid)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = depid;
}
//��ʾ������Ϣ
void boss::showInfo()
{
	cout << "ְ����ţ�" << m_Id << endl;
	cout << "ְ��������" << m_Name << endl;
	cout << "��λ��" << this->getDeptName() << endl;
	cout << "��λְ�𣺹���˾��������" << endl;
}
//��ȡ��λ����
string boss::getDeptName()
{
	return string("�ϰ�");
}