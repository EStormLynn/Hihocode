/*
 * 宽度优先搜索
 * 从1开始进行拓展
 * 由于边的长度均为1，第一次拓展到时即为最短路
 * 最短路径长度_min__𝑖__
 * 如果存在𝑖→1，使用_min__𝑖__+1更新答案
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;

vector<int> V[100005];
int vis[100005];

int bfs(int star)
{
    int v=star;
    queue<int> que;
    que.push(v);
    while(!que.empty())
    {
        int top=que.front();
        que.pop();

        for(int i=0;i<V[top].size();i++)
        {
            if(!vis[V[top][i]])
            {
                que.push(V[top][i]);
                vis[V[top][i]]=vis[top]+1;
            }

            if(V[top][i]==1)
                return vis[1];
        }

    }

    return -1;
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int x,y;
        for(int i=0;i<m;i++) {
            cin >> x >> y;
            V[x].push_back(y);
        }

        cout<<bfs(1)<<endl;
    }
}


