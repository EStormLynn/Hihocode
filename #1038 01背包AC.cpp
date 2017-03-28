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

        for (int i = 0; i < N; i++)
        {
            for (int j = V; j >= c[i]; j--)
                dp[j] = max(dp[j],dp[j-c[i]]+v[i]);
        }

        cout << dp[V] << endl;
    }
}