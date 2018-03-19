#include <iostream>

using namespace std;
//ac

int a[100001], b[100001], sum[100002], s;

int main()
{
    int i,j, k, digNum;
    char c;
    i = j = 1;
    c = cin.get();
    while(c != '\n')
	{
		a[i++] = c - '0';
		c = cin.get();
	}


	c = cin.get();
    while(c != '\n')
	{
		b[j++] = c - '0';
		c = cin.get();
	}


	k = digNum = max(i,j);
	int carry = 0;
	while(i > 1 && j > 1 )
	{
		i--; j--;
		s = a[i]+ b[j] + carry;
		carry = s / 10;
		s = s % 10;
		sum[k--] = s ;
	}

	while(i > 1){
		i--;
		s = a[i] + carry;
		carry = s / 10;
		s = s % 10;
		sum[k--] = s ;
	}
	while(j > 1){
		j--;
		s = b[j] + carry;
		carry = s / 10;
		s = s % 10;
		sum[k--] = s ;
	}

	sum[k--] = carry;

	while(sum[++k] == 0);


    for(; k <= digNum; k++)
		cout<<sum[k];

    return 0;
}
