#include "iostream"

using namespace std;

int Josephus(int n, int k) {
    if (n == 1) {
        return 0;
    } else if (n < 2 * k) {
        int ret = 0;
        for (int i = 2; i <= n; ++i)
            ret = (ret + k) % i;
        return ret;
    }
    int ret = Josephus(n - n / k, k), mod = n % k;
    if (ret < mod)
        ret = ret - mod + n;
    else
        ret = ret - mod + (ret - mod) / (k - 1);
    return ret;
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << Josephus(n, k) << endl;
    }
}


//int solve(int i, int m)// i总长  m步数
//{
//	if (i == 1)
//		return 1;
//	return (solve(i - 1, m) + m - 1) % i + 1;
//}