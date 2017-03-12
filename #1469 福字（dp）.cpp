#include "iostream"
#include "algorithm"
using namespace std;

int dp[1001][1001], a[1001][1001];
int ans;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ((a[i][j] == a[i - 1][j] + 1) && (a[i][j] == a[i][j - 1] + 1) && (a[i][j] == a[i - 1][j - 1] + 2))
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			else
				dp[i][j] = 1;

			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;
}