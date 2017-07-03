#include <iostream>

using namespace std;

//ac

class graph
{
private:
	bool a[101][101];
	int n;
public:
	graph(int _n)
	{
		n = _n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				a[i][j] = false;
	}

	void insert(int u, int v)
	{
		a[u][v] = true;
		a[v][u] = true;
	}

	void func()
	{
		if(n < 2)
		{
			cout<<"NO ODD SUBGRAPH"<<endl;
			return;
		}

		bool  allOdd = true;
		int  temCount;
		int i, j;
		for(i = 1; i <= n; i++)
		{
			temCount = 0;
			for(j = 1; j <= n; j++ )
			{
				if(a[i][j]) temCount++;
			}
			if(temCount % 2 == 0)
			{ allOdd = false; }
		}


		if(allOdd)
		{
			cout<<"ODD GRAPH"<<endl;
			return;
		}

		for(i = 1; i <= n; i++)
			for(j = i+1; j <= n; j++)
				if(a[i][j])
				{
					cout<<"2 "<<i<<" "<<j<<endl;
					return;
				}

		cout<<"NO ODD SUBGRAPH"<<endl;

	}

};


int main()
{
    int t, m,n,u,v;
    cin>>t;
    int i, caseI;
    for(caseI = 0;  caseI < t; caseI++)
	{

		cin>>n>>m;
		graph g(n);
		for(i = 0; i < m; i++)
		{
			cin>>u>>v;
			g.insert(u,v);
		}

		g.func();



	}


    return 0;
}
