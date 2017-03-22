#include "iostream"
#include "map"
#include "algorithm"
#include "string"
using namespace std;

map<string, string> mmap;

void putIn(string s)
{
	if (!mmap.count(s))
		mmap[s] = s;
}

string getFather(string s)
{
	if (mmap[s] != s)
		mmap[s] = getFather(mmap[s]);
	return mmap[s];
}

void join(int tag, string a, string b)
{
	string fa = getFather(a), fb = getFather(b);
	if (tag == 0)
	{
		if (fa != fb)
			mmap[fa] = fb;
	}
	else
	{
		if (fa != fb)
		{
			cout << "no" << endl;
		}
		else
			cout << "yes" << endl;
	}
}

int main()
{
	int n,tag;
	string s1, s2;
	cin >> n;
	while (n--)
	{
		cin >> tag >> s1 >> s2;
		
		putIn(s1); putIn(s2);
		join(tag,s1, s2);		
	}
}