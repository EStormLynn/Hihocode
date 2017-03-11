#include <stdio.h>
#include <set>
using namespace std;

char s[52][52];
int N, M;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
set<int> area, shape;

int dfs(int i, int j, int *mini, int *minj, int *maxi, int *maxj) {
	if (i < *mini)
		*mini = i;
	if (i > *maxi)
		*maxi = i;
	if (j < *minj)
		*minj = j;
	if (j > *maxj)
		*maxj = j;
	s[i][j] = 'x';
	int a = 1;
	for (int d = 0; d < 4; ++d) {
		int ni = i + di[d], nj = j + dj[d];
		if (s[ni][nj] == '#')
			a += dfs(ni, nj, mini, minj, maxi, maxj);
	}
	return a;
}

int mhash(int mini, int minj, int maxi, int maxj) {
	int k = 79, sh = 0;
	for (int i = mini; i <= maxi; ++i) {
		for (int j = minj; j <= maxj; ++j) {
			sh = sh * k + s[i][j];
		}
		k*=91;
	}
	return sh;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%s", s[i + 1] + 1);
	int n1 = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (s[i][j] == '#') {
				n1++;
				int mini = i, maxi = i, minj = j, maxj = j;
				area.insert(dfs(i, j, &mini, &minj, &maxi, &maxj));
				shape.insert(mhash(mini, minj, maxi, maxj));
			}
	printf("%d %d %d", n1, area.size(), shape.size());
	return 0;
}
