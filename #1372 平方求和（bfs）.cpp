#include"iostream"
#include"cstring"
using namespace std;

struct trie
{
	trie *chi[26];
	int num;
	trie()
	{
		num = 0;
		for (int i = 0; i < 26; i++)
			chi[i] = NULL;
	}
}*root;

void insertTrie(char s[])
{
	trie *p = root;
	p->num++;
	for (int i = 0; s[i]; i++)
	{
		int j = s[i] - 'a';
		if (p->chi[j] == NULL)
			p->chi[j] = new trie;
		p = p->chi[j];
		p->num++;
	}
}

int searchTrie(char s[])
{
	trie *p = root;
	for (int i = 0; p && s[i]; i++)
	{
		int j = s[i] - 'a';
		p = p->chi[j];
	}
	if (!p) return 0;
	else return p->num;
}

int main()
{
	char s[12];
	int n, m;
	cin >> n;
	
	root = new trie;
	while (n--)
	{
		cin>>s;
		insertTrie(s);
	}
	cin>>m;
	while (m--)
	{
		cin>>s;
		cout<<searchTrie(s)<<endl;
	}
	int b;

	return 0;
}