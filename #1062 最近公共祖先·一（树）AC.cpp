#include "iostream"
#include "string"
#include "map"

using namespace std;

map<string, string> fa;
map<string, int> vis;

void Find(string a, string b)
{
	vis.clear();
	string x = a;
	while (!x.empty())
	{
		vis[x] = 1;
		x = fa[x];
	}

	x = b;
	while (!x.empty() && !vis[x])
	{
		x = fa[x];
	}

	if (!x.empty())
		cout << x << endl;
	else
		cout << "-1" << endl;
}

int main()
{
	int n,m;
	string a, b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		fa[b] = a;		
	}

	cin >> m;
	while (m--)
	{
		cin >> a >> b;
		Find(a, b);
	}
}
