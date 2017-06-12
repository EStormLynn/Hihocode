#include "iostream"
#include "set"
using namespace std;

int main()
{
	int n,k,ans;
	set<int> s;
	char c;

	cin >> n;
	while (n--)
	{
		cin >> c >> k;
		if (c == 'I')
			s.insert(k);
		else
		{
			set<int>::iterator  it = s.upper_bound(k);
			it--;
			cout << *it << endl;
		}
	}
}
