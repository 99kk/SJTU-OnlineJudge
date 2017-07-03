#include <iostream>

using namespace std;

template<class elem>
class linkQueue
{
private:
	struct node
	{
		elem data;
		node *next;
		node(elem x):data(x),next(NULL){}
	};
	node *head, *tail;

public:
	linkQueue(){head = tail = NULL;}

	void enQueue(const elem &x)
	{
		if(head == NULL) head = tail = new node(x);
		else
		{
			node *tem = new node(x);
			tail->next = tem;
			tail = tem;
		}
	}

	elem deQueue()
	{
		node *p = head;
		head = head->next;
		return p->data;
	}
	bool isEmpty(){ return head == NULL; }
	int top() { return head->data; }
	void print()
	{
		node *p = head;
		while(p != NULL)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}

};



class Tree
{
private:
struct node
	{
		int data;
		node *dad;
		node **sons;
		int sonNum;
		int maxSons;
		node(int x):data(x),dad(NULL),sonNum(0)
			{
				maxSons = 20;
				sons = new node*[maxSons+1];
				for(int i = 1; i <= maxSons; i++) sons[i] = NULL;
			}
	};
	node *root;

	void doubleSons(node *cur)
	{
		cur->maxSons = cur->maxSons * 2;
		node **tem = cur->sons;
		cur->sons = new node*[cur->maxSons + 1];
		for(int i =1; i <= cur->sonNum; i++) cur->sons[i] = tem[i];
		for(int i = cur->sonNum +1; i <= cur->maxSons; i++) cur->sons[i] = NULL;
	}

class priorityQueueForNode
{
private:
	int maxSize, curSize;
	node **a;

	void doubleSize()
	{
		maxSize *= 2;
		node **tem = a;
		a = new node *[maxSize+1];
		for(int i = 1; i <= curSize; i++) a[i] = tem[i];
	}
public:
	priorityQueueForNode(int cap = 20){maxSize = cap; curSize = 0; a = new node*[maxSize+1]; }
	void enQueue( node *x)
	{
		int hole = ++curSize;
		if(curSize >= maxSize - 1) doubleSize();
		for(; hole >1 and x->data < a[hole/2]->data; hole/=2)
			a[hole] = a[hole/2];
		a[hole] = x;
	}

	node* deQueue()
	{
		node* minItem = a[1];
		a[1] = a[curSize--];
		down(1);
		return minItem;
	}
	void down(int hole)
	{
		int child;
		node* tem = a[hole];
		for(; hole * 2 <= curSize; hole = child)
		{
			child = hole * 2;
			if(child != curSize and a[child+1]->data < a[child]->data) child++;
			if(a[child]->data < tem->data) a[hole] = a[child];
			else break;
		}
		a[hole] = tem;
	}

	node* top() { return a[1]; }

	int getCurSize(){return curSize;}

	bool isEmpty(){return curSize == 0;}

	void print()
	{
		for(int i = 1; i <= curSize; i++)
		{
			cout<<a[i]->data<<" ";
		}
		cout<<endl;
	}

};




	node* makeTree(linkQueue<int> &q, node* father)
	{
		node *tem;
		q.deQueue();
		tem = new node(q.deQueue());
		tem->dad = father;
		while(true)
		{
			if(q.top() == -1)
			{
				tem->sonNum += 1;
				if(tem->sonNum == tem->maxSons - 1) doubleSons(tem);
				tem->sons[tem->sonNum] = makeTree(q, tem);
			}
			if(q.top() == -2)
			{
				q.deQueue();
				break;
			}
		}
		return tem;

	}

public:
	Tree(){root = NULL;}
	void makeTree(linkQueue<int> &q)
	{
		q.deQueue();
		root = new node(q.deQueue());
		root->dad = NULL;
		while(true)
		{


			if(q.top() == -1)
			{
				root->sonNum += 1;
				if(root->sonNum == root->maxSons - 1) doubleSons(root);
				root->sons[root->sonNum] = makeTree(q, root);
			}
			if(q.top() == -2)
			{
				q.deQueue();
				break;
			}
		}
	}

	void print()
	{
		linkQueue<node*> q; node*tem;

		if(root != NULL)	q.enQueue(root);
		while(!q.isEmpty())
		{
			tem = q.deQueue();
			for(int i = 1; tem->sons[i] != NULL; i++ )
				q.enQueue(tem->sons[i]);
			cout<<tem->data<<" ";
		}
		cout<<endl;
	}

	void outputMinLeafsFather()
	{
		priorityQueueForNode priQueueForNode;
		linkQueue<node*>q; node *tem;
		int n = 0;
		if(root != NULL) q.enQueue(root);
		while(!q.isEmpty())
		{
			tem = q.deQueue(); n++;
			for(int i = 1; tem->sons[i] != NULL; i++ )
				q.enQueue(tem->sons[i]);
			if(tem->sonNum == 0) priQueueForNode.enQueue(tem);
		}

		for(int i = 1; i < n-1; i++)
		{
			tem = priQueueForNode.deQueue();
			tem->dad->sonNum--;
			if(tem->dad->sonNum == 0  and tem->dad != NULL) priQueueForNode.enQueue(tem->dad);
			cout<<tem->dad->data<<" ";
		}

		tem = priQueueForNode.deQueue();
		//cout<<tem->data;
		if(tem->data > root->data) cout<<tem->data<<" ";
		else
			cout<< root->data<<" ";
	}

};

int main()
{
    char c;
    int x = 0;
    linkQueue<int> q;

    while(true)
	{
		cin.get(c);
		if(c == ' ') continue;
		if(c == '\n') break;

		if(c >= '0' and c <= '9')
		{
			x = 0;
			while(true)
			{
				if(c < '0' or c > '9') break;
				x = x * 10 + c - '0';
				cin>>c;
			}
			q.enQueue(x);
		}
		if(c == '(') {q.enQueue(-1);continue;}
		if(c == ')') {q.enQueue(-2); continue; }
	}


	Tree tree;
	tree.makeTree(q);

	tree.outputMinLeafsFather();


    return 0;
}







