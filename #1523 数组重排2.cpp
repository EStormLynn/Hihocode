#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

int v[100005];

int main()
{
    int n;
    while(cin>>n)
    {
        int ans=n;
        for(int i=1;i<=n;i++)
            cin>>v[i];

        for(int i=n;i>0;i--)
        {
            if(v[i]==ans)
                ans--;
        }
        cout<<ans<<endl;
    }
}