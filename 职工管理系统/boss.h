#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;
class boss : public worker
{
public:
	//���캯��
	boss(int id, string name, int depid);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
