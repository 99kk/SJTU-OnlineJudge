#include <iostream>

using namespace std;

//ac

int main()
{
    int a[200], b[200], res[203], i = 0, j = 0;
    for(i = 0; i < 200; i++)
	{
		a[i] = b[i] = 0;
		res[i] = -1;
	}
	res[200] = res[201] = res[202] = -1;

	i = j = 0;
	char c = cin.get();
	while( c != '\n')
	{
		if(c == '.') ;
		else
			a[++i] = c - '0';
		c = cin.get();
	}

	c = cin.get();
	while( c != '\n')
	{
		if(c == '.') ;
		else
			b[++j] = c - '0';
		c = cin.get();
	}

	int tail = max(i,j);
	int sum, carry = 0;
	while(i > 0 && j > 0)
	{
		sum = a[i] + b[j] + carry;
		carry = sum / 10;
		sum = sum % 10;
		res[tail--]  = sum;

		i--; j--;
	}

	while(i > 0)
	{
		sum = a[i] + carry;
		carry = sum / 10;
		sum = sum % 10;
		res[tail--]  = sum;
		i--;
	}

	while(j > 0)
	{
		sum = b[j] + carry;
		carry = sum / 10;
		sum = sum % 10;
		res[tail--]  = sum;
		j--;
	}

	res[tail] = carry;


	if(res[0] == 1) cout<<1;
	for(i = 1; res[i+2]!= -1; i++)
	{
		cout<<res[i];
	}
	cout<<'.';
	cout<<res[i]<<res[i+1]<<endl;


    return 0;
}
