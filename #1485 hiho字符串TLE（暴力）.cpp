#include "iostream"
#include "string"
#include "deque"
#include "map"
using namespace std;

string str;
deque<char> deq;
map<char,int> ma;
int ans=100005;

int main()
{
    while(cin>>str)
    {
        ma['h']=0;
        ma['i']=0;
        ma['o']=0;

        ans=100005;
        int l=str.length();


        if(l<4)
        {
            cout<<-1<<endl;
            continue;
        }

        for(int i=0;i<l-4+1;i++)
        {
            ma['h']=0;
            ma['i']=0;
            ma['o']=0;
            for(int j=i;j<l;j++)
            {
                if(str[j]=='h'||str[j]=='i'||str[j]=='o')
                    ma[str[j]]++;

                if(ma['h']==2 && ma['i']==1 && ma['o']==1)
                    ans=min(ans,j-i+1);
            }

        }

        if(ans!=100005)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;


    }
}