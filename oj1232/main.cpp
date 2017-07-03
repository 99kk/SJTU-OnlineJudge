#include <iostream>
#include <stdio.h>

using namespace std;

//ac

int n ,a, b;


class disJoinSet
{
private:
	int size;
	int *parent;
public:
	disJoinSet()
	{

	}


	void setSize(int s)
	{
		size = s;
		parent = new int[size+1];
		for(int i = 0 ; i < size; i++)
		{
			parent[i] = -1;
		}
	}

	void Union(int root1, int root2)
	{
		if(root1 == root2) return;
		if(parent[root1]>parent[root2])
		{
			parent[root2] += parent[root1]; parent[root1] = root2;
		}
		else
		{
			parent[root1] += parent[root2]; parent[root2] = root1;
		}
	}

	int Find(int x)
	{
		if(parent[x] < 0) return x;
		return parent[x] = Find(parent[x]);
	}

	void print()
	{
		int i;
		for(i = 0; i < size; i++)
			cout<<parent[i]<<"\t";
		cout<<endl;
		for(i = 0; i < size; i++)
			cout<<i<<"\t";
		cout<<endl;
	}


};

disJoinSet ds;



template <class elemType>
class linkStack
{
private:
	struct node
	{
		elemType data;
		node *next;
		node(const elemType &x, node* N = NULL)
		{
			data = x; next = N;
		}
		node():next(NULL){}
		~node(){}
	};
	node *element;

public:
	linkStack(){element = NULL;}


	bool isEmpty() {return element == NULL;}

	void push(const elemType &x) {node *tem = new node(x, element); element = tem;}

	elemType pop()
	{
		node *tem = element;
		elemType x = element->data;
		element  = element->next;
		return x;
	}
	elemType top() const {return element->data;}
};



bool trans(int x, int dir, int &y)
{
	int  row = 1, col;

	while(x > row )
	{

		x -= row;
		row++;
	}
	col = x;


	switch(dir)
	{
	case 0: row--; col--;
		break;
	case 1: row--;
		break;
	case 2: row++;
		break;
	case 3: row++; col++;
		break;
	}

	if(row < 1 or row > n or col <1 or col > row ) return false;

	y = row * (row - 1) /2 + col;
	return true;
}

bool *visited;
bool **martrix;

void findPath(int x, linkStack<int> &s, bool &finish)
{

	if(x == b) finish = true;
	s.push(x);visited[x] = true;

	int y;
	for(int i = 0; i < 4; i++)
		if(!finish and trans(x, i, y))
		{
			if(!visited[y] and ds.Find(x-1) == ds.Find(y-1) and martrix[x][y])
			{
				findPath(y, s, finish);
				if(!finish) {s.pop(); visited[y] = false;}
			}
		}



}



int main()
{
    int  p, q,pp;
    cin>>n>>a>>b;

	ds.setSize(n*(n+1)/2);
	visited = new bool[n*(n+1)/2+1];
	martrix = new bool*[n*(n+1)/2+1];

	for(int i = 1; i <=n*(n+1)/2; i++ )
		{
			visited[i] = false;
			martrix[i] = new bool[n*(n+1)/2+1];
			for(int j = 1; j <= n*(n+1)/2; j++)
				martrix[i][j] = false;
		}


	while(ds.Find(a-1) != ds.Find(b-1))
	{

		scanf("%d%d", &p, &q);
		if(trans(p, q, pp))
			{
				ds.Union(ds.Find(p-1), ds.Find(pp-1));
				martrix[p][pp] = true;
				martrix[pp][p] = true;
			}

	}


	linkStack<int> stk, sout;
	bool finish = false;
	findPath(a, stk, finish);

	while(!stk.isEmpty())
	{
		sout.push(stk.pop());
	}

	while(!sout.isEmpty())
	{
		cout<<sout.pop()<<" ";
	}

    return 0;
}
