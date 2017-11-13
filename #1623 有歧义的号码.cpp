#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<n;i++)
        {
            string s1=to_string(i),s2=s1;
            bool flag=true;
            for(auto &t:s1)
            {
                if(t=='3'||t=='4'||t=='7')
                {
                    flag=false;
                    break;
                }else if(t=='6')    t='9';
                else if(t=='9')     t='6';
            }

            if(flag)
            {
                reverse(s1.begin(),s1.end());
                if(s1[0]=='0' || s1==s2 || stoi(s1)>n)
                    continue;
                cout<<s2<<endl;
            }
        }
    }
}