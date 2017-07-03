#include <iostream>

using namespace std;

//ac

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

int res[500], num = 1;
void doubleDanger()
{
	int i, carry = 0, cur;
	for(i = 0; i< 500; i++)
	{
		cur = res[i];
		res[i] = res[i] * 2 % 10 + carry;
		carry = cur * 2 / 10;
	}
}

int main()
{
    int n, m, i, j, a,b, *mix;
    long long danger = 1;
    res[0] = 1;
    for(i = 1; i <500; i++) res[i] = 0;
    cin>>n>>m;
    bool *visted = new bool[n+1];
    for(i = 0; i < n+1; i++) visted[i] = false;
    mix = new int[(n+1)*(n+1)];
    for(i = 0; i <=(n+1)*(n+1); i++ ) mix[i] = 0;
    for(i = 0; i <m; i++)
	{
		cin>>a>>b;
		mix[a*n+b] = 1;
		mix[b*n+a] = 1;
	}
	linkQueue<int> q;
	int x;
	while(true)
	{
		 for(i = 1; i < n+1; i++) if(!visted[i]) {visted[i] = true; q.enQueue(i); break;}
		 if(i == n+1) break;
		 while(!q.isEmpty())
		 {
		 	x = q.deQueue();
		 	for(i = 1; i <= n; i++)
			{
				if(mix[x*n+i] == 1 and !visted[i])
				{q.enQueue(i);visted[i] = true; doubleDanger();}
			}
		 }

	}

	for(i = 500; i >= 0; i--) if(res[i] != 0) break;

	for(;i>=0; i--)cout<<res[i];


    return 0;
}
