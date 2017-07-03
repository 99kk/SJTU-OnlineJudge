#include <iostream>

using namespace std;

//AC

bool isRunYear(int y)
{
	if(y % 400 == 0) return true;
	if(y % 4 == 0 and  y % 100 != 0) return true;
	return false;
}

int getFirstDateInMouth(int y, int m, int yearFirstDate)
{
	int mouth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(isRunYear(y)) mouth[2] = 29;
	int days = 0;
	for(int i = 1; i < m; i++)
		days+=mouth[i];

	int DateThisMouth = (days  + yearFirstDate) % 7;
	if(DateThisMouth == 0) DateThisMouth = 7;
	return DateThisMouth;

}



int main()
{
	int a,b,c,y1,y2;
	cin>>a>>b>>c>>y1>>y2;
	int mouth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, mouthForRunYear[13] ={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int daysBefore = 0;
	for(int y = 1850; y < y1; y++)
	{
		if(isRunYear(y)) daysBefore += 366;
		else daysBefore += 365;
	}
	int firstD = (daysBefore + 2) % 7 ;
	if(firstD == 0) firstD = 7;

	for(int y = y1; y <= y2; y++)
	{

		int dateOnThatMouth = getFirstDateInMouth(y,a,firstD);
		int d = 1;

		if(dateOnThatMouth > c){ d+= 8 - dateOnThatMouth; dateOnThatMouth = 1; }
		while(dateOnThatMouth < c){d++; dateOnThatMouth++;}


		d += (b - 1) * 7;

		if(isRunYear(y))
		{
			if(d > mouthForRunYear[a]) cout<<"none"<<endl;
			else
			{
				cout<<y<<"/";
				if(a<10)cout<<0;
				cout<<a<<"/";
				if(d<10)cout<<0;
				cout<<d<<endl;
			}
		}
		else
		{
			if(d > mouth[a]) cout<<"none"<<endl;
			else
			{
				cout<<y<<"/";
				if(a<10)cout<<0;
				cout<<a<<"/";
				if(d<10)cout<<0;
				cout<<d<<endl;
			}
		}

		if(isRunYear(y))
		{
			firstD = (366+ firstD)% 7 ;
		}
		else firstD = (365 +firstD) % 7 ;
		if(firstD == 0) firstD = 7;
	}













    return 0;
}
