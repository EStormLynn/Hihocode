#include"iostream"
#include"vector"
#include"map"
#define MAX 1000005
using namespace std;

int res;
int w, h, r_count;

struct Radar
{
	int x;
	int y;
	int r;
};

Radar rr[1005];
bool solve()
{
	for (int i = 0; i <= w; i++)
	{
		int height[MAX] = { 0 };
		for (int j = 0; j < r_count; j++)
		{
			if (rr[j].x == i)
			{
				int k = rr[j].y - rr[j].r;
				if (k< 0)
					k = 0;
				for (k; k < rr[j].y + rr[j].r; k++)
				{
					height[k] = 1;
				}
			}
		}

		int p = 0;
		bool pass=false;
			while ((p < h)&&(pass == false))
			{
				if (height[p] == 1)
					p++;
				else
					pass = true;				
			}

		if (pass == false)
			return false;
	}
	return true;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> w >> h >> r_count;

		for (int i = 0; i < r_count; i++)
		{
			cin >> rr[i].x >> rr[i].y >> rr[i].r;
		}

		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
}
