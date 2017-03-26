#include "iostream"
#include "string"
#include "string.h"
using namespace std;

string str;
int ans = 100005;

int count1[256];
int count2[256];

string minWindow(string S, string T) {
	if (T.size() == 0 || S.size() == 0)
		return "";

	memset(count1, 0, sizeof(count1));
	memset(count2, 0, sizeof(count2));

	for (int i = 0; i < T.size(); i++)
	{
		count1[T[i]]++;
		count2[T[i]]++;
	}

	int count = T.size();

	int start = 0;
	int minSize = 100005;
	int minStart;
	for (int end = 0; end < S.size(); end++)
	{
		if (count2[S[end]] > 0)
		{
			count1[S[end]]--;
			if (count1[S[end]] >= 0)
				count--;
		}
		if (count == 0)
		{
			while (true)
			{
				if (count2[S[start]] > 0)
				{
					if (count1[S[start]] < 0)
						count1[S[start]]++;
					else
						break;
				}
				start++;
			}

			if (minSize > end - start + 1)
			{
				minSize = end - start + 1;
				minStart = start;
			}
		}
	}

	if (minSize == ans)
		return "";

	string ret(S, minStart, minSize);//string ¹¹Ôìº¯Êý
	return ret;
}

int main()
{
	while (cin >> str)
	{
		int l = minWindow(str, "hiho").length();
		if (l<4)
			cout << -1 << endl;
		else
			cout << l << endl;
	}
}