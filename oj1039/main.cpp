#include <iostream>

using namespace std;

//AC
void postOrder(int node,  int *leftson, int *rightson)
{
	if(leftson[node] != -1) postOrder(leftson[node], leftson, rightson);
	if(rightson[node] != -1) postOrder(rightson[node], leftson, rightson);
	cout<<node<<" ";
}


int main()
{
    int n, i, *pos, x , y, z, curpos, *leftson, *rightson;
    cin>>n;
    pos = new int[n+1];
    leftson = new int[n+1]; rightson = new int[n+1];
    pos[1] = 1;
    for(i = 0; i < n; i++)
	{
		cin>>x>>y>>z;
		curpos = pos[x];
		if(y >0) pos[y] = curpos * 2;
		if(z > 0) pos[z] = curpos * 2 +1;

		leftson[x] = y;
		rightson[x] = z;

	}



	for(i = 1; i <= n; i++) cout<<pos[i]<<" ";
	cout<<endl;


	postOrder(1, leftson, rightson);

    return 0;
}
