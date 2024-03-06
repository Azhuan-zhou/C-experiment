#include<iostream>
#include<string>
using namespace std;
class CPU
{
public:
	CPU()
	{
		cout << "CPU���캯������" << endl;
	}
	~CPU()
	{
		cout << "CPU������������" << endl;
	}
	virtual void calculate() = 0;
};
class VideoCard
{
public:
	VideoCard()
	{
		cout << "VideoCard���캯������" << endl;
	}
	~VideoCard()
	{
		cout << "VideoCard������������" << endl;
	}
	virtual void display() = 0;
};
class Memory
{
public:
	Memory()
	{
		cout << "Memory���캯������" << endl;
	}
	~Memory()
	{
		cout << "Memory������������" << endl;
	}
	virtual void storage() = 0;
};
class InterCPU :public CPU
{
public:
	InterCPU()
	{
		cout << "InterCPU���캯������" << endl;
	}
	~InterCPU()
	{
		cout << "InterCPU������������" << endl;
	}
	void calculate()
	{
		cout << "Ӣ�ض���CPU��ʼ������" << endl;
	}
};
class InterVideoCard :public VideoCard
{
public:
	InterVideoCard()
	{
		cout << "InterVideoCard���캯������" << endl;
	}
	~InterVideoCard()
	{
		cout << "InterVideoCard������������" << endl;
	}
	void display()
	{
		cout << "Ӣ�ض����Կ���ʼ��ʾ��" << endl;
	}
};
class InterMemory :public Memory
{
public:
	InterMemory()
	{
		cout << "InterVideoCard���캯������" << endl;
	}
	~InterMemory()
	{
		cout << "InterVideoCard������������" << endl;
	}
	void storage()
	{
		cout << "Ӣ�ض����ڴ濪ʼ������" << endl;
	}
};
class LegionCPU :public CPU
{
public:
	void calculate()
	{
		cout << "�����CPU��ʼ������" << endl;
	}
};
class LegionVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "������Կ���ʼ��ʾ��" << endl;
	}
};
class LegionMemory :public Memory
{
public:
	void storage()
	{
		cout << "������ڴ濪ʼ������" << endl;
	}
};
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
		cout << "computer���캯������" << endl;
	}
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer()
	{
		cout << "computer������������" << endl;
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};
void test01()
{
	CPU* intelcpu = new InterCPU;
	VideoCard* intelvc = new InterVideoCard;
	Memory* intelmem = new InterMemory;
	Computer *computer1=new Computer(intelcpu, intelvc, intelmem);
	computer1->work();
	delete computer1;
}
void test02()
{
	CPU* legioncpu = new LegionCPU;
	VideoCard* legionvc = new LegionVideoCard;
	Memory* legionmem = new LegionMemory;
	Computer *computer2=new Computer(legioncpu, legionvc, legionmem);
	computer2->work();
	delete computer2;
}
int main()
{
	cout << "��һ̨������װ" << endl;
	test01();
	cout << "------------------------------------"<<endl;
	cout << "�ڶ�̨������װ" << endl;
	test02();
	cout << "------------------------------------" << endl;
	system("pause");
}