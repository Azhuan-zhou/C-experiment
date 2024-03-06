#include"head.h"
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