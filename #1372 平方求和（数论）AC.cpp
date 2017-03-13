#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//5324124312
bool is_sqrt(long long n)
{
	int m = sqrt(n);
	if (m*m == n)
		return true;
	else
		return false;
}

int solve(long long n)
{
	if (is_sqrt(n))
		return 1;
	while (n % 4 == 0)
		n /= 4;

	if (n % 8 == 7)
		return 4;

	for (int i = 0; i*i < n; i++)
	{
		if (is_sqrt(n - i*i))
			return 2;
	}
	return 3;
}

int main()
{
	long long n;
	while (cin>>n)
	{
		if (n == -1)
			break;
		cout<< solve(n)<<endl;

	}
	system("pause");
	return 0;
}
