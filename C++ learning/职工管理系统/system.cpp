#include"WorkerManager.h"
int main()
{
	WorkerManager wm;
	int choice;
	while (true)
	{
		wm.Showmanu();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.ExitSystem();//退出系统
			return 0;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
		}
		system("cls");
	}
}