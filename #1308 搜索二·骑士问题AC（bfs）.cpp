#include "iostream"
#include "string.h"
#include "queue"

using namespace std;

typedef pair<int, int> pii;
char ss[3];
int vis[3][8][8];
int d[8][2] = { { -2,1 },{ -2,-1 },{ -1,-2 },{ -1,2 },{ 2,-1 },{ 2,1 },{ 1,-2 },{ 1,2 } };
int step = 0;

pii pos; //ÂíÎ»ÖÃ

bool in(pii p)
{
	if (p.first < 0 || p.second < 0 || p.first>7 || p.second>7)
		return false;
	else
		return true;
}

void bfs(int vi[8][8])
{
	step = 0;
	queue<pii> q;
	memset(vi, -1, 256);
	q.push(pos);
	vi[pos.first][pos.second] = 0;

	while (!q.empty())
	{
		pii pfront = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			pii temp;
			temp.first = pfront.first + d[i][0];
			temp.second = pfront.second + d[i][1];
			if (in(temp) && vi[temp.first][temp.second] == -1)
			{
				vi[temp.first][temp.second] = vi[pfront.first][pfront.second] + 1;
				q.push(temp);
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%s", ss);
		pos = make_pair(ss[0] - 'A', ss[1] - '1');
		bfs(vis[0]);

		scanf("%s", ss);
		pos = make_pair(ss[0] - 'A', ss[1] - '1');
		bfs(vis[1]);

		scanf("%s", ss);
		pos = make_pair(ss[0] - 'A', ss[1] - '1');
		bfs(vis[2]);

		int ans = 1e9;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int temp = 0;
				for (int k = 0; k < 3; k++)
				{
					temp += vis[k][i][j];
				}
				if (temp < ans)
					ans = temp;				
			}			
		}
		cout << ans << endl;		
	}
}