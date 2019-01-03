#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, ans = 0;
	while (cin>>n>>m)
	{
		ans = 0;
		for(int y = n;y<=m;y++)
		{
			string s1 = to_string(y);

			reverse(s1.begin(), s1.end());
			int x = stoi(s1);
			if (x - y >= 1000)
				ans += 1;
		}
		cout << ans << endl;
	}
}