#include <iostream>

using namespace std;

// sudoku
// brute force
//ac

int main()
{
    int i, j, k, n, x, y, z, a[9][9];
    bool col[9], row[9], grid[3][3], check[10], flag = true;
    cin>>n;
    for(i = 0; i < n; i++)
	{
		for(j = 0; j < 9; j++)
			for(k= 0; k < 9; k++)
				cin>>a[j][k];
		flag = true;


		for(j = 0; j < 9; j++)
		{
			for(k = 1; k <= 9; k++)
				check[k] = false;
			for(k = 0; k < 9; k++)
				check[a[j][k]] = true;
			for(k = 1; k <= 9; k++)
				if(!check[k])
					flag = false;
		}
		if(!flag)
		{
			cout<<"Wrong"<<endl;
			continue;
		}

		for(j = 0; j < 9; j++)
		{
			for(k = 1; k <= 9; k++)
				check[k] = false;
			for(k = 0; k < 9; k++)
				check[a[k][j]] = true;
			for(k = 1; k <= 9; k++)
				if(!check[k])
					flag = false;
		}
		if(!flag)
		{
			cout<<"Wrong"<<endl;
			continue;
		}

		for(j = 0; j < 3; j++)
			for(k = 0; k < 3; k++)
		{
			for(x = 1; x <= 9; x++)
				check[x] = false;
			for(x = 0; x < 3; x++)
				for(y = 0; y < 3; y++)
			{
				check[a[3*j+x][3*k+y]] = true;
			}
			for(x = 1; x <= 9; x++)
				if(!check[x])
					flag = false;
		}
		if(!flag)
		{
			cout<<"Wrong"<<endl;
			continue;
		}

		cout<<"Right"<<endl;

	}


    return 0;
}
