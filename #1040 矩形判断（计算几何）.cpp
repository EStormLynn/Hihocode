#include"iostream"

using namespace std;

struct Point{
	int x, y;	
};

struct Line{
	Point p1, p2;
};

bool judgePoint(Line *l)
{
	Point tag[4];
	int taga[4] = { 0 };
	
	for (int i = 0; i < 4; i++)
	{
		tag[i] = l[0].p1;
		for (int j = 0; j < 4; j++)
		{			
			if ((tag[i].x == l[j].p1.x &&tag[i].y == l[j].p1.y) || (tag[i].x == l[j].p2.x &&tag[i].y == l[j].p2.y))
				taga[i]++;
		}
	}

	bool flag = false;
	for (int i = 0; i < 4; i++)
	{

		if (taga[i] == 2)
			flag = true;
		else
		{
			flag = false;
			break;
		}
			
	}
	return flag;
}

bool judgeLine(Line *l)
{
	for (int i = 1; i<4; ++i)
	{
		//判断是不是垂直    
		if ((l[0].p1.y - l[0].p2.y)*(l[i].p1.y - l[i].p2.y) == -(l[0].p1.x - l[0].p2.x)*(l[i].p1.x - l[i].p2.x))
			continue;
		//判断是不是平行    
		if ((l[0].p1.y - l[0].p2.y)*(l[i].p1.x - l[i].p2.x) == (l[0].p1.x - l[0].p2.x)*(l[i].p1.y - l[i].p2.y))
			continue;
		return false;
	}
	return true;
}
	
int main()
{
	int n;
	Line l[4];
	cin >> n;
	while (n--)
	{
		for (int i = 0; i < 4; i++)
		{
				cin >> l[i].p1.x >> l[i].p1.y >> l[i].p2.x >> l[i].p2.y;
		}

		if (judgePoint(l) && judgeLine(l))
			cout << "YES"<<endl;
		else
			cout << "NO"<<endl;
	}

	system("pause");
	return 0;
}