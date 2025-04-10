#include<iostream>
#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<string>
using namespace std;
//构造函数
workerManager::workerManager()
{
	//初始化员工人数为0
	this->m_EmpNum = 0;
	//初始化员工数组为nullptr
	this->m_EmpArray = nullptr;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，且数据不为空
	int num = this->getEmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new worker * [this->m_EmpNum];
	this->initEmp();

}
//展示菜单
void workerManager::showmenu()
{
	cout << "**********************************" << endl;
	cout << "**********欢迎使用职工管理系统****" << endl;
	cout << "**********1.添加职工信息**********" << endl;
	cout << "**********2.显示职工信息**********" << endl;
	cout << "**********3.删除职工信息**********" << endl;
	cout << "**********4.修改职工信息**********" << endl;
	cout << "**********5.查找职工信息**********" << endl;
	cout << "**********6.按照编号排序**********" << endl;
	cout << "**********7.清空职工信息**********" << endl;
	cout << "**********0.退出管理系统**********" << endl;
	cout << "**********************************" << endl;
	cout << endl;
}
//实现退出系统
void workerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}
//添加职工
void workerManager::addEmp()
{
	cout << "请输入添加职工数量：" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		//计算新空间大小
		int newsize = this->m_EmpNum + addnum;
		//开辟新空间
		worker** newspace = new worker * [newsize];
		//将原有空间中的数据拷贝到新空间中
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//输入新数据
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int dselect;
			cout << "请输入第" << i + 1 << "个新职工编号：";
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：";
			cin >> name;
			cout << "请选择该职工岗位：1.普通员工 2.经理 3.老板" << endl;
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
			//将新职工信息添加到新空间中
			newspace[this->m_EmpNum+ i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//将新空间赋值给原有空间
		this->m_EmpArray = newspace;
		//更新员工人数
		this->m_EmpNum = newsize;
		//更新文件不为空
		this->m_FileIsEmpty = false;
		//成功添加后，保存到文件中
		this->save();
		//显示成功添加
		cout << "成功添加" << addnum << "名职工" << endl;
	}
	else
	{
		cout << "输出有误" << endl;
	}
	system("pause");
	system("cls");
}
//保存文件
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
//统计人数
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
		//记录人数
		num++;
	}
	ifs.close();
	return num;
}
//初始化员工
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
		//根据岗位类型创建对象
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
//显示职工信息
void workerManager::showEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
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
//判断职工是否存在
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
//删除职工
void workerManager::delEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号：" << endl;
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
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerManager::modifyEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];
			int newId;
			string newName;
			int newDeptId;
			cout << "请输入新的职工编号：";
			cin >> newId;
			cout << "请输入新的职工姓名：";
			cin >> newName;
			cout << "请选择该职工岗位：1.普通员工 2.经理 3.老板" << endl;
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
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找职工
void workerManager::findEmp()
{
	if(this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入要查找的职工编号：" << endl;
			int id = 0;
			cin >> id;
			int index = this->isExist(id);
			if (index != -1)
			{
				cout << "查找成功，信息如下" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "请输入要查找的职工姓名：" << endl;
			string name;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，信息如下" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
//排序职工
void workerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按编号升序" << endl;
		cout << "2.按编号降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minormax = 1;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (m_EmpArray[minormax]->m_Id > m_EmpArray[i]->m_Id)
					{
						minormax = j;
					}
				}
				else//降序
				{
					if (m_EmpArray[minormax]->m_Id < m_EmpArray[i]->m_Id)
					{
						minormax = j;
					}
				}
			}


			//交换
			if (i != minormax)
			{
				worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minormax];
				m_EmpArray[minormax] = temp;
			}
		}
		cout << "排序成功" << endl;
		this->save();
		this->showEmp();
	}
}
//清空职工
void workerManager::cleanFile()
{
	cout << "是否清空文件？" << endl;
	cout << "1.清空" << endl;
	cout << "2.取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//如果存在则删除文件并重新创建
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
		cout << "清空成功" << endl;
	}
	else
	{
		cout << "取消清空" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数 
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