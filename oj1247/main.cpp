#include <iostream>

using namespace std;

//ac

int main()
{
    int l, m, i, j , k ,x, y;
    cin>>l>>m;
    bool *a = new bool[l+1];
    for(i = 0; i <= l; i++)
		a[i] = true;
    for(i = 0; i < m; i++)
	{
		cin>>x>>y;
		for(j = x; j <= y; j++)
			a[j] = false;
	}

	int count = 0;
    for(i = 0; i <= l; i++)
		if(a[i])
			count++;

	cout<<count<<endl;
    return 0;
}
