#include <iostream>
#include <stdio.h>

using namespace std;
//ac
int main()
{
    int n;
    scanf("%d", &n);
    int *a = new int[n];

    for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	int cur, counts;
	for(int i = 0; i < n; i++)
	{
		cur = a[i]; counts = 0;
		for(int j = i+1; j < n; j++)
			if(a[j] <cur ) counts++;
		printf("%d ", counts);
	}

    return 0;
}
