#include <iostream>

using namespace std;

//ac
// ¿ìËÙÅÅĞò

int slice(int *a, int low, int high)
{
	int key = a[low], i = low, j, tem;
	for(j = low+1; j <= high; j++)
	{
		if(a[j] < key)
		{
			i++;
			tem = a[i]; a[i] = a[j]; a[j] = tem;
		}
	}
	tem = a[i]; a[i] = a[low]; a[low] = tem;
	return i;
}

void qsort(int *a, int low, int high)
{
	if( low< high)
	{
		int w = slice(a, low, high);
		qsort(a, low, w-1);
		qsort(a, w+1, high);
	}
}


int main()
{
    int n;
    cin>>n;
    int *a = new int[n+1];
    for(int i = 0; i < n; i++)
		cin>>a[i];

	qsort(a, 0, n-1);

	for(int i = 0; i <n; i++)
		cout<<a[i]<<" ";




    return 0;
}
