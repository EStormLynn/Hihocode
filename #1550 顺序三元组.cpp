#include<iostream>
#include<vector>
typedef long long LL;

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		LL t1 = 0, t2 = 0, t3 = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];

			if (v[i] == 1)
			{
				t1++;
			}
			else if (v[i] == 2)
			{
				t2 += t1;
			}
			else if (v[i] == 3)
			{
				t3 += t2;
			}
		}
		cout << t3 << endl;
	}
}