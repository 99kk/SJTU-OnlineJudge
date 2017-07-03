#include <iostream>

using namespace std;

//AC

int main()
{
	int n, k, *a, curMax, allMaxMin, curMaxPos;
	cin>>n>>k;
	a = new int[n+k+1];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = n; i < n+k+1; i++)
		a[i] = a[i-n];


	curMax = a[0];
	curMaxPos = 0;
	for(int i = 0; i < k; i++)
	{
		if(curMax < a[i]) {curMax = a[i];curMaxPos = i;}
	}
	allMaxMin = curMax;

	for(int i = curMaxPos+1; i < n;)
	{
		curMax = a[i];

		for(int j =0; j < k; j++)
		{
			if(curMax < a[i+j]) {curMax = a[i+j];curMaxPos = i+j;}
		}
		if(allMaxMin > curMax) allMaxMin = curMax;
		if(i == curMaxPos) i++;
		else i = curMaxPos+1;
	}



	cout<<allMaxMin;

    return 0;
}
