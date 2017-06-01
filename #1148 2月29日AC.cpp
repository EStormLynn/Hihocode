#include"iostream"
#include "cstring"
using namespace std;

char months[12][20] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

bool isRyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}

int cal(int month, int day, int year)
{
	int sum = year / 4 - year / 100 + year / 400;
	if (isRyear(year) && (month < 2 || (month == 2 && day < 29)))
		sum--;
	return sum;
}
// 

int main()
{
	int t;
	scanf("%d", &t);
	int p = 1;
	while (t--)
	{
		char month1[20], month2[20] ;
		int year1, year2, mon1, mon2, day1, day2, ans, years;
		
		scanf("%s %d,%d", &month1, &day1, &year1);
		scanf("%s %d,%d", &month2, &day2, &year2);

		for (int i = 0; i < 12; i++)
		{
			if (strcmp(month1, months[i]) == 0)
				mon1 = i + 1;
			if (strcmp(month2, months[i]) == 0)
				mon2 = i + 1;
		}

		ans = cal(mon2, day2, year2) - cal(mon1, day1, year1);
		if (mon1 == 2 && day1 == 29)
			ans++;
		printf("Case #%d: %d\n", p++,ans);
	}
}
