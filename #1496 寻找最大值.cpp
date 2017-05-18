#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

typedef long long LL;
LL vec[100000];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			vec[i] = 0;
			LL temp;
			cin >> temp;
			vec[i] = temp;
		}

		LL ans = 0;

		sort(vec, vec+n);

		ans = vec[n - 2] * vec[n - 1] * (vec[n - 2] & vec[n - 1]);
		for (int i = n-1; i >= 2; i--)
		{
			ans = max(ans, vec[i - 1] * vec[i] * (vec[i - 1] & vec[i]));
		}


		cout << ans << endl;

	}

}