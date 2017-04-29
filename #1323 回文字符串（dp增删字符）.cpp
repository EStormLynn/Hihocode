#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 101;
string s;
bool vis[maxn][maxn];
int dp[maxn][maxn];

int dfs(int i, int j)
{
	if (i >= j)
		return 0;
	if (vis[i][j])
		return dp[i][j];
	if (s[i] == s[j])
		dp[i][j] = dfs(i + 1, j - 1);
	else
		dp[i][j] = min(dfs(i + 1, j - 1), min(dfs(i, j - 1), dfs(i + 1, j))) + 1;
	vis[i][j] = 1;
	return dp[i][j];
}
int main()
{
	while (cin >> s)
	{
		memset(vis, 0, sizeof vis);
		memset(dp, 0x3f, sizeof dp);
		cout << dfs(0, s.length() - 1) << endl;
	}
	system("pause");
	return 0;
}
