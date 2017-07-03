#include <iostream>

using namespace std;

//³©³©µÄÑÀÇ©
//ac

int main()
{
	int n, i,j,k, num = 0, x, y, z;
	cin>>n;
	int digtal[10] = {6,2,5,5,4,5,6,3,7,6};
	int allNumbers[1000];
	for(i = 0; i < 1000; i++)
	{
		 x = i;
		 allNumbers[i] = 0;
		 while(x>= 10)
		 {
		 	allNumbers[i] += digtal[x % 10] ;
		 	x /= 10;
		 }
		 allNumbers[i] += digtal[x];
	}


	for(i = 999; i >= 0; i--)
		for(j = i; j >= 0; j--)
	{
		if(allNumbers[i] + allNumbers[j] + 3  + allNumbers[i-j] == n)
			num++;
			//cout<<i<<"-"<<j<<endl;
	}

	cout<<num;

    return 0;
}
