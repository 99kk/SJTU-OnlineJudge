#include <iostream>

using namespace std;

//AC

template<class elemType>
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
		~node(){}
	};
	node *head;
	node *tail;

public:
	linkStack(){head = tail = NULL;}

	bool isEmpty(){return head == NULL;}

	void push(const elemType &x)
	{
		if(head == NULL) head = new node(x);
		else
		{
			node *tem = new node(x);
			tem->next = head->next;
			head->next = tem;
		}

	}
	elemType pop()
	{
		node *tem = head;
		elemType x = tem->data;
		head = tem->next;
		delete tem;
		return x;
	}

};


template<class elemType>
class Tree
{
private:
	struct node
	{
		elemType data;
		node* firstson;
		node* nextBrother;
		node():firstson(NULL), nextBrother(NULL){}
		node(const elemType x):firstson(NULL), nextBrother(NULL){data = x;}
	};
	node* root;

	node* create(int rootNum, int *lchildren, int *rbrother, elemType *value,int nouse)
	{
		node *tem = new node(value[rootNum]);
		if(lchildren[rootNum] != 0)
			tem->firstson = create(lchildren[rootNum], lchildren, rbrother, value, 0);
		if(rbrother[rootNum]!= 0)
			tem->nextBrother = create(rbrother[rootNum], lchildren, rbrother, value, 0);
		return tem;
	}

	void postOrder(node *cur)
	{
		if(cur != NULL)
		{
			postOrder(cur->firstson);
			cout<<cur->data<<" ";
			postOrder(cur->nextBrother);
		}
	}
	void preOrder(node *cur)
	{
		if(cur != NULL)
		{
			cout<<cur->data<<" ";
			preOrder(cur->firstson);
			preOrder(cur->nextBrother);
		}
	}



public:
	void create(int rootNum, int *lchildren, int *rbrother, elemType *value)
	{
		root = new node(value[rootNum]);
		if(lchildren[rootNum] != 0)
			root->firstson = create(lchildren[rootNum], lchildren, rbrother, value, 0);
		if(rbrother[rootNum]!= 0)
			root->nextBrother = create(rbrother[rootNum], lchildren, rbrother, value, 0);
	}

	void preOrder()
	{
		if(root != NULL)
		{
			cout<<root->data<<" ";
			preOrder(root->firstson);
			preOrder(root->nextBrother);
		}
		cout<<endl;
	}

	void postOrder()
	{
		if(root != NULL)
		{
			postOrder(root->firstson);
			cout<<root->data<<" ";
			postOrder(root->nextBrother);
		}
		cout<<endl;
	}

	void levelPrint()
	{
		linkQueue<node*> q;
		q.enQueue(root);

		while(!q.isEmpty())
		{
			linkQueue<node*> curQue;

			while(!q.isEmpty()) curQue.enQueue(q.deQueue());

			while(!curQue.isEmpty())
			{
				node *tem = curQue.deQueue();
				while(tem != NULL)
				{
					if(tem->firstson != NULL) q.enQueue(tem->firstson);
					cout<<tem->data<<" "; tem = tem->nextBrother;

				}
			}

		}






	}

};




int main()
{
    int n;
    cin>>n;
	int *lchildren = new int[n+1], *rbrother = new int[n+1], *value = new int[n+1], *findRoot = new int[n+1];
    int l, r, v, rootNum = 0;
     for(int i = 1; i <= n; i++) findRoot[i] = 0;
    for(int i = 1; i <= n; i++)
	{
		cin>>l>>r>>v;
		lchildren[i] = l; rbrother[i] = r; value[i] = v;
		findRoot[l] = 1; findRoot[r] = 1;
	}

    for(int i = 1; i <= n; i++)
		if(findRoot[i] == 0) {rootNum = i;}
	Tree<int> t;
	t.create(rootNum, lchildren, rbrother, value);

	t.preOrder();
	t.postOrder();
	t.levelPrint();







    return 0;
}
