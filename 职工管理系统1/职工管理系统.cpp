#include<iostream>
using namespace std;
#include"workerManager.h"
int main()
{

	workerManager wm;
	int choice = 0;//�����洢�û�ѡ��
	while (true)
	{
		//չʾ�˵�
		wm.showmenu();
		cout << "����������ѡ��: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.addEmp();
			break;
		case 2://��ʾְ��
			wm.showEmp();
			break;
		case 3://ɾ��ְ��
			wm.delEmp();
			break;
		case 4://�޸�ְ��
			wm.modifyEmp();
			break;
		case 5://����ְ��
			wm.findEmp();
			break;
		case 6://����ְ��
			wm.sortEmp();
			break;
		case 7://����ļ�
			wm.cleanFile();
			break;
		default:
			system("cls");//����
			break;
		}
	}
	return 0;

}