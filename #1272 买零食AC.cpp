#include "iostream"
#define N 51

using namespace std; 

int max(int a, int b)
{
	return a > b ? a: b;
}

int main()
{
	int q;
	double tag;
	cin >> q;
	while (q--)
	{
		int n;
		double aa[N];
		int a[N],b[N];

		cin >> n;
		for (int i = 0; i < n;i++)
		{
			cin >> aa[i] >> b[i];
			a[i] = 10 * aa[i];
		}

		int ans = 0; 

		for (int i = 0; i < n; i++)
		{
			if (a[i] % 50 == 0)
				ans = max(ans, b[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				if ((a[i] + a[j]) % 50 == 0)
					ans = max(ans, b[i] + b[j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				for (int k = j+1; k < n; k++)
				{
					if ((a[i] + a[j] + a[k]) % 50 == 0)
						ans = max(ans, b[i] + b[j] + b[k]);
				}
			}
		}
		cout << ans << endl;
	}
}