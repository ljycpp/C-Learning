//��ͨԱ��
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"
class employee : public worker
{
public:
	//���캯��
	employee(int id,string name,int depid);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
