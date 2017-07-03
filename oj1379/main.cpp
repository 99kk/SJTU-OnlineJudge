#include <iostream>

using namespace std;

//关羽
//ac 时间稍长 4700ms



int main()
{
	int n, totalLen = 0, x, i, j, k, num = 0;
	cin>>n;
	int *a = new int[n+1];

	int halfPoint;
	a[0] = 0;
	for(i = 0; i < n; i++)
	{
		cin>>x;
		totalLen += x;
		a[i+1] = totalLen;

	}
	int half = totalLen /2;
	for(i = 0; i < n; i++)
	{
		if( a[i] >= half ) {halfPoint = i;break;}
	}

	if(totalLen % 2 == 1)
	{
		cout<<0<<endl;
		return 0;
	}

	bool first, second;
	for(i = 0; i < halfPoint; i++)
		{
			for(j = i+1; j < halfPoint; j++)
			{
				first = false; second = false;
				for(k = halfPoint; k < n; k++)
				{
					if(a[k] == a[i] + half) first = true;
					if(a[k] == a[j] +half) second = true;
					if(first and second) break;
				}
				if(first and second)
					num++;


			}
		}

		cout<<num;


    return 0;
}
