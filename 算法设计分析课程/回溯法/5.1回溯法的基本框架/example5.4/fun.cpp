#include<iostream>
#define N 9
using namespace std;
const int a[N] = { 1,2,3,4,5,6,7,8,9 };
void dispsolution(char op[])//���
{
	cout << a[0];
	for (int i = 1; i < 9; i++)
	{	
		if (op[i] != ' ')
		{
			cout << op[i];
		}
		cout << a[i];
	}
	cout << "=100" << endl;
}
void fun(int i, char op[], int sum, int num)
{
	if (i == N)
	{
		if(sum==100)
		{
			dispsolution(op);
		}
		//return;
	}
	else//�ӵڶ���Ԫ�ؿ�ʼ
	{
		//����'+'
		op[i] = '+';
		sum += a[i];//sum����a[i]Ԫ��
		fun(i + 1, op, sum, a[i]);
		sum -= a[i];//����
		//����'-'
		op[i] = '-';
		sum -= a[i];//sum��ȥa[i]Ԫ��
		fun(i + 1, op, sum, -a[i]);
		sum += a[i];//����
		//����' '
		op[i] = ' ';
		sum -= num;//�������ո�����Ҫ����һ�θ�sum���ϻ��߼�ȥ��num��ȥ��
		int temp;
		if (num > 0)
		{
			temp = num * 10 + a[i];
		}
		else
		{
			temp = num * 10 - a[i];
		}
		sum += temp; 
		fun(i + 1, op, sum, temp);
		sum -= temp;//����
		sum += num;//��֮ǰɾȥ��num������
	}
}
int main()
{
	char op[N];
	cout << "�������" << endl;
	fun(1, op, a[0], a[0]);
}