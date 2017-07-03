#include <iostream>

using namespace std;

void Merge(int data[], int a, int b, int length, int n)
{

}



















int partion(int a[], int low, int high)
{
	int key = a[low], i = low, j = low+1;
	for(j = low+1; j <= high; j++)
	{
		if(a[j] < key)
		{
			i++;
			int tem = a[i]; a[i] = a[j]; a[j] = tem;
		}

	}
	int tem = a[i]; a[i] = a[low]; a[low] = tem;
	return i;
}

void quickSort(int a[], int low, int high)
{
	if(low<high)
	{
		int w = partion(a, low, high);
		quickSort(a, low, w -1);
		quickSort(a, w+1, high);
	}
}

int main()
{
	int t;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin>>n;
		int *a = new int[n];
		for(int j = 0; j < n; j++)
		{
			cin>>a[j];
		}
		quickSort(a, 0, n - 1);

		for(int j = 0; j < n; j++)
		{
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}


    return 0;
}
