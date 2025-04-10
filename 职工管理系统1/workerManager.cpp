#include<iostream>
#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<string>
using namespace std;
//���캯��
workerManager::workerManager()
{
	//��ʼ��Ա������Ϊ0
	this->m_EmpNum = 0;
	//��ʼ��Ա������Ϊnullptr
	this->m_EmpArray = nullptr;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ������ݲ�Ϊ��
	int num = this->getEmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new worker * [this->m_EmpNum];
	this->initEmp();

}
//չʾ�˵�
void workerManager::showmenu()
{
	cout << "**********************************" << endl;
	cout << "**********��ӭʹ��ְ������ϵͳ****" << endl;
	cout << "**********1.���ְ����Ϣ**********" << endl;
	cout << "**********2.��ʾְ����Ϣ**********" << endl;
	cout << "**********3.ɾ��ְ����Ϣ**********" << endl;
	cout << "**********4.�޸�ְ����Ϣ**********" << endl;
	cout << "**********5.����ְ����Ϣ**********" << endl;
	cout << "**********6.���ձ������**********" << endl;
	cout << "**********7.���ְ����Ϣ**********" << endl;
	cout << "**********0.�˳�����ϵͳ**********" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}
//ʵ���˳�ϵͳ
void workerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}
//���ְ��
void workerManager::addEmp()
{
	cout << "���������ְ��������" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		//�����¿ռ��С
		int newsize = this->m_EmpNum + addnum;
		//�����¿ռ�
		worker** newspace = new worker * [newsize];
		//��ԭ�пռ��е����ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//����������
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int dselect;
			cout << "�������" << i + 1 << "����ְ����ţ�";
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������";
			cin >> name;
			cout << "��ѡ���ְ����λ��1.��ͨԱ�� 2.���� 3.�ϰ�" << endl;
			cin >> dselect;

			worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new employee(id, name, dselect);
				break;
			case 2:
				worker = new manager(id, name, dselect);
				break;
			case 3:
				worker = new boss(id, name, dselect);
				break;
			default:
				break;
			}
			//����ְ����Ϣ��ӵ��¿ռ���
			newspace[this->m_EmpNum+ i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//���¿ռ丳ֵ��ԭ�пռ�
		this->m_EmpArray = newspace;
		//����Ա������
		this->m_EmpNum = newsize;
		//�����ļ���Ϊ��
		this->m_FileIsEmpty = false;
		//�ɹ���Ӻ󣬱��浽�ļ���
		this->save();
		//��ʾ�ɹ����
		cout << "�ɹ����" << addnum << "��ְ��" << endl;
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}
//�����ļ�
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_Id << "  ";
		ofs << m_EmpArray[i]->m_Name << "  ";
		ofs << m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
//ͳ������
int workerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int depid;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> depid)
	{
		//��¼����
		num++;
	}
	ifs.close();
	return num;
}
//��ʼ��Ա��
void workerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int depid;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> depid)
	{
		//���ݸ�λ���ʹ�������
		worker* worker = NULL;
		if (depid == 1)
		{
			worker = new employee(id, name, depid);
		}
		else if (depid == 2)
		{
			worker = new manager(id, name, depid);
		}
		else
		{
			worker = new boss(id, name, depid);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}
//��ʾְ����Ϣ
void workerManager::showEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//�ж�ְ���Ƿ����
int workerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
//ɾ��ְ��
void workerManager::delEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerManager::modifyEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];
			int newId;
			string newName;
			int newDeptId;
			cout << "�������µ�ְ����ţ�";
			cin >> newId;
			cout << "�������µ�ְ��������";
			cin >> newName;
			cout << "��ѡ���ְ����λ��1.��ͨԱ�� 2.���� 3.�ϰ�" << endl;
			cin >> newDeptId;

			worker* worker = NULL;
			switch (newDeptId)
			{
			case 1:
				worker = new employee(newId, newName, newDeptId);
				break;
			case 2:
				worker = new manager(newId, newName, newDeptId);
				break;
			case 3:
				worker = new boss(newId, newName, newDeptId);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;
			this->save();
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����ְ��
void workerManager::findEmp()
{
	if(this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.����Ų���" << endl;
		cout << "2.����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			int id = 0;
			cin >> id;
			int index = this->isExist(id);
			if (index != -1)
			{
				cout << "���ҳɹ�����Ϣ����" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "������Ҫ���ҵ�ְ��������" << endl;
			string name;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�����Ϣ����" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
//����ְ��
void workerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.���������" << endl;
		cout << "2.����Ž���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minormax = 1;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (m_EmpArray[minormax]->m_Id > m_EmpArray[i]->m_Id)
					{
						minormax = j;
					}
				}
				else//����
				{
					if (m_EmpArray[minormax]->m_Id < m_EmpArray[i]->m_Id)
					{
						minormax = j;
					}
				}
			}


			//����
			if (i != minormax)
			{
				worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minormax];
				m_EmpArray[minormax] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->save();
		this->showEmp();
	}
}
//���ְ��
void workerManager::cleanFile()
{
	cout << "�Ƿ�����ļ���" << endl;
	cout << "1.���" << endl;
	cout << "2.ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//���������ɾ���ļ������´���
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	else
	{
		cout << "ȡ�����" << endl;
	}
	system("pause");
	system("cls");
}

//�������� 
workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
	}

}