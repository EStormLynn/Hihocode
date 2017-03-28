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
		//�������ܹ���֤ f[v-c[i]] �������״̬�� f[i-1][v-c[i]] ��Ҳ����ÿ����Ʒֻ��ʹ����һ�Σ�
		for (int i = 0; i < N; i++)
		{
			//˳��Ļ� f[v - c[i]] ������� f[i][v - c[i]] ��ÿ����Ʒ�п��ܱ�ʹ�ö�Σ�Ҳ������ȫ��������Ľⷨ��
			for (int j = c[i]; j <=V; j++)
			{
				dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
			}
		}

		cout << dp[V] << endl;
	}
}
