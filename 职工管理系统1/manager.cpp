#include"manager.h"
//���캯��
manager::manager(int id, string name, int depid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = depid;
}
//��ʾ������Ϣ
void manager::showInfo()
{
	cout << "ְ����ţ�" << m_Id << endl;
	cout << "ְ��������" << m_Name << endl;
	cout << "��λ��" << this->getDeptName() << endl;
	cout << "��λְ������ϰ彻��������" << endl;
}
//��ȡ��λ����
string manager::getDeptName()
{
	return string("����");
}