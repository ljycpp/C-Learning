#include<iostream>
using namespace std;
#include"workerManager.h"
int main()
{

	workerManager wm;
	int choice = 0;//用来存储用户选择
	while (true)
	{
		//展示菜单
		wm.showmenu();
		cout << "请输入您的选择: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.addEmp();
			break;
		case 2://显示职工
			wm.showEmp();
			break;
		case 3://删除职工
			wm.delEmp();
			break;
		case 4://修改职工
			wm.modifyEmp();
			break;
		case 5://查找职工
			wm.findEmp();
			break;
		case 6://排序职工
			wm.sortEmp();
			break;
		case 7://清空文件
			wm.cleanFile();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	return 0;

}