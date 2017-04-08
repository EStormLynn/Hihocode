#include<iostream>
using namespace std;
const int max_n = 1000005;
bool isPrime[max_n + 1];
int primeList[max_n];

int main() {
	int n;  
	while (cin >> n)
	{
		int primeCount = 0;


		for (int i = 0; i <= n; i++)    // ³õÊ¼»¯
			isPrime[i] = true;

		for (int i = 2; i <= max_n; i++) {
			if (isPrime[i]) primeList[primeCount++] = i;

			for (int j = 0; j < primeCount; j++) {
				if (i*primeList[j] > max_n) break;
				isPrime[i*primeList[j]] = false;
				if (i%primeList[j] == 0) break;
			}
		}

		for (int i = 2; i <= max_n; i++)
		{
			if (isPrime[i]&&isPrime[n - i])
			{
				cout << i << " " << n - i << endl;
				break;
			}
		}
	}

	return 0;
}
