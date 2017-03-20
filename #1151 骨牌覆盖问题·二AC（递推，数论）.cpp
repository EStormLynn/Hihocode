#include <iostream>
#include <algorithm>
#define mod 12357
using namespace std;

//5324124312
int solve(long long n)
{
	n = n / 2;
	int a[3],t=0;
	a[0] = 1;
	a[1] = 3;
	a[2] = 11;

	if (n < 3)
		return a[n];

	for (int i = 3; i <= n; i++)
	{
		t = (3*a[2] + 3*a[1]-a[0]+mod)%mod;
		a[0] = a[1];
		a[1] = a[2];
		a[2] = t;
	}
	return t;
}

int main()
{
	long long n;
	while (cin >> n) {
		if (n & 1)
			cout << 0 << endl;
		else
			cout << solve(n) << endl;
	}


	system("pause");
	return 0;
}
