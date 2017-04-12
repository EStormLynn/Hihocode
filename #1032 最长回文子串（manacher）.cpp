#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestPalindrome(string s) {
	string ss = "#";
	for (int i = 0; i<s.length(); i++)
	{
		ss += s[i];
		ss += '#';
	}
	vector<int> P(ss.length(), 0);

	int center = 0, boundary = 0, maxLen = 0, resCenter = 0;
	for (int i = 1; i<ss.length() - 1; i++) {
		int iMirror = 2 * center - i;
		P[i] = (boundary>i) ? min(boundary - i, P[iMirror]) : 0;
		while (i - 1 - P[i] >= 0 && i + 1 + P[i] <= ss.length() - 1 && ss[i + 1 + P[i]] == ss[i - 1 - P[i]])
			P[i]++;
		if (i + P[i]>boundary) { // 更新边界
			center = i;
			boundary = i + P[i];
		}
		if (P[i]>maxLen) { // 更新res
			maxLen = P[i];
			resCenter = i;
		}
	}
	return maxLen;
}

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		string str;
		cin >> str;
		cout << longestPalindrome(str) << endl;
	}
	return 0;
}