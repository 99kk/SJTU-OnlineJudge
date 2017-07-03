#include <iostream>

using namespace std;
//AC
int main()
{
	int i,j, l, m = 0;
	cin>>l;
	int **a = new int*[l];
	for(i = 0; i < l; i++)
		a[i] = new int[l];

	int**contract = new int*[l];
	for(i = 0; i < l; i++)
		contract[i] = new int[l];

	for(i = 0; i < l; i++)
		for(j = 0; j < l; j++)
			{
				cin>>a[i][j];
				contract[i][j] = a[i][j];
			}

	bool flag = true;
	while(flag)
	{
		flag = false;
		for(i = 0; i < l; i++)
			for(j = 0; j < l; j++)
				{

					if(a[i][j] == 1 and contract[i][j] == 1)
					{
						if(i+1 < l and a[i+1][j] == 0)  {a[i+1][j] = 1;flag = true;}
						if(i-1 >= 0 and a[i-1][j] == 0) {a[i-1][j] = 1;flag = true;}
						if(j-1 >= 0 and a[i][j-1] == 0) {a[i][j-1] = 1;flag = true;}
						if(j+1 < l and a[i][j+1] == 0) {a[i][j+1] = 1;flag = true;}
					}
				}
		if(flag) ++m;
		for(i = 0; i < l; i++)
			for(j = 0; j < l; j++)
				contract[i][j] = a[i][j];

	}

    cout << m << endl;
    return 0;
}
