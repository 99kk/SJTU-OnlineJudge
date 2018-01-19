#include <iostream>

using namespace std;

//note that it must be two key chosen
//ac

int n, *a;

int maxsum(int low, int high)
{
	if(low + 1 == high) return a[low]+a[high];
	if(low == high) return 0;

	int mid = (low+ high)/2;
	long left = maxsum(low, mid), right = maxsum(mid+1,high);

	long cursum = 0, curmaxl = a[mid], i;
	for(i = mid; i >= low; i--)
	{
		cursum += a[i];
		if(curmaxl < cursum)
			curmaxl = cursum;
	}
	cursum = 0;
	long curmaxr = a[mid+1];
	for(i = mid+1; i<= high; i++)
	{
		cursum += a[i];
		if(curmaxr < cursum)
			curmaxr = cursum;
	}
	long curmax = curmaxl+curmaxr;

	if(left < right) left = right;
	if(left < curmax) left = curmax;
	return left;

}

int main()
{
    int i;
    cin>>n;
    a = new int[n];
    for(i = 0; i < n; i++)
		cin>>a[i];




	long sum = maxsum(0,n-1);


	if(sum > 0)
		cout<<sum;
	else
		cout<<"Game Over";


    return 0;
}
