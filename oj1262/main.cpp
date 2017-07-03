#include <iostream>

using namespace std;

//AC

int slice(int *intime, int *outtime, int low, int high)
{
	int key = intime[low], i = low, j = low+1, tem;
	for(j = low+1;j <= high; j++)
	{
		if(intime[j] < key)
		{
			i++;
			tem = intime[i]; intime[i] = intime[j]; intime[j] = tem;
			tem = outtime[i]; outtime[i] = outtime[j]; outtime[j] = tem;
		}
	}
	tem = intime[low]; intime[low] = intime[i]; intime[i] = tem;
	tem = outtime[low]; outtime[low] = outtime[i]; outtime[i] = tem;
	return i;

}
void quickSort(int *intime, int *outtime, int low, int high)
{
	if(low< high)
	{
		int w = slice(intime, outtime, low, high);
		quickSort(intime, outtime, low, w-1);
		quickSort(intime, outtime, w+1, high);
	}
}

int main()
{
	int n, i, *intime, *outtime;
	cin>>n;
	intime = new int[n];
	outtime = new int[n];
	for(i = 0; i < n ; i++)
	{
		cin>>intime[i]>>outtime[i];
	}
	quickSort(intime, outtime, 0, n-1);

	int maxOccuqied = 0, maxFree = 0, curoccu = 0, curfree = 0, curIn = intime[0], curOut = outtime[0];
	curoccu = curOut - curIn;  maxOccuqied = curoccu;
	long long time = 0;

	for(i = 0; i < n; i++)
	{
		if(intime[i] > curOut)
		{
			curfree =intime[i] - curOut;
			if(maxFree < curfree) maxFree = curfree;
			curoccu = curOut - curIn;
			if(maxOccuqied < curoccu) maxOccuqied = curoccu;

			curOut = outtime[i]; curIn = intime[i];
			continue;
		}

		if(outtime[i]<= curOut) continue;

		if(outtime[i] > curOut)
		{
			curOut = outtime[i];
			continue;
		}

	}

	curoccu = curOut - curIn;
	if(maxOccuqied < curoccu) maxOccuqied = curoccu;


cout<<maxOccuqied<<" "<<maxFree;
    return 0;
}
