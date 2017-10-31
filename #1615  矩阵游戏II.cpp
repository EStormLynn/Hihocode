#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	while (cin>>n)
	{
		vector<int> v(n);
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> temp;
				v[j] += temp;
			}
		}
		sort(v.begin(), v.end());

		vector<int>v1, v2;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] <= 0)
				v1.push_back(v[i]);
			else
			{
				v2.push_back(v[i]);
				ans += v[i];
			}
		}

		for (int i = 0; i < v1.size(); i++)
			ans -= v1[i];

		if (v1.size() % 2 == 1)	//奇数个负数，比较最大负数和最小正数
		{
			if (v2.size() != 0 && (-v1[v1.size() - 1] > v2[0]))
				ans -= 2 * v2[0];
			else
				ans += 2 * v1[v1.size() - 1];
		}			

		cout << ans << endl;
	}

}
