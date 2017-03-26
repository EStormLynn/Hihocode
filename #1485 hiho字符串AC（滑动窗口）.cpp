#include "iostream"
#include "string"
#include "string.h"
#include "vector"
#include "map"
#include "algorithm"

using namespace std;

char c[256];
int ans = 100005;

int main()
{
	string s;
	while (cin >> s)
	{
		memset(c, 0, sizeof(c));
		int l = s.length();
		for (int i = 0,j=0; i < l; i++)
		{
			while (j < l && (c['h'] < 2 || c['i'] < 1 || c['o'] < 1))
			{
				c[s[j]]++;
				j++;
				if (c['h'] > 2 || c['i'] > 1 || c['o'] > 1)
					break;
			}
			
			if (c['h'] == 2 && c['i'] == 1 && c['o'] == 1)
			{
				ans = min(ans, j - i);
			}
			c[s[i]]--;
		}
		if (ans == 100005)
			ans = -1;
		cout << ans << endl;
	}
}