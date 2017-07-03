#include <iostream>

using namespace std;

//ac

int main()
{
    int n, a[110], i, j, left[110], right[110];
    cin>>n;
    for(i = 1; i <= n; i++)
		cin>>a[i];

	left[1] = right[n] = 0;

    int curMaxNum;
    bool exist;
    for(i = 2; i <=n; i++)
	{
		curMaxNum = left[1]; exist = false;
		for(j = 1; j < i; j++)
		{
			if(a[j] >= a[i]) continue;
			else
			{
				exist = true;
				if(curMaxNum < left[j])
				{
					curMaxNum = left[j];
				}
			}
		}

		if(exist)
			left[i] = curMaxNum + 1;
		else
			left[i] = 0;
	}

	for(i = n-1; i >=1; i--)
	{
		curMaxNum = right[n]; exist = false;
		for(j = n; j > i; j--)
		{
			if(a[j] >= a[i]) continue;
			else
			{
				exist = true;
				if(curMaxNum < right[j])
				{
					curMaxNum = right[j];
				}
			}
		}
		if(exist)
			right[i] = curMaxNum + 1;
		else
			right[i] = 0;
	}

	int curSum = 0, maxSum = 0;

	for(i = 1; i <= n; i++)
	{
		curSum = left[i] + right[i];
		if(maxSum < curSum)
			maxSum = curSum;
	}

/*
	for(i = 1; i <= n; i++)
	{
		cout<<left[i]<<" ";
	}
	cout<<endl;
	for(i = 1; i <= n; i++)
		cout<<right[i]<<" ";
	cout<<endl;
*/


	cout<<n - maxSum -1<<endl;
    return 0;
}
