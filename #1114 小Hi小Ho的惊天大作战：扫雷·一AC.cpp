#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 100005
using namespace std;

int n, a[MAX],up[MAX],ans[MAX];

void dfs(int pos)
{
	if (pos == n+1)
	{
		for (int i = 1; i <= n; i++)
		{
			if(ans[i]==-1)	ans[i] = up[i];
			else if (ans[i] != up[i]) ans[i] = 2;      //存在几种可能的情况下，如果不都是0，或不都是1，至为2.
		}
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		up[pos] = i;
		if (up[pos] + up[pos - 1]>a[pos])
			continue;

		if (pos > 1 && up[pos] + up[pos - 1] + up[pos - 2] != a[pos - 1])
			continue;
			
		if (pos == n && up[pos] + up[pos - 1] != a[pos])
			continue;

		dfs(pos + 1);
	}
}

int main()
{
	int task;
	cin >> task;
	while (task--)
	{
		int x=0, o=0;

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		memset(ans, -1, sizeof(ans));
		dfs(1);

		for (int i = 1; i <= n; i++)
		{
			if (ans[i] == 0)
				o++;
			else if (ans[i] == 1)
				x++;
		}

		cout << x;
		for (int i = 1; i <= n; i++){
			if (ans[i] == 1)
				cout << " " << i;
		}
		cout << endl;
		cout << o;
		for (int i = 1; i <= n; i++){
			if (ans[i] == 0)
				cout << " " << i;
		}
		cout << endl;
	}
	system("pause");
}