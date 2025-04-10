//普通员工
#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"
class employee : public worker
{
public:
	//构造函数
	employee(int id,string name,int depid);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
