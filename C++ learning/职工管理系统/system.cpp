#include"WorkerManager.h"
int main()
{
	WorkerManager wm;
	int choice;
	while (true)
	{
		wm.Showmanu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.ExitSystem();//�˳�ϵͳ
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