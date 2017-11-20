#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

typedef long long LL;

using namespace std;

int main()
{
    int m,n,x,p,q;

    while(cin>>m>>n>>x)
    {
        p=m,q=0;
        int eated=0;
        vector<int> v(n),b(n);

        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            b[i]=0;
        }

        sort(v.begin(),v.end());

        for(int time=1;time<=x;time++)
        {
            for(int i=0;i<n;i++)
            {
                if(b[i]==0)
                    p--;
                if(time%v[i]==0)
                {
                    b[i]=0;
                    eated++;
                }else
                    b[i]=1;
                if(p==0)
                    break;

            }
            if(p==0)
                break;
        }

        for(int i=0;i<n;i++)
            if(b[i]==1)
                q++;


        cout<<p<<" "<<q<<endl;
    }
}
