#include"iostream"
#define MAX 5000000

using namespace std;

bool isPrime[MAX+1];
int primeList[MAX+1];
int phi[MAX];
int primeCount = 0;

int solve(int l, int r)
{
	for (int i = 0; i <= MAX; i++)
		isPrime[i] = true, phi[i] = 1;

	for (int i = 2; i <= MAX; i++)
	{
		if (isPrime[i]) {
			primeList[++primeCount] = i;
			phi[i] = i - 1;
		}

		for (int j = 1; j <= primeCount; j++) {
			if (i*primeList[j] > MAX) break;
			isPrime[i*primeList[j]] = false;
			if (i%primeList[j] == 0) {
				phi[i*primeList[j]] = phi[i] * primeList[j];
				break;
			}
			else phi[i*primeList[j]] = phi[i] * (primeList[j] - 1);
		}
	}


	int min = l;
	for (int i = l; i <= r; i++)
	if (phi[i]<phi[min])
	{
		min = i;
	}

	return min;
}

int main()
{
	int k, l, r;
	cin >> l >> r;

	cout << solve(l, r);
	system("pause");

}

