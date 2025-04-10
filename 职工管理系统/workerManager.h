#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt" //文件名
using namespace std;
class workerManager
{
public:
	//构造函数
	workerManager();
	//展示菜单
	void showmenu();
	//实现退出系统
	void exitSystem();
	//记录文件中的人数个数
	int m_EmpNum;
	//员工数组的指针
	worker** m_EmpArray;
	//添加职工
	void addEmp();
	//保存文件
	void save();
	//标志文件是否为空
	bool m_FileIsEmpty;
	//统计人数
	int getEmpNum();
	//初始化员工
	void initEmp();
	//显示职工信息
	void showEmp();
	//删除职工
	void delEmp();
	//判断职工是否存在
	int isExist(int id);
	//修改职工
	void modifyEmp();
	//查找职工
	void findEmp();
	//排序职工
	void sortEmp();
	//清空职工
	void cleanFile();

	//析构函数
	~workerManager();
};
