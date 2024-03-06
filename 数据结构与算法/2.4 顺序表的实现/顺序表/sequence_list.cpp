#include<iostream>
#define True 1
#define False 0
#define Ok 1
#define Infeasible -2
#define Overflow -1
#define Error 0
#define MaxLength 100
using namespace std;
// ����Ԫ�ص�����
class ElemType
{
public:
	char elem;
};
// ˳���
class Sqlist
{
public:
	ElemType* elem; // һ����ֵ��ָ��������׵�ַ
	int len;  // ˳���ĳ���
	// ��ʼ��˳���
	int InitList(void)
	{
		elem = new ElemType[MaxLength];
		if (!elem)
		{
			exit(Overflow);
		}
		len = 0;
		return Ok;
	}
	// ��ֵ
	int setElem(ElemType e[], int l)
	{
		int i;
		for (i = 0; i < l; i++)
		{
			elem[i + len] = e[i];
		}
		len = len + l;
		return Ok;
	}
	// ����˳���
	void DestroyList(void)
	{
		if (elem)
		{
			delete elem;
		}
	}
	// ������Ա�
	void ClearList(void)
	{
		len = 0;
	}
	// ��ȡ��i��Ԫ��
	int Getnum(int i, ElemType& e)
	{
		if (i<1 || i > len)
		{
			return Error;
		}
		e = elem[i - 1];
		return Ok;
	}
	// ˳�����,eΪҪ���ҵ�Ԫ�أ���Elem��ͷ��β˳�����
	int LocateElem(ElemType e)
	{
		int i;
		for ( i = 0; i < len; i++)
		{
			if (elem[i].elem == e.elem)
				return i+1; // ���ҳɹ��������
		}
		return False; // ����ʧ�ܷ���0
	}
	// ���룺�ڵ�i��λ�ò���e
	int ListInsert(int i, ElemType& e)
	{
		if (len == MaxLength) // ѭ�������
		{
			return Error;
		}
		if (i<1 || i>len + 1) // ����λ�ò���˳�����
		{
			return Error;
		}
		if (i == 1)  // �����ͷ
		{
			int j = len;
			while (j > 0)
			{
				elem[j] = elem[j - 1];
				j--;
			}
			elem[i -1] = e;
			len++;
			return Ok;
		}
		else if (i == len+1) // �������һ��λ��
		{
			elem[i - 1] = e;
			len++;
			return Ok;
		}
		else
		{
			int j=len;
			while (j > i - 1)
			{
				elem[j] = elem[j - 1];
				j--;
			}
			elem[i - 1] = e;
			len++;
			return Ok;
		}
	}
	// ɾ����i��Ԫ��,�����ظ�e
	int ListDelete(int i, ElemType& e)
	{
		if (i<1 || i>len) // ɾ��λ�ò���˳�����
		{
			return Error;
		}
		if (i == len) // λ���ڱ�β
		{
			e = elem[i - 1];
			len--;
			return Ok;
		}
		else // λ���ڱ�ͷ
		{
			int j = i - 1;
			e = elem[j];
			while (j < len-1)
			{
				elem[j] = elem[j + 1];
				j++;
			}
			len--;
			return Ok;
		}
	}

};
void printList(Sqlist& l)
{
	for (int j = 0; j < l.len; j++)
	{
		cout << l.elem[j].elem << " ";
	}
	cout << endl;
}
int main()
{
	Sqlist l;
	ElemType e[2] = { 'a', 'b' };
	// ��ʼ��
	l.InitList();
	// ���ó�ֵ
	l.setElem(e, 2);
	// ��ʼ�����˳���
	printList(l);
	// ��ȡ��i��Ԫ��
	ElemType m;
	l.Getnum(1, m);
	cout << "��һ��Ԫ���ǣ�" << m.elem << endl;
	// ����Ԫ��e��λ��
	ElemType n;
	n.elem = 'a';
	int i = l.LocateElem(n);
	if (i != 0)
	{
		cout << "aԪ�ص�λ��Ϊ" << i << endl;
	}
	else
	{
		cout << "˳������޴�Ԫ��" << endl;
	}
	// �ڵ�i��λ�ò���Ԫ��e
	if (l.ListInsert(2, n))
	{
		printList(l);
	}
	// ɾ����i��λ��Ԫ�أ����ظ�e
	ElemType k;
	if (l.ListDelete(1, k))
	{
		printList(l);
		cout << "ɾ����Ԫ����" << k.elem << endl;
	}
	l.DestroyList();
	l.ClearList();
	return 0;
}