#include <iostream>

using namespace std;

//AC

int spilt(int *a, int low, int high)
{
	int i = low+1, x = a[low], j, temp;
	for(j = low+1; j <= high; j++)
	{
		if(a[j] > x)
			{
				temp = a[j]; a[j] = a[i]; a[i] = temp;
				i++;
			}
	}
	temp = a[low]; a[low] = a[i-1]; a[i-1] = temp;
	return i;
}

void quickSort(int *a, int low, int high)
{
	if(low < high)
	{
		int w = spilt(a,low,high);
		quickSort(a, low, w-1);
		quickSort(a, w, high);
	}
}

int deleteMutipuly(int *a, int n)
{
	int curN = n;
	for(int i = 0; i < curN-1; i++)
	{
		while(a[i] == a[i+1])
		{
			for(int j = i+1; j < n ; j++) a[j] = a[j+1];
			curN--;

		}
	}

	return curN;
}

int main()
{
	int n, oldN;
	cin>>n; oldN = n;
	int a[10000];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	quickSort(a, 0, n-1);
	do
	{
		oldN = n;
		for(int i = 0; i < oldN; i++)
		{
			for(int j = i+1; j < oldN; j++)
			{
				if(a[j] == 1) continue;
				int qut = a[i] / a[j];
				bool exist = false;
				for(int k = i+1; k <n;k++) if(qut == a[k]) exist = true;
				if(exist) continue;
				a[n] = qut;
				n++;
			}
		}

		quickSort(a, 0, n-1);
		//n = deleteMutipuly(a, n);
		//for(int k = 0; k < n; k++) cout<<a[k]<< " ";cout<<endl;
		//cout<<endl;

	}while(oldN != n);


	cout<<n;

    return 0;
}
