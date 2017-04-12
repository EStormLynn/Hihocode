#include "iostream"
#define MAX 20000000

using namespace std;

typedef long long LL;

LL m[MAX], r[MAX], n ;

LL gcd(LL a, LL b){
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

void extend_gcd(LL a, LL b, LL &x, LL &y){
	if (b == 0){
		x = 1;
		y = 0;
		return ;
	}

	LL x1, y1;
	extend_gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a / b)*y1;
}

LL Solve()
{
	LL M = m[1], R = r[1], d, k1, k2, c;
	for (int i = 2; i <= n; i++)
	{
		d = gcd(M, m[i]);
		c = r[i] - R;
		if (c % d)
			return -1;                          // 无解的情况
		extend_gcd(M / d, m[i] / d, k1, k2);
		k1 = (c / d*k1) % (m[i] / d);           // 计算x = m[1] * k[1] + r[1]
		R = R + k1*M;                           // 求解lcm(M, m[i])
		M = M / d*m[i];                         // 求解合并后的新R，同时让R最小
		R %= M;
	}
	if (R < 0)
		R = R + M;
	return R;
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> m[i] >> r[i];
	cout << Solve() << endl;

	system("pause");
}
