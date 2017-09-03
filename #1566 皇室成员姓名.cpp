#include<iostream>
#include <string>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 100005;

typedef struct Name {
	string name;
	string agestr;
	int age;
}Name;

Name name[N];

int weight[300];
void initWeight()
{
	//I	V	X	L	C	D	M
	//1	5	10	50	100	500	1,000
	weight['I'] = 1;
	weight['V'] = 5;
	weight['X'] = 10;
	weight['L'] = 50;
	weight['C'] = 100;
	weight['D'] = 500;
	weight['M'] = 1000;
}
/*
I	V	X	L	C	D	M
Value	1	5	10	50	100	500	1,000
*/

int getNum(string roma)
{
	int l = roma.length();

	int sum = 0;
	for (int i = l - 1; i >= 0; --i)
	{
		if (i>0 && weight[roma[i - 1]]<weight[roma[i]])
		{
			sum += weight[roma[i]] - weight[roma[i - 1]];
			i--;
		}
		else
		{
			sum += weight[roma[i]];
		}
	}

	return sum;
}

bool cmp(Name a, Name b)
{
	if (a.name != b.name)
		return a.name < b.name;
	return a.age < b.age;
}

int main()
{
	initWeight();

	int n;
	cin >> n;

	for (int i = 0; i<n; ++i)
	{
		string s;
		cin >> s;
		name[i].name = s;
		cin >> s;
		name[i].agestr = s;
		name[i].age = getNum(s);
	}

	sort(name, name + n,cmp);

	for (int i = 0; i<n; ++i)
	{
		cout << name[i].name << " " << name[i].agestr << endl;
	}
}