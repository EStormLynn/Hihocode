#include"iostream"
#include"algorithm"
#include"cstring"
#define MAX 200001
using namespace std;


struct point
{
	int x;
	int state;
};

point nn[MAX];

bool cmp(point p1, point p2)
{
	return p1.x < p2.x;
}

int main()
{
	int n, m;
	int start, len=0;
	int A = 0, B = 0;
	cin >> n >> m;

	for (int i = 0; i < 2 * n; i += 2)
	{
		cin >> nn[i].x;
		nn[i].state = 0;
		cin >> nn[i + 1].x;
		nn[i + 1].state = 1;
	}

	for (int i = 2*n; i < 2 * (n+m); i += 2)
	{
		cin >> nn[i].x;
		nn[i].state = 2;
		cin >> nn[i + 1].x;
		nn[i + 1].state = 3;
	}

	n = 2 * (n + m);
	sort(nn, nn + n, cmp);

	for (int i = 0; i<n; i++)
	{
		switch (nn[i].state)
		{
		case 0:
			if (!B && !A)
				start = nn[i].x;
			A++;
			break;
		case 1:
			A--;
			if (!B && !A)
				len += nn[i].x - start;
			break;
		case 2:
			if (A && !B)
				len += nn[i].x - start;
			B++;
			break;
		case 3:
			B--;
			if (A && !B)
				start = nn[i].x;
			break;
		}
	}

	cout << len;
	system("pause");

	return 0;
}