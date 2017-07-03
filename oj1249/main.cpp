#include <iostream>
#include <stdio.h>

using namespace std;

//ac
struct fenshu
{
	int fenzi, fenmu;
	float value;
	fenshu(int a, int b):fenzi(a),fenmu(b){value = (float)fenzi/fenmu;}
	fenshu(){}
	fenshu(const fenshu &f){ value = f.value; fenzi = f.fenzi; fenmu = f.fenmu;   }
};

fenshu a[5000];

int slice(int low, int high)
{
	float key = a[low].value; fenshu tem;
	int i = low, j;
	for(j = low+1; j <= high; j++)
	{
		if(a[j].value < key )
		{
			i++;
			tem = a[i]; a[i] = a[j]; a[j] = tem;
		}
	}
	tem = a[low]; a[low] = a[i]; a[i] = tem;
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

int main()
{
    int n, num = 0,x,y, z;
	cin>>n;

	a[num++] = fenshu(0,1);
	a[num++] = fenshu(1,1);
	for(int i = 2; i <= n; i++)
	 {
	 	a[num++] = fenshu(1, i);
	 	for(int j = 2; j < i; j++)
		{
			x = j; y = i;
			while(y != 0)
			{
				z = x % y; x = y; y = z;
			}
			if(x == 1)
				a[num++] = fenshu(j, i);
		}
	 }

	 quickSort(0, num-1);


	for(int i = 0; i < num; i++)
		cout<<a[i].fenzi<<"/"<<a[i].fenmu<<endl;




    return 0;
}
