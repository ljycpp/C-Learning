#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;
class boss : public worker
{
public:
	//构造函数
	boss(int id, string name, int depid);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};
