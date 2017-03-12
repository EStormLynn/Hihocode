//
// Created by SeeKHit on 2017/3/5.
//

#include "iostream"
#include "vector"
#include "algorithm"
#define MAX 505
using namespace std;

char a[MAX][MAX];
int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};
int n,m;
int n1=0;   //记录多少个块

vector<pair<int,int>> vv[500*505];//记录图形点的数组

void dfs(int i,int j,int id)
{
    a[i][j]='x';
    vv[id].push_back(make_pair(i-1,j-1));
    int ar=1;
    for(int ii=0;ii<4;ii++)
    {
        int ni=di[ii]+i,nj=dj[ii]+j;
        if(a[ni][nj]=='1')
            dfs(ni,nj,id);
    }
}

int vvv[500][505];  //记录字块
void Print(int id)
{
    int cow=0,rol=0;
    int maxx=0,minx=1e9,maxy=0,miny=1e9;
    for(int t=0;t<vv[id].size();t++)
    {
        maxx=max(maxx,vv[id][t].first);
        minx=min(minx,vv[id][t].first);
        maxy=max(maxy,vv[id][t].second);
        miny=min(miny,vv[id][t].second);

        int x=vv[id][t].first;
        int y=vv[id][t].second;

    }
    rol=maxy-miny+1;
    cow=maxx-minx+1;
    cout<<cow<<" "<<rol<<endl;

    for(int t=0;t<vv[id].size();t++)
    {
        int x=vv[id][t].first;
        int y=vv[id][t].second;

        vvv[x-minx][y-miny]=1;

    }

    for(int i=0;i<cow;i++)
    {
        for(int j=0;j<rol;j++)
        {
            cout<<vvv[i][j];
            vvv[i][j]=0;

        }
        cout<<endl;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",a[i+1]+1);


    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]=='1')
            {
                n1++;
                dfs(i,j,n1);
            }
        }

    for(int i=1;i<=n1;i++)
    {
        Print(i);
    }
}
