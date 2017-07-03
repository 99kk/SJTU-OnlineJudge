#include <iostream>

using namespace std;

//ac


int slice(int a[], int b[], int low, int high)
{
	int key = a[low], i = low, j, tem;
	for(j = low+1; j <= high; j++)
	{
		if(a[j] >= key)
		{
			i++;
			tem = a[i]; a[i] = a[j]; a[j] = tem;
			tem = b[i]; b[i] = b[j]; b[j] = tem;
		}
	}
	tem = a[i]; a[i] = a[low]; a[low] = tem;
	tem = b[i]; b[i] = b[low]; b[low] = tem;
	return i;
}

void quicksort(int a[], int b[], int low, int high)
{
	if(low < high)
	{
		int w = slice(a, b, low, high);
		quicksort(a,b,low,w-1);
		quicksort(a,b,w+1, high);
	}
}

int sliceLow(int a[], int low, int high)
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

void quicksortLow(int a[], int low, int high)
{
	if(low < high)
	{
		int w = sliceLow(a, low, high);
		quicksortLow(a,low,w-1);
		quicksortLow(a,w+1, high);
	}
}



int main()
{
    int i, m, s, c, *a, total = 0;
    cin>>m>>s>>c;
    a = new int[c];
	int *dif = new int[c];
	int *index = new int[c];
    for(i = 0; i < c; i++)
	{
		cin>>a[i];
	}

	quicksortLow(a,0,c-1);


	for(i = 1; i < c; i++)
	{
		dif[i] = a[i] - a[i-1];
		index[i] = i;
	}

	quicksort(dif, index, 1, c-1);

	m = min(m,c);
	for(i = 1; i < m; i++)
	{
		total += a[index[i]] - a[index[i]-1] - 1;
	}

	cout<< a[c-1] - a[0] +1 - total;



    return 0;
}
