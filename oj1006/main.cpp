#include <iostream>

using namespace std;

int main()
{
	int n, *sum, *a, maxsum, i, premin = 0, curmax = 0;
	cin>>n;
	if(n<=0){cout<<"Game Over"<<endl; return 0;}
	a = new int[n];
	sum = new int[n];
	for(i = 0; i < n; i++)
	{
		cin>>a[i];
		sum[i] = 0;
	}

	sum[0] = a[0];
	maxsum = sum[0];

	for(i = 1; i < n; i++)
	{
		sum[i] = sum[i-1] + a[i];
		if(premin > sum[i-1]) premin = sum[i-1];
		curmax = sum[i] - premin;
		if(maxsum < curmax) maxsum = curmax;
	}

	if(maxsum>0) cout<<maxsum<<endl;
	else cout<<"Game Over"<<endl;


    return 0;
}
