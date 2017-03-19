#include"iostream"
#define MOD 19999997
using namespace std;

typedef long long LL;

struct Matrix
{
	LL matrix[2][2];
}ans,base;

Matrix mult(Matrix a,Matrix b)
{
	Matrix c;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			c.matrix[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				c.matrix[i][j] += (a.matrix[i][k] * b.matrix[k][j]) % MOD;
			}
			c.matrix[i][j] %= MOD;
		}
	}	
	return c;
}

LL solve(LL n)
{
	base.matrix[0][1] = base.matrix[1][0] = base.matrix[1][1] = 1;
	base.matrix[0][0] = 0;

	//初始化单位矩阵
	ans.matrix[0][0] = ans.matrix[1][1] = 1;
	ans.matrix[0][1] = ans.matrix[1][0] = 0;

	while (n)
	{
		if (n & 1)
		{
			ans = mult(ans, base);
			//break;
		}
		base = mult(base, base);
		n >>= 1;     //n右移一位，n=n>>1  n/2

	}
	return ans.matrix[0][1] % MOD;
	
}

int main()
{
	LL n;
	scanf("%lld", &n);

	printf("%lld", solve(n+1) % MOD);
	system("pause");
}                                                                                       