#include "iostream"
#include "algorithm"

using namespace std;

int N, V;
int c[505], v[505];
int dp[100005];

int main()
{
	while (cin >> N >> V)
	{
		for (int i = 0; i < N; i++)
		{
			cin >> c[i] >> v[i];
		}
		//逆序推能够保证 f[v-c[i]] 保存的是状态是 f[i-1][v-c[i]] ，也就是每个物品只被使用了一次；
		for (int i = 0; i < N; i++)
		{
			//顺序的话 f[v - c[i]] 保存的是 f[i][v - c[i]] ，每个物品有可能被使用多次，也就是完全背包问题的解法。
			for (int j = c[i]; j <=V; j++)
			{
				dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
			}
		}

		cout << dp[V] << endl;
	}
}
