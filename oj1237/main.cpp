#include <iostream>

using namespace std;

//courses, Õÿ∆À≈≈–Ú
//ac

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
		edgeNode *head;
		verNode(edgeNode *h = NULL)
		{
			head = h;
		}
	};

	verNode *verList;
	int Vers, Edges;

public:
	adjListGraph(int vSize, const TypeOfVer d[])
	{
		Vers = vSize; Edges = 0;

		verList = new verNode[vSize+1];
		for(int i = 1; i <= Vers;i++)
			verList[i].ver = d[i];
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


	void topSort() const
	{
		linkQueue<int> q, q2;
		edgeNode *p;
		int  i;
		int *inDegree = new int[Vers+1];

		for(i = 1; i <= Vers; i++) inDegree[i] = 0;

		for(i = 1 ; i <= Vers; i++)
		{
			for(p = verList[i].head; p != NULL; p = p->next)
				++inDegree[p->end];
		}

		for(i = 1; i <= Vers; i++)
			if(inDegree[i] == 0) q.enQueue(i);

		int maxTerms = 1, curNode;

		while(!q.isEmpty() )
		{

			curNode = q.deQueue();

			for(p = verList[curNode].head; p != NULL; p = p->next)
				if(--inDegree[p->end] == 0 ) {q2.enQueue(p->end);  }

			if(q.isEmpty())
			{
				if(!q2.isEmpty()) maxTerms++;
				while(!q2.isEmpty())
					q.enQueue(q2.deQueue());

			}

		}

		cout<<maxTerms;
		cout<<endl;
	}


};






int main()
{
    int n, m, *a, i, u, v;
    cin>>n>>m;
	a = new int[n+1];
	for(i = 1 ; i <= n; i++)
		a[i] = i;

	adjListGraph<int, int> course(n, a);

	for(i = 0; i < m; i++)
	{
		cin>>u>>v;
		course.insert( v,u,  1);
	}

	course.topSort();



    return 0;
}
