#include <iostream>
typedef long long LL;
using namespace std;

int main() {
	int n, mod = 1000000007;
	LL s[101], pow2 = 1;

	s[0] = s[1] = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		s[i] = (s[i - 1] + s[i - 2] + pow2) % mod;
		pow2 = (pow2 * 2) % mod;
	}
	cout << s[n] << endl;
	system("pause");
	return 0;
}
