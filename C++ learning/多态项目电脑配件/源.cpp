#include<iostream>
#include<string>
using namespace std;
class CPU
{
public:
	CPU()
	{
		cout << "CPU构造函数运行" << endl;
	}
	~CPU()
	{
		cout << "CPU析构函数运行" << endl;
	}
	virtual void calculate() = 0;
};
class VideoCard
{
public:
	VideoCard()
	{
		cout << "VideoCard构造函数运行" << endl;
	}
	~VideoCard()
	{
		cout << "VideoCard析构函数运行" << endl;
	}
	virtual void display() = 0;
};
class Memory
{
public:
	Memory()
	{
		cout << "Memory构造函数运行" << endl;
	}
	~Memory()
	{
		cout << "Memory析构函数运行" << endl;
	}
	virtual void storage() = 0;
};
class InterCPU :public CPU
{
public:
	InterCPU()
	{
		cout << "InterCPU构造函数运行" << endl;
	}
	~InterCPU()
	{
		cout << "InterCPU析构函数运行" << endl;
	}
	void calculate()
	{
		cout << "英特尔的CPU开始计算了" << endl;
	}
};
class InterVideoCard :public VideoCard
{
public:
	InterVideoCard()
	{
		cout << "InterVideoCard构造函数运行" << endl;
	}
	~InterVideoCard()
	{
		cout << "InterVideoCard析构函数运行" << endl;
	}
	void display()
	{
		cout << "英特尔的显卡开始显示了" << endl;
	}
};
class InterMemory :public Memory
{
public:
	InterMemory()
	{
		cout << "InterVideoCard构造函数运行" << endl;
	}
	~InterMemory()
	{
		cout << "InterVideoCard析构函数运行" << endl;
	}
	void storage()
	{
		cout << "英特尔的内存开始储存了" << endl;
	}
};
class LegionCPU :public CPU
{
public:
	void calculate()
	{
		cout << "联想的CPU开始计算了" << endl;
	}
};
class LegionVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "联想的显卡开始显示了" << endl;
	}
};
class LegionMemory :public Memory
{
public:
	void storage()
	{
		cout << "联想的内存开始储存了" << endl;
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
		cout << "computer构造函数运行" << endl;
	}
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer()
	{
		cout << "computer析构函数运行" << endl;
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
	cout << "第一台电脑组装" << endl;
	test01();
	cout << "------------------------------------"<<endl;
	cout << "第二台电脑组装" << endl;
	test02();
	cout << "------------------------------------" << endl;
	system("pause");
}