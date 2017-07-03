#include <iostream>

using namespace std;

//AC

int jump(char **a, int x, int y,char color, int r, int c)
{
	if(x == r-1 and y == c-1) return 1;
	else if(x == r-1 or y == c-1) return 0;
	else if(x < r-1 and y < c-1)
	{
		int total = 0;
		for(int i = x+1; i < r; i++)
			for(int j = y+1; j < c;j++)
		{
			if(a[i][j] != color)
				total += jump(a,i,j,a[i][j],r,c);
		}

		return total;
	}
}



int main()
{
	int r,c, i, j;
	char **a;
	cin>>r>>c;
	a = new char*[r];
	for(i = 0; i <r; i++) a[i] = new char[c];
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			cin>>a[i][j];

	cout<<jump(a,0,0,a[0][0],r,c);



    return 0;
}
