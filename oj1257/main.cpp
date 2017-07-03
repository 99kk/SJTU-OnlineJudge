#include <iostream>
#include <stdio.h>
using namespace std;

//ac

class linkStack
{
private:
	struct node
	{
		int data;
		node *next;
		node(const int &x):data(x), next(NULL){}
	};
	node *head, *tail;
public:
	linkStack()
	{
		head = NULL;
	}
	bool isEmpty(){ return head ==NULL; }

	void push(const int &x)
	{
		if(head == NULL) head  = new node(x);
		else
		{
			node *tem = new node(x);
			tem->next = head;
			head = tem;
		}
	}

	int pop()
	{
		int tem = head->data;
		head = head->next;
		return tem;
	}
};

int main()
{
    int m, op, a, b, c, i, j, *node, *leftSon, *rightSon, *father, tem, temFather;
    cin>>m;
    node =     new int[100001];
    leftSon =  new int[100001];
    rightSon = new int[100001];
    father =   new int[100001];

    for(i = 0; i < 100001; i++)
	{
		node[i] = 0; leftSon[i] = 0; rightSon[i] = 0; father[i] = 0;
	}
    node[1] = 1;


    for(i = 0; i < m ;i++)
	{
		scanf("%d", &op);
		switch(op)
		{
		case 1:
			scanf("%d%d%d", &a,&b,&c);
			if(node[a] == 0 or b == c or node[b] != 0 or node[c] != 0 or leftSon[a] != 0) printf("Error!\n");
			else
			{
				printf("Ok!\n");
				node[b] = 1; node[c] = 1; leftSon[a] = b; rightSon[a] = c; father[b] = a; father[c] = a;
			}
			break;
		case 2:
			scanf("%d", &a);
			if(node[a] == 0) printf("Error!\n");
			else
			{
				printf("%d %d %d\n",father[a],leftSon[a],rightSon[a] );
			}
			break;
		case 3:
			scanf("%d", &a);
			if(node[a] == 0 or a== 1) printf("Error!\n");
			else
			{
				temFather = father[a];
				tem = leftSon[temFather]; leftSon[temFather] = rightSon[temFather]; rightSon[temFather] = tem;

				printf("%d\n", ((tem == a)? leftSon[temFather]:rightSon[temFather]));
			}
			break;
		}
	}

	linkStack q; int x;
	q.push(1);
	while(!q.isEmpty())
	{
		x = q.pop();
		printf("%d ", x);
		if(rightSon[x] != 0) q.push(rightSon[x]);
		if(leftSon[x] != 0) q.push(leftSon[x]);
	}




    return 0;
}
