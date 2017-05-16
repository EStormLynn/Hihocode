#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

vector<int> veNum;
map<int, int> vec;
int ans = -1;

int main()
{
	int n;
	while (cin >> n)
	{
		vec.clear();

		int nn = n;
		while (nn--)
		{
			veNum.clear();
			int t = 0;
			cin >> t;
			int width;
			while (t--)
			{
				cin >> width;
				veNum.push_back(width);
			}
			width = 0;

			for (int i = 0; i < veNum.size()-1; i++)
			{
				width += veNum[i];
				vec[width]++;
			}
		}

		for (auto iter = vec.begin(); iter != vec.end(); iter++)
		{
			ans = max(ans, iter->second);
		}
		if (ans == -1)
			cout << n << endl;
		else
		cout << n - ans << endl;

	}
}