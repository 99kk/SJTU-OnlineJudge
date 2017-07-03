#include <iostream>

using namespace std;

//AC

int main()
{
	int n, x = 0;
	cin >>n;
	int *a = new int[n], totalWater = 0;
	char c;cin>>c;
	for(int i = 0; i < n; i++)
	{

		cin>>c;
		while(c != ',' and c != ']')
		{
			x = x * 10 + c - '0';
			cin>>c;
		}
		a[i] = x;
		x = 0;
	}
	int pre, post, lower;
	for(int i = 0; i < n; i++)
	{
		int p = a[i], q = a[i];
		for( pre = i; pre>=0; pre--){if(p<a[pre])p = a[pre];}
		for(post = i; post< n; post++){if(q<a[post])q = a[post];}
		lower = min(q,p);
		totalWater += lower - a[i];


	}


	cout<<totalWater;


    return 0;
}
