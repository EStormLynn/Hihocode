#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 100009
int a[MAX];

int binary_search(int* a, int len, int goal)
{
	int low = 0;
	int high = len - 1;
	while (low <= high)
	{
		int middle = (high - low) / 2 + low; // 直接使用(high + low) / 2 可能导致溢出
		if (a[middle] == goal)
			return middle+1;
		else if (a[middle] > goal)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1;
}


int main(){
	int n, tag, left, right,mid,ans;
	cin >> n>>tag;

	for (int i = 0; i < n;i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	left = 0;
	right = n - 1;

	cout << binary_search(a, n, tag);

	return 0;
}