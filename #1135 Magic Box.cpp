#include"iostream"
#include"algorithm"
#include"cstring"
#include"math.h"
#define MAX 20000
using namespace std;

int main()
{
	int cr, cy, cb, p, q, r, xyz[3], m[3];
	char str[MAX];
	
	cr = cy = cb = p = q = r = 0;
	for (int i = 0; i < 3; i++)
		scanf("%d", &xyz[i]);
	scanf("%s", str);

	sort(xyz, xyz + 3);

	for (int i = 0; i < strlen(str); i++)
	{
		switch (str[i])
		{
		case 'R':
			cr++; break;
		case 'Y':
			cy++; break;
		case 'B':
			cb++; break;
		default:
			break;
		}
		q = ++p;

		m[0] = abs(cr - cy);
		m[1] = abs(cr - cb);
		m[2] = abs(cy - cb);
		sort(m, m+3);

		if (xyz[0] == m[0] && xyz[1] == m[1] && xyz[2] == m[2])
		{
			cr = cy = cb = 0;
			p = 0;
		}
		if (r <= q)
			r = q;
	}
	printf("%d", r);
	system("pause");	
}
