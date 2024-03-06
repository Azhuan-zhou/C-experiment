#include<iostream>
#include<iomanip>
#define MAX 1025
using namespace std;
void chessboard(int tr, int tc, int dr, int dc, int size);
int title=1;
int board[MAX][MAX];
void chessboard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)
	{
		return;
	}
		int t=title++;//��������
		int s = size / 2;//�ָ����̺������������
		//���Ͻ�����
		if (dr < tr + s && dc < tc + s)
		{
			chessboard(tr, tc, dr, dc, s);
		}
		else
		{
			board[tr + s - 1][tc + s - 1] = t;//����tr + s - 1��tr + s - 1�У����½ǣ���Ϊ��������
			chessboard(tr, tc, tr + s - 1, tc + s - 1, s);
		}
		//���Ͻ�����
		if (dr<tr + s  && dc>=tc + s )
		{
			chessboard(tr, tc + s, dr, dc, s);
		}
		else
		{
			board[tr+s-1][tc + s] = t;//�����½���Ϊ��������
			chessboard(tr, tc + s, tr + s - 1, tc + s, s);
		}
		//���½�����
		if (dr >= tr + s && dc < tc + s)
		{
			chessboard(tr + s, tc, dr, dc, s);
		}
		else
		{
			board[tr + s][tc + s - 1] = t;//�����Ͻ���Ϊ��������
			chessboard(tr + s, tc, tr + s, tc + s - 1, s);
		}
		//���½�����
		if (dr >= tr + s && dc >= tc + s)
		{
			chessboard(tr + s, tc + s, dr, dc, s);
		}
		else
		{
			board[tr + s][tc + s] = t;//�����Ͻ���Ϊ��������
			chessboard(tr + s, tc + s, tr + s, tc + s, s);
		}
}
int main()
{
	int k=3;
	int  x=1, y=2;
	int size = 1<<k;
	chessboard(0, 0, x, y, size);
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			cout << setw(4) << board[i][j];
		}
		cout << endl;
	}
}
