#include"iostream"
#include"algorithm"

#define MAX 201
using namespace std;

int a[MAX][MAX] = {0};
int n;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
			a[n][j] = max(a[n][j], a[n][j + 1]) + a[i][j];
	}
	printf("%d", a[n][0]);
	system("pause");	
}