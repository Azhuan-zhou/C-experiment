#include<string>
#include<iostream>
using namespace std;
int main()
{
	string v = "ababababcabaytiyabbaab";
	string t = "aba";
	int i=0, j=0;
	int sum=0;
	while (i < v.length() && j < t.length())
	{
		if (v[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0; 
		}
		if (j == t.length())
		{
			sum++;
			j = 0;
		}
	}
	cout<<"一共有"<<sum<<"个字符串相同"<<endl;
}