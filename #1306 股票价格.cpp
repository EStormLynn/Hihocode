#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

//��Ź�Ʊʱ��ͼ۸�
map<int, int> p;
//��Ʊʱ��
int a[100];
int t, i = 0,rem_i=0;
//������
char s;

//�����С�������
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
	mapi--;                //p.den()Ϊmap�����һ��Ԫ�ص���һ����ַ��

	cout << max << " "<< min <<" ";
	cout << mapi->second <<endl;

}

//ɾ��jʱ��֮ǰ����j�Ĳ���
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