#include"iostream"
#include"algorithm"
#define MAX 101
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m, day,ans=0;
		int a[MAX] = {0};

		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}

		for (int i = 0; i+m+1 <= n; i++)
		{
			day = a[i + m+1] - a[i];
			if (day>ans)
				ans = day;
		}
		ans = ans - 1;
		
		if (m >= n)
			ans = 100;
		printf("%d\n", ans);		
	}
	
	system("pause");	
}