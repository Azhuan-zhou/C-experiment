#include"head.h"
void knap(int w[],int v[],int W, vector<vector<int>>& ps)
{
	int sumw=0, sumv=0;
	int maxsumv=0,maxsumw=0;
	int maxp=0;
	int count = 0;
	vector<vector<int>>::iterator it1;//ָ�򷽰��ĵ�����
	vector<int>::iterator it2;//ָ����Ʒ�ĵ�����
	cout << setw(12) << "���" << setw(12) << "ѡ����Ʒ" << setw(12) << "������" << setw(12) << "�ܼ�ֵ" << setw(12) << "�ܷ�װ��"<<endl;
	for (it1 = ps.begin(); it1 != ps.end(); ++it1)
	{
		cout << setw(12) << count+1;//��ӡ���������
		cout << "{";
		for (it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)//����
		{
			cout << *it2 << " ";//��ӡ��ѡ�����Ʒ
			sumw += w[*it2 - 1];//����÷����µ������ܺ�
			sumv += v[*it2 - 1];//����÷����µļ�ֵ�ܺ�
		}
		cout << "}";
		cout << setw(12) << sumw << setw(12) << sumv;//��ӡ�����µ������ܺͺͼ�ֵ�ܺ�
		if (sumw <= W)//�ж��������Ƿ���������
		{
			cout << setw(12) << "��";
			if (maxsumv > sumv)//�ҳ�������������������ֵ�ķ���
			{
				maxsumv = sumv;
				maxsumw = sumw;
				maxp = count;//����ֵ���������
			}
		}
		else
		{
			cout<<setw(12) << "��";
		}
		cout << endl;
		count++;
	}
	cout << "��ѷ���Ϊ��ѡ����Ʒ";
	cout << "{";
	for (it2 = ps[maxp].begin(); it2 != ps[maxp].end(); ++it2)
	{
		cout << *it2 << " ";
	}
	cout << "}," << "��������" << maxsumw << "�ܼ�ֵ��" << maxsumv;
}