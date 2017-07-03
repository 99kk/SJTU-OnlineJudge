#include <iostream>
#include <stdio.h>

using namespace std;

//ac
struct edge
	{
		int beg, end;
		int w;
		bool operator<(const edge &rp)const {return w < rp.w;}
	};


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

	class disJoinSet
{
private:
	int size;
	int *parent;
public:
	disJoinSet(int s)
	{
		size = s;
		parent = new int[size];
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
};


template<class elemType>
class priorityQueue
{
private:
	int curSize, maxSize;
	elemType *a;

	void doubleSpace()
	{
		maxSize *= 2;
		elemType *tem = a;
		a = new elemType[maxSize+1];
		for(int i = 1; i <= curSize; i++) a[i] = tem[i];
	}

	void percolateDown(int hole)
	{
		int child;
		elemType tem = a[hole];
		for(; hole * 2 <= curSize; hole = child)
		{
			child = hole*2;
			if(child != curSize and a[child+1] < a[child]) child++;
			if(a[child] < tem) a[hole] = a[child];
			else break;
		}
		a[hole] = tem;
	}
public:
	priorityQueue()
	{
		curSize = 0; maxSize = 20;
		a = new elemType[maxSize+1];
	}

	priorityQueue(const elemType *item, int s)
	{
		maxSize = s + 20; curSize = s;
		a = new elemType[maxSize];
		for(int i = 1; i <= curSize; i++) a[i] = item[i];
		buildHeap();
	}

	bool isEmpty()const {return curSize == 0;}

	void enQueue(const elemType &x)
	{
		if(curSize+1 == maxSize) doubleSpace();
		int hole = ++curSize;
		for(;hole>1 and x < a[hole/2]; hole/=2)
			a[hole] = a[hole/2];
		a[hole] = x;
	}

	elemType deQueue()
	{
		elemType tem = a[1];
		a[1] = a[curSize--];
		percolateDown(1);
		return tem;
	}
	void buildHeap()
	{
		for(int i = curSize/2; i >0; i--)
			percolateDown(i);
	}
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

private:



public:
	int kruskal() const
	{
		int weights = 0;
		int edgeAccepted = 0, u, v;
		edgeNode*p;
		edge e;
		disJoinSet ds(Vers);
		priorityQueue<edge> pq;
		int i;
		for(i = 0 ; i < Vers; i++)
			for(p = verList[i].head; p != NULL; p = p->next)
				//if(i < p->end)
			{
				e.beg = i;
				e.end = p->end;
				e.w = p->weight;
				pq.enQueue(e);
			}

		while(edgeAccepted < Vers -1)
		{
			e = pq.deQueue();
			u = ds.Find(e.beg);
			v = ds.Find(e.end);

			if(u != v)
			{
				edgeAccepted++;
				ds.Union(u, v);
				weights += e.w;

				//cout<<verList[e.beg].ver<<"--"<<verList[e.end].ver<<"  "<<e.w<<endl;
			}

		}
		return weights;
	}


};




int main()
{
    int n, m, i, a, b, p;
    cin>>n>>m;

    adjListGraph<int, int> g(n);

    for(i = 0; i < m; i++)
    {
    	//cin>>a>>b>>p;
    	scanf("%d%d%d", &a, &b, &p);
    	g.insert(a-1,b-1,p);
    }
	cout<<g.kruskal();


    return 0;
}
