#include "iostream"
#define MAX 1000

using namespace std; 

int main()
{
	int n;
	int a[MAX];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int flag = 0;
	for (int i = n - 1; i > 0; i--)
	{
		if (a[i - 1] > a[i])
		{
			flag = i - 1;
			break;
		}			
	}

	for (int i = 0; i <= flag; i++)
		cout << a[i] << " ";

	return 0;

}