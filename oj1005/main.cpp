#include <iostream>

using namespace std;

struct sudoku{
	int a[9][9];
};

int main()
{
    int n, i, j, k;
    cin>>n;
    sudoku *shudo = new sudoku[n];
    bool *res = new bool[n];
    for(k = 0; k < n; k++)
	{
		for(i = 0; i <9 ; ++i)
			for(j = 0; j < 9; j++)
		{
			cin>>shudu[k].a[i][j];
		}



	}





    return 0;
}
