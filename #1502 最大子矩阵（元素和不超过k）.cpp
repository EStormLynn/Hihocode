#include <iostream>
#include <algorithm>
using namespace std;

int dp[255][255], a[255][255];
int ans=-1;
int n,m,K;
typedef long long LL;

int main()
{

    cin >> n>>m>>K;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0]=0;
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            dp[i][j]=dp[i][j-1]+a[i][j];
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            LL aa=0;
            for(int k=1,l=1;k<=n;++k){
                aa+=dp[k][j]-dp[k][i-1];
                while(aa>K){
                    aa-=dp[l][j]-dp[l][i-1];
                    ++l;
                }
                ans=max(ans,(j-i+1)*(k-l+1));
            }
        }
    }

    cout << ans;
}