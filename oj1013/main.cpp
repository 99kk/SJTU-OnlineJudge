#include <iostream>

using namespace std;

// infinite Knapsack problem

int V,N,*c,*w, value[10001];

int main()
{
	int i,j;
    cin>>V>>N;
    c = new int[N]; w = new int[N];
    for(i = 0; i< N; i++)
	{
		cin>>c[i]>>w[i];
	}
	for(j = 0; j <= V; j++)
		value[j] = 0;

	for(i = 0; i < N; i++)
		for(j = c[i]; j <= V; j++)
	{
		value[j] = max(value[j], value[j-c[i]]+ w[i]);
	}

	cout<<value[V]<<endl;







    return 0;
}
