
#include<cstdio>
#include<algorithm>
#define maxn 100000
using namespace std;

//ac

int n,r,q;
int a[maxn*2+100],win[maxn+100],lose[maxn+100];
int s[maxn*2+100],w[maxn*2+100];

bool cmp(int x,int y)
{
  if(s[x]!=s[y])return s[x]>s[y];
  return x<y;
}

bool MAX(int x,int y)
{
  if(s[x]!=s[y])return s[x]>s[y];
  return x<y;
}

void merge()
{
  int i,j,k;
  i=j=1,a[0]=0;
  while(i<=win[0] && j<=lose[0])
    if(MAX(win[i],lose[j]))
      a[++a[0]]=win[i++];
    else
      a[++a[0]]=lose[j++];
  while(i<=win[0])a[++a[0]]=win[i++];
  while(j<=lose[0])a[++a[0]]=lose[j++];
}

int main()
{
  int i,j,k;
  scanf("%d%d",&n, &r);
  for(i=1;i<=2*n;i++)a[i]=i;
  for(i=1;i<=2*n;i++)scanf("%d",&s[i]);
  for(i=1;i<=2*n;i++)scanf("%d",&w[i]);
  sort(a+1,a+2*n+1,cmp);

  for(i=1;i<=r;i++)
    {
      win[0]=lose[0]=0;
      for(j=1;j<=2*n;j+=2)
        if(w[a[j]]>w[a[j+1]])
          {
            s[a[j]]++;
            win[++win[0]]=a[j];
            lose[++lose[0]]=a[j+1];
          }
        else
          {
            s[a[j+1]]++;
            win[++win[0]]=a[j+1];
            lose[++lose[0]]=a[j];
          }
      merge();
    }

for(i = 1; i <= 2*n; i++) printf("%d ", a[i]);

  return 0;
}




/*
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

//tle

int *score, *capb, *index;

int slice(int low, int high)
{
	int key = score[low], i = low, j, tem;
	for(j = low+1; j <= high; j++)
	{
		if(score[j]>key)
		{
			i++;
			tem = score[i]; score[i] = score[j]; score[j] = tem;
			tem = capb[i];  capb[i] =  capb[j];  capb[j] = tem;
			tem = index[i]; index[i] = index[j]; index[j] = tem;
		}

	}
	tem = score[i]; score[i] = score[low]; score[low] = tem;
	tem = capb[i];  capb[i] =  capb[low];  capb[low] = tem;
	tem = index[i]; index[i] = index[low]; index[low] = tem;
	return i;

}

void quickSort(int low, int high)
{
	if(low < high)
	{
		int w = slice(low, high);
		quickSort(low, w-1);
		quickSort(w+1, high);
	}
}


int sliceIndex(int low, int high)
{
	int key = index[low], i = low, j, tem;
	for(j = low+1; j <= high; j++)
	{
		if(index[j]<key )
		{
			i++;
			tem = score[i]; score[i] = score[j]; score[j] = tem;
			tem = capb[i];  capb[i] =  capb[j];  capb[j] = tem;
			tem = index[i]; index[i] = index[j]; index[j] = tem;
		}

	}
	tem = score[i]; score[i] = score[low]; score[low] = tem;
	tem = capb[i];  capb[i] =  capb[low];  capb[low] = tem;
	tem = index[i]; index[i] = index[low]; index[low] = tem;
	return i;

}

void quickSortIndex(int low, int high)
{
	if(low < high)
	{
		int w = sliceIndex(low, high);
		quickSortIndex(low, w-1);
		quickSortIndex(w+1, high);
	}
}

void handleIndex(int n)
{
	int i, j = 1, cur = score[1];

	for(i = 1; i <= 2*n; i++)
	{
		if(cur != score[i])
		{
			quickSortIndex(j, i-1);
			cur = score[i];
			j= i;
		}
	}
	quickSortIndex(j, 2*n);
}


int main()
{
    int n,r,i,j;
    cin>>n>>r;
    score = new int[2*n+1];
    capb = new int[2*n+1];
    index = new int[2*n+1];
    for(i = 1; i <= 2*n; i++)
		scanf("%d", &score[i]);
	for(i = 1; i <= 2*n; i++)
		scanf("%d", &capb[i]);
	for(i = 1; i <= 2*n; i++)
		index[i] = i;

	for(i = 0; i < r; i++)
	{
		quickSort(1, 2 * n);
		handleIndex(n);
		for(j = 1; j <=2*n; j+=2)
		{
			if(capb[j]>capb[j+1])
				score[j]++;
			else
				score[j+1]++;
		}
	}
	quickSort(1, 2 * n);
	handleIndex(n);
	for(i = 1; i <=2* n; i++) cout<<index[i]<<" ";

    return 0;
}
*/
