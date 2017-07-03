#include <iostream>
#include <stdio.h>

using namespace std;



template <class elemType>
class linkQueue
{
private:
	struct node
	{
		elemType data;
		node* next;
		node(const elemType &x, node*p = NULL) {data = x; next = p;}
		node():next(NULL){}
		~node(){}
	};
	node *head;
	node *tail;

public:
	linkQueue(){head = tail = NULL;}

	bool isEmpty(){return head == NULL;}

	void enQueue(const elemType &x)
	{
		if(tail == NULL) head = tail = new node(x);
		else
		{
			node *p = new node(x);
			tail->next = p;
			tail = tail->next;
		}
	}

	elemType deQueue()
	{
		node *tem = head;
		elemType x = head->data;
		head = head->next;
		if(head == NULL) tail = NULL;
		delete tem;
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


	struct edge
	{
		int beg, end;
		int w;
		bool operator<(const edge &rp)const {return w < rp.w;}
	};



template<class TypeOfVer, class TypeOfEdge>
class adjListGraph
{
private:
	struct edgeNode
	{
		int end;
		TypeOfEdge weight;
		edgeNode *next;
		edgeNode(int e, TypeOfEdge w, edgeNode *p = NULL)
		{
			end = e; weight = w; next = p;
		}
	};

	struct verNode
	{
		TypeOfVer ver;
		edgeNode *head;;
		verNode(edgeNode *h = NULL)
		{
			head = h;
		}
	};

	verNode *verList;
	int Vers, Edges;

public:
	adjListGraph(int vSize)
	{
		Vers = vSize; Edges = 0;

		verList = new verNode[vSize];
		for(int i = 0; i < Vers;i++)
			verList[i].ver = i;
	}

	bool insert(int u, int v, TypeOfEdge w)
	{
		verList[u].head = new edgeNode(v, w, verList[u].head);
		++Edges;
		return true;
	}

	bool remove(int u, int v)
	{
		edgeNode *p = verList[u].head, *q;
		if(p == NULL) return false;
		if(p->end == v)
		{
			verList[u].head = p->next;
			delete p;
			--Edges;
			return true;
		}

		while(p->next != NULL and p->next->end != v) p = p->next;
		if(p->next == NULL) return false;
		q = p->next; p->next = q->next; delete q;
		--Edges;
		return true;
	}

	bool exist(int u, int v)
	{
		edgeNode * p = verList[u].head;
		while(p != NULL and p->end != v) p = p->next;
		if(p == NULL) return false;
		else return true;
	}




	void shortestPath(int start, int ending)
	{
		int *dis = new int[Vers];
		TypeOfVer *prev = new TypeOfVer[Vers];

		linkQueue<TypeOfVer> q;
		int i;

		for(i = 0; i < Vers; i++)
			dis[i] = 2100000000;

		dis[start] = 0;

		q.enQueue(start);
		TypeOfVer v, w;
		edgeNode *p;
		while(!q.isEmpty())
		{
			v = q.deQueue();
			for(p = verList[v].head; p != NULL; p = p->next)
			{
				if(dis[v] + p->weight < dis[p->end])
				{
					dis[p->end] = dis[v] + p->weight;
					prev[p->end] = v;
					q.enQueue(p->end);
				}
			}
		}

		cout<<dis[ending];


	}


};






int main()
{
	int n, m,endPnt , startPnt, i, j, a, b, p;
	cin>>n>>m>>startPnt>>endPnt;

	adjListGraph<int, int> g(n);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &p);
		g.insert(a-1, b-1, p);
	}
	g.shortestPath(startPnt-1, endPnt-1);


    return 0;
}
