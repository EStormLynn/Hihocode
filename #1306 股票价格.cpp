#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

//存放股票时间和价格
map<int, int> p;
//股票时间
int a[100];
int t, i = 0,rem_i=0;
//操作符
char s;

//最大最小最近操作
void max_min_near()
{
	map<int, int>::iterator mapi = p.begin();
	int max = mapi->second;
	int min = mapi->second;
	for (; mapi != p.end(); mapi++)
	{
		if (max < mapi->second)
			max = mapi->second;
		if (min > mapi->second)
			min = mapi->second;
	}
	mapi--;                //p.den()为map中最后一个元素的下一个地址，

	cout << max << " "<< min <<" ";
	cout << mapi->second <<endl;

}

//删除j时间之前包括j的操作
void remove_i(int j)
{
	map<int, int>::iterator mapi=p.begin();
	while (mapi->first<=j){
		p.erase(mapi++);
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> s;
		switch (s)
		{
			case 'P':
				cin >> a[i];
				cin >> p[a[i]];	
				i++;  break;
			case 'Q':
				max_min_near(); break;
			case 'R':
				cin >> rem_i;
				remove_i(rem_i);
		}
	}
	system("pause");
	return 0;
}