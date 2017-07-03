#include <iostream>

using namespace std;

//path 长度为M的简单路径个数
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
		edgeNode *head;;
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

		verList = new verNode[vSize];
		for(int i = 0; i < Vers;i++)
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



	int dfs(int start, int M) const
	{

		bool *visited = new bool[Vers];
		int i;
		for( i = 0; i < Vers; i++) visited[i] = false;
		int num = 0, curLen = 0;
		dfs(start, visited, num, M, curLen);
		return num;
	}
private:
	void dfs(int start, bool visited[], int &num, int M, int &curLen) const
	{
		edgeNode *p = verList[start].head;


		//cout<<verList[start].ver<<" ";
		if(curLen == M)
		{
			//curLen--;
			num++;
			return;}

		visited[start]=  true;

		//if(p != NULL) num--;
		while(p != NULL)
		{	int tem = curLen;
			if(!visited[p->end]) { curLen++; dfs(p->end, visited, num,	M, curLen); }
			p = p->next;
			curLen = tem;
		}
		visited[start] = false;

	}


};







int main()
{
    int n, m, start, M, i, j, u, v;
    cin>>n>>m>>start>>M;
    int *a = new int[n+1];
    for(i = 0; i < n; i++)
		a[i] = i;

    adjListGraph<int, int> g(n, a);

    for(i = 0; i < m; i++)
	{
		cin>>u>>v;
		g.insert(u-1, v-1, 1);
	}

    cout<<g.dfs(start-1, M);


    return 0;
}
