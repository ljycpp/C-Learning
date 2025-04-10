#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt" //�ļ���
using namespace std;
class workerManager
{
public:
	//���캯��
	workerManager();
	//չʾ�˵�
	void showmenu();
	//ʵ���˳�ϵͳ
	void exitSystem();
	//��¼�ļ��е���������
	int m_EmpNum;
	//Ա�������ָ��
	worker** m_EmpArray;
	//���ְ��
	void addEmp();
	//�����ļ�
	void save();
	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	//ͳ������
	int getEmpNum();
	//��ʼ��Ա��
	void initEmp();
	//��ʾְ����Ϣ
	void showEmp();
	//ɾ��ְ��
	void delEmp();
	//�ж�ְ���Ƿ����
	int isExist(int id);
	//�޸�ְ��
	void modifyEmp();
	//����ְ��
	void findEmp();
	//����ְ��
	void sortEmp();
	//���ְ��
	void cleanFile();

	//��������
	~workerManager();
};
