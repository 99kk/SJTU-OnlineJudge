#include <iostream>
#include <stdio.h>

//ac

using namespace std;

int a[8001];

int main()
{
	int m,i, p, n, k[8], j, totalNum,curNum, lastEaten , start = 0, cnt = 0;
	scanf("%d", &m);
	for(p = 1; p <= m; p++)
	{
		scanf("%d", &n);
		for(j  =1; j <= 7; j++) scanf("%d", &k[j]);
		for(j= 0; j <= 8 * n; j++) a[j] = 1;

		totalNum = curNum = 8 * n;
		lastEaten = -1;

		for(j = 1; j <= 7; j++)
		{
			//cout<<endl<<"j:"<<j<<endl;
			//if(curNum < k[j]) break;

			for(i = lastEaten+1; i< lastEaten+totalNum; i++) if(a[i%totalNum] == 1) {start = i% totalNum;break;}
			cnt = 0;
			for(i = start; i < start + totalNum; i++)
			{
				if(a[i%totalNum] == 0) continue;

				if(a[i%totalNum] == 1)
				{
					cnt++;
				}
				if(cnt == k[j])
				{
					int c = 0;
					while(c < k[j] and i < start + totalNum)
					{
						//cout<<"i:"<<i<<"   ";for(int t = 0; t < 8*n; t++) cout<<a[t]<<" "; cout<<" lasteaten:";	cout<<lastEaten<<endl;
						if(a[i%totalNum] == 0) {i++;continue;}
						a[i%totalNum] = 0; c++;i++; curNum--;
						lastEaten = (i-1)%totalNum;
					}
					cnt = 0; i--;
				}

			//cout<<"i:"<<i<<"   ";	for(int t = 0; t < 8*n; t++) cout<<a[t]<<" "; cout<<" lasteaten:";	cout<<lastEaten<<endl;

			}
		}
		cout<<lastEaten+1<<endl;
	}

    return 0;
}
