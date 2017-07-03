#include <iostream>

using namespace std;

int a[6][6],totalCost , state, cost, xStart, yStart, xEnd, yEnd , dis[6][6];

bool visited[6][6];
bool finish;

void findMinCost(int x, int y)
{
	if(x == xEnd and y == yEnd) {finish = true; return;}

	visited[x][y] = true;

	if(!finish and y + 1 < 6 and !visited[x][y+1])
	{
		int s = state, c = cost, t = totalCost;
		cost = state * a[x][y+1];
		state = (cost % 4) + 1;
		if(dis[x][y+1] > dis[x][y] + cost)
		{
			dis[x][y+1] = dis[x][y] + cost;
			findMinCost(x, y+1);
		}
	}

}

int main()
{
    int n, i,j, k;
    cin>>n;
    for(k = 0; k < n; k++)
	{
		state = 1; totalCost = 0; cost = 0; finish = false;
		for(i = 0; i < 6; i++)
			for(j = 0; j < 6; j++)
			{cin>>a[i][j];visited[i][j] = false;dis[i][j] = 2100000000;}

		cin>>xStart>>yStart>>xEnd>>yEnd;



	}



    return 0;
}
