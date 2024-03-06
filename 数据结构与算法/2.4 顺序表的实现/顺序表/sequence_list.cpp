#include<iostream>
#define True 1
#define False 0
#define Ok 1
#define Infeasible -2
#define Overflow -1
#define Error 0
#define MaxLength 100
using namespace std;
// 数据元素的类型
class ElemType
{
public:
	char elem;
};
// 顺序表
class Sqlist
{
public:
	ElemType* elem; // 一个数值，指向数组的首地址
	int len;  // 顺序表的长度
	// 初始化顺序表
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
	// 赋值
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
	// 销毁顺序表
	void DestroyList(void)
	{
		if (elem)
		{
			delete elem;
		}
	}
	// 清空线性表
	void ClearList(void)
	{
		len = 0;
	}
	// 获取第i个元素
	int Getnum(int i, ElemType& e)
	{
		if (i<1 || i > len)
		{
			return Error;
		}
		e = elem[i - 1];
		return Ok;
	}
	// 顺序查找,e为要查找的元素，对Elem从头到尾顺序查找
	int LocateElem(ElemType e)
	{
		int i;
		for ( i = 0; i < len; i++)
		{
			if (elem[i].elem == e.elem)
				return i+1; // 查找成功返回序号
		}
		return False; // 查找失败返回0
	}
	// 插入：在第i个位置插入e
	int ListInsert(int i, ElemType& e)
	{
		if (len == MaxLength) // 循序表已满
		{
			return Error;
		}
		if (i<1 || i>len + 1) // 插入位置不在顺序表中
		{
			return Error;
		}
		if (i == 1)  // 插入表头
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
		else if (i == len+1) // 插入最后一个位置
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
	// 删除第i个元素,并返回给e
	int ListDelete(int i, ElemType& e)
	{
		if (i<1 || i>len) // 删除位置不在顺序表中
		{
			return Error;
		}
		if (i == len) // 位置在表尾
		{
			e = elem[i - 1];
			len--;
			return Ok;
		}
		else // 位置在表头
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
	// 初始化
	l.InitList();
	// 设置初值
	l.setElem(e, 2);
	// 初始化后的顺序表
	printList(l);
	// 获取第i个元素
	ElemType m;
	l.Getnum(1, m);
	cout << "第一个元素是：" << m.elem << endl;
	// 查找元素e的位置
	ElemType n;
	n.elem = 'a';
	int i = l.LocateElem(n);
	if (i != 0)
	{
		cout << "a元素的位置为" << i << endl;
	}
	else
	{
		cout << "顺序表中无此元素" << endl;
	}
	// 在第i个位置插入元素e
	if (l.ListInsert(2, n))
	{
		printList(l);
	}
	// 删除第i个位置元素，返回给e
	ElemType k;
	if (l.ListDelete(1, k))
	{
		printList(l);
		cout << "删除的元素是" << k.elem << endl;
	}
	l.DestroyList();
	l.ClearList();
	return 0;
}