#pragma once

#include<iostream>
#include"worker.h"
using namespace std;
class manager :public worker
{
public:
	//构造函数
	manager(int id, string name, int depid);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
