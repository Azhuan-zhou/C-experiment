#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i=0, j=0,p;
	string s = "aababcde";
	string t = "abcd";
	while(i<s.length()&&j<t.length())
	{
		if (s[i] == t[j])
		{
			++j;
			++i;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		if (j == t.length())
		{
			break;
		}
	}
	p = i - j;
	cout << "�ڵ�" << p+1 << "��λ��ʱ�ɹ�ƥ��"<<endl;
}