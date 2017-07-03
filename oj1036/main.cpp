#include <iostream>

using namespace std;
//AC

int main()
{
	long n,x, oldWait = 0,oldtime = 0, oldWaitTime[3], newWaitTime = 0, oldClock[3], newClock = 0;

	cin>>n;

	long c1 = 0, w1 = 0, c2 = 0, w2 = 0, c3 = 0, w3 = 0;

	for(int i = 0; i < 3; i++)
	{
		oldClock[i] = 0;
		oldWaitTime[i] = 0;

	}


	for(int i = 0; i < n; i++)
	{
		cin>>x;

		oldWaitTime[i%3] = oldWaitTime[i%3] + oldClock[i%3];
		oldClock[i%3] += x;

		if(c1<= c2 and c1 <= c3)
		{
			w1 += c1; c1 += x;
		}
		else if(c2 <= c3)
		{
			w2 += c2; c2 += x;
		}
		else { w3 += c3; c3 += x; }


	}

	for(int i = 0; i < 3; i++)
		{
			oldWait += oldWaitTime[i];
			if(oldtime < oldClock[i]) oldtime = oldClock[i];
		}

	long newMaxClock = c1;
	if(newMaxClock < c2) newMaxClock = c2;
	if(newMaxClock < c3) newMaxClock = c3;

	cout<<oldWait<<" "<<oldtime<<endl;
cout<<w1+w2+w3<< " "<<newMaxClock ;






    return 0;
}
