#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//5324124312
int bfs(long long n)
{
	queue<long long> q;
	int t = 1;
	long long head,last=n,nlast; //last当前行最右，nlast下一行最右
	q.push(n);
	while (!q.empty())
	{
		head = q.front();

		if (t == 4)
			break;
		q.pop();
		if (head != 0)
		{
			for (int i = sqrt(head); i > 0; i--)
			{
				if (head - i*i == 0)
					return t;
				q.push(head-i*i);

				nlast = head - i*i;
			}		

			if (head == last && !q.empty())
			{
				t++;
				last = nlast;
			}
		}
	}
}

int main()
{
	long long n;
	while (cin>>n)
	{
		if (n == -1)
			break;
		cout<< bfs(n)<<endl;

	}
	system("pause");
	return 0;
}
