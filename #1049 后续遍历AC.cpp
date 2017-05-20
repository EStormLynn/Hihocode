#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

void post_order(const char *pre, const char *in, int len)
{
	if (len<1)return;
	int i = 0;
	while (in[i] != pre[0])
		i++;
	post_order(pre + 1, in, i);
	post_order(pre + i + 1, in + i + 1, len - i - 1);
	cout << pre[0];
}
int main()
{
	string pre, in;
	cin >> pre >> in;
	post_order(pre.c_str(), in.c_str(), in.size());//c_str()º¯Êý·µ»Ø¾²Ì¬Ö¸Õë 
}