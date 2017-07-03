#include <iostream>

using namespace std;

//AC

int slice(int x[], int h[], int low, int high)
{
	int key = x[low], i =low, j = low+1, tem;
	for(j = low+1; j <= high; j++)
	{
		if(x[j] < key)
		{
			i++;
			tem = x[i]; x[i] = x[j]; x[j] = tem;
			tem = h[i]; h[i] = h[j]; h[j] = tem;
		}
	}
		x[low] = x[i]; x[i] = key;
		tem = h[low]; h[low] = h[i]; h[i] = tem;
	return i;
}

void quickSort(int x[], int h[], int low, int high)
{
	if(low < high)
	{
		int w = slice(x,h,low, high);
		quickSort(x,h, low, w-1);
		quickSort(x,h,w+1, high);
	}
}

int main()
{
	int n,d;
	cin>>n>>d;
	if(n<=2) {cout<<0<<endl;return 0;}

	int i, crowedCow = 0;

	int *x = new int[n+1], *h = new int[n+1];

	for(i = 1; i <= n; i++)
	{
		cin>>x[i]>>h[i];
	}

	quickSort(h,x,1,n);


	int doubleHight = 1, j;
	bool leftSide = false, rightSide = false;

	for(i = 1; i < n; i++)
	{
		while(h[doubleHight] < h[i]*2 and doubleHight <= n) doubleHight++;
		leftSide = rightSide = false;
		for(j = doubleHight; j <= n; j++)
		{
			if( x[j]>x[i] and x[j]-x[i] <= d) leftSide = true;
			if(x[j]<x[i] and x[i] - x[j] <= d) rightSide = true;
			if(leftSide and rightSide){crowedCow++; break;}
		}

	}



	cout<<crowedCow<<endl;


    return 0;
}
