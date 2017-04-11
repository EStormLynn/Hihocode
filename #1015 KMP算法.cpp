#include <cstring>
#include <iostream>
using namespace std;
int kmpnext[10005];
char text[1000005];
char pat[10005];
int n, m;
void getnext()
{
	int i = 0, j = -1;
	kmpnext[0] = -1;
	while (i<m)
	{
		if (j == -1 || pat[i] == pat[j])
		{
			i++, j++;
			kmpnext[i] = j;
		}
		else j = kmpnext[j];
	}

}
int kmp()
{
	int i = 0, j = 0, ans = 0;
	getnext();
	while (i<n)
	{
		if (j == -1 || text[i] == pat[j])
		{
			i++, j++;
			if (j == m) ans++;
		}
		else j = kmpnext[j];
	}
	return ans;
}
int main()
{
	int c, i;
	scanf("%d", &c);
	while (c--)
	{
		cin >> pat >> text;
		m = strlen(pat);
		n = strlen(text);
		printf("%d\n", kmp());

	}

	return 0;
}
