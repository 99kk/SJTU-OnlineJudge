#include <iostream>

using namespace std;
// AC
int main()
{
    int l, w, i, j, k, a, b, m = 0, cur = 0;
    cin>>l>>w;
    int **A = new int*[l+1];
    for(i = 0; i < l+1; i++)
		A[i] = new int[w+1];

	for(i = 0; i < l; i++)
	{A[i][0] = 0; A[0][i] = 0;}

    for(i = 1; i <= l; i++)
		for(j = 1;j <= w; j++)
		{
			cin>>A[i][j];
			A[i][j] = A[i][j] + A[i][j-1] + A[i-1][j] - A[i-1][j-1];
		}

	cin>>a>>b;

	for(i = a; i <= l; i++)
		for(j = b; j <=w; j++)
	{
		cur = A[i][j] - A[i-a][j]  - A[i][j-b] + A[i-a][j-b];
		if(m < cur)m = cur;
	}


	cout<<m;
    return 0;
}

