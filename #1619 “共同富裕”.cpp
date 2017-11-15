#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

typedef long long LL;

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        LL ans=0;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++)
        {
            ans+=v[i]-v[0];
        }
        cout<<ans<<endl;
    }
}
