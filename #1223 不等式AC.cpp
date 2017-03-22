#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define C 100; 

#define MAXN 55
string s, op[MAXN];
int n;
double num[MAXN];
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> s >> op[i] >> num[i];
		}
		int maxn = 1;
		for (double x = 0; x <= 1000; x+=0.5)            //A>5 A<6Âú×ã£¬ËùÒÔ+0.5
		{
			int tem = 0;
			for (int k = 0; k < n; k++)
			{
				if (op[k] == "=" && x == num[k])tem++;
				else if (op[k] == "<=" && x <= num[k])tem++;
				else if (op[k] == ">=" && x >= num[k])tem++;
				else if (op[k] == "<" && x < num[k])tem++;
				else if (op[k] == ">" && x > num[k])tem++;
			}
			maxn = max(maxn, tem);
		}
		cout << maxn << endl;
	}
	system("pause");
	return 0;
}