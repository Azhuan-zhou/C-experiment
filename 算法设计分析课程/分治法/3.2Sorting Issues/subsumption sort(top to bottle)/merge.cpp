#include"head.h"
void merge(int a[], int low, int mid, int high)
{
	int i = low;//�β���������ߵ��±�
	int j = mid+1;//�β������м���±�
	int k, l;
	int t = 0;//��ʱ������±�
	vector<int> p(high - low + 1);
	//��������Ϊ��high-low+1����һά��ʱ����
	while (i <= mid && j <= high)//�����ֿ������a[i],a[j],��Ԫ�����ν��������Ƚϣ�С�ķ�����ʱ����p��
	{
		if (a[i] <= a[j])
		{
			p[t] = a[i];
			i++;
			t++;
		}
		else
		{
			p[t] = a[j];
			j++;
			t++;
		}
	}
	while (i <=  mid)//�������a[i]ʣ��һ��Ԫ��,�������ʱ������
	{
		p[t] = a[i];
		i++;
		t++;
	}
	while (j <= high)//�������a[j]ʣ��һ��Ԫ��,�������ʱ������
	{
		p[t] = a[j];
		j++;
		t++;
	}
	for (k = low, l = 0; k <= high ; k++, l++)//���ź�����������a�ĵ�low��Ԫ�ص���high��Ԫ��
	{
		a[k] = p [l];
	}
	cout << "ִ����merge" << endl;
	print(a, 10);
	cout << endl;
}