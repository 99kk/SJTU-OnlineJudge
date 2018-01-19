#include <iostream>

using namespace std;

//ac

int monthDays[] ={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//基姆拉尔森计算公式 Kim larsson calculation formula
int whichWeekday(int y, int m, int d)
{
	if(m== 1 || m == 2)
	{
		m += 12;
		y--;
	}
	int w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
	return w+1;
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool isHolidayAndWeekday(int year, int month, int day)
{
	if(whichWeekday(year, month, day) < 6)
	{
		if((month == 1 && day == 1) || (month == 5 && day >= 1 && day <= 3) || (month == 10 && day >= 1 && day <= 7))
			return true;
	}
	return false;
}

int daysWholeYear(int year)
{
	int days = 0, i;
	int weekStart = 1, weekNum = 53, thisYearDays = 365 + isLeapYear(year);
	while(whichWeekday(year, 1, weekStart) != 1)
		weekStart++;
	while(weekStart - 1 + weekNum * 7 > thisYearDays)
		weekNum--;

	for(i = 1; i < weekStart; i++)
		if(whichWeekday(year, 1, i) < 6)
			days++;
	for(i = 0; i < thisYearDays - (weekStart - 1 + weekNum * 7); i++)
		if(whichWeekday(year, 12, 31-i) < 6)
			days++;
	days += weekNum * 5;

	// 1.1
	if(whichWeekday(year, 1, 1) < 6) days--;

	//5.1 - 5.3
	for(i = 1; i <= 3; i++)
		if(whichWeekday(year, 5, i) < 6) days--;

	//10.1 - 10.7
	for(i = 1; i <= 7; i++)
		if(whichWeekday(year, 10, i) < 6) days--;

	return days;
}

int daysSameYear(int year, int monthStart, int dayStart, int monthEnd, int dayEnd)
{
	int days = 0, i, j;
	for(i = monthStart + 1; i <= monthEnd - 1; i++)
	{
		if(i == 2 && isLeapYear(year))
		{
			for(j = 1; j <= 29; j++)
				if(whichWeekday(year, 2, j) < 6)
					days++;
		}
		else
			for(j = 1; j <= monthDays[i]; j++)
			{
				if(whichWeekday(year, i, j) < 6)
					days++;
				if(isHolidayAndWeekday(year, i, j))
					days--;
			}
	}

	if (monthStart == monthEnd)
		for(i = dayStart; i <= dayEnd; i++)
		{
			if(whichWeekday(year, monthStart, i) < 6)
				days++;
			if(isHolidayAndWeekday(year, monthStart, i))
				days--;
		}
	else
	{
		for(i = dayStart; i <= monthDays[monthStart]+(monthStart==2 && isLeapYear(year)); i++)
		{
			if(whichWeekday(year, monthStart, i) < 6)
				days++;
			if(isHolidayAndWeekday(year, monthStart, i))
				days--;
		}

		for(i = 1; i <= dayEnd; i++)
		{
			if(whichWeekday(year, monthEnd, i) < 6)
				days++;
			if(isHolidayAndWeekday(year, monthEnd, i))
				days--;
		}

	}

	return days;
}

int main()
{
    int n, i, j, yearStart, monthStart, dayStart, yearEnd, monthEnd, dayEnd, totalDays;
    cin>>n;
	cin.get();
    for(i = 0; i < n; i++)
	{
		yearStart = yearEnd = monthEnd = monthStart = dayStart = dayEnd = 0;
		for(j = 0; j < 4; j++)
			yearStart  = yearStart * 10 + cin.get() - '0';
		cin.get();
		monthStart = (cin.get()-'0') * 10 + cin.get() - '0';
		cin.get();
		dayStart = (cin.get()-'0') * 10 + cin.get() - '0';
		cin.get();
		for(j = 0; j < 4; j++)
			yearEnd  = yearEnd * 10 + cin.get() - '0';
		cin.get();
		monthEnd = (cin.get()-'0') * 10 + cin.get() - '0';
		cin.get();
		dayEnd = (cin.get()-'0') * 10 + cin.get() - '0';
		cin.get();

		totalDays = 0;
		for(j = yearStart+1; j <= yearEnd-1; j++)
			totalDays += daysWholeYear(j);

		if(yearStart == yearEnd)
			totalDays += daysSameYear(yearStart, monthStart, dayStart, monthEnd, dayEnd);
		else
		{
			totalDays += daysSameYear(yearStart, monthStart, dayStart, 12, 31);
			totalDays += daysSameYear(yearEnd, 1, 1, monthEnd, dayEnd);
		}


		cout<<totalDays<<endl;
	}
    return 0;
}
