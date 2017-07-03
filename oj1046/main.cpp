#include <iostream>
#include <stdio.h>

using namespace std;

//ac

template<class elemType>
class linkStack
{
private:
	struct node
	{
		elemType data;
		node* next;
		node(const elemType &x, node*p = NULL) {data = x; next = p;}
		node():next(NULL){}
	};
	node *head;

public:
	linkStack(){head = NULL;}

	bool isEmpty(){return head == NULL;}

	void push(const elemType &x)
	{
			node *p = new node(x);
			p->next = head;
			head = p;
	}

	elemType pop()
	{
		elemType x = head->data;
		head = head->next;
		return x;
	}

	elemType getHead(){return head->data;}

	void print()
	{
		node*p=head;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
};

void  midOrder(int t, int *leftChildren, int* rightChildren, int &y, int *mid, int *start, int *ending)
{
	start[t] = y+1;
	if(leftChildren[t] != 0) midOrder(leftChildren[t], leftChildren, rightChildren, y, mid, start,ending);
	y++; mid[y] = t;
	if(rightChildren[t]!= 0) midOrder(rightChildren[t], leftChildren, rightChildren, y, mid, start, ending);
	ending[t] = y;
}


int main()
{
    int n, p, q, i, j;
    cin>>n>>p>>q;

	int *leftChildren = new int[n+1], *rightChildren = new int[n+1], *red = new int[n+1], *findRoot = new int[n+1];

	for( i = 1; i <= n; i++) {red[i] = 0;findRoot[i] = 0;}
	int root , l, r;
	for( i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &root, &l, &r);
		//cin>>root>>l>>r;
		leftChildren[root] = l;
		rightChildren[root] = r;
		findRoot[l] = 1; findRoot[r] = 1;
	}

	int t, x, cur, *popTimes = new int[n+1], y = 0, *mid = new int[n+1], index = 1, rootNode = 0;
	int *start = new int[n+1], *ending = new int[n+1];
	for(i = 1; i <= n; i++) { if(findRoot[i] == 0) rootNode = i;}
	midOrder(rootNode, leftChildren, rightChildren, y, mid, start, ending);

	linkStack<int> s;

	for(i = 1; i <= p; i++)
	{


		scanf("%d%d", &t, &x);

		red[ mid[ start[t] + x % (ending[t] - start[t]+1)  ] ] = 1;

		//cin>>t>>x;

/*
		s.push(t);

		while(!s.isEmpty())
		{
			cur = s.pop();
			if(++popTimes[cur] == 2)
			{
				y++;
				mid[index] = cur;
				index++;
				if(rightChildren[cur] != 0)
					s.push(rightChildren[cur]);
			}
			else
			{
				s.push(cur);
				if(leftChildren[cur] != 0)
					s.push(leftChildren[cur]);
			}
		}
*/

		//midOrder(t, leftChildren, rightChildren, y, mid, index);
		//red[mid[x % y +1]] = 1;
	}


	int w, redNum = 0; int *redNodes = new int[n+1];
	for(i = 1; i <= n; i++) redNodes[i] = 0;
	for(i = 1; i <= q; i++)
	{
		scanf("%d", &w);
		//cin>>w;
		if(redNodes[w] != 0) {printf("%d\n", redNodes[w]); continue;}
		redNum = 0;


		s.push(w);
		while(!s.isEmpty())
		{
			cur = s.pop();
			if(red[cur] == 1) redNum++;
			if(leftChildren[cur] != 0) s.push(leftChildren[cur]);
			if(rightChildren[cur] != 0) s.push(rightChildren[cur]);
		}

		redNodes[w] = redNum;

		printf("%d\n", redNum);
	}

    return 0;
}
