#include <iostream>

using namespace std;


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
		elemType x = head->data;
		head = head->next;
		if(head == NULL) tail = NULL;
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


int main()
{
	int n, i,f, *leftson, *rightson;
	cin>>n;
	leftson = new int[n]; rightson = new int[n];
	for(i = 0; i < n; i++)
	{
		leftson[i] = rightson[i] = -1;
	}

	for(i = 1; i < n ;i++)
	{
		cin>>f;
		if(leftson[f] == -1) leftson[f] = i;
		else rightson[f] = i;
	}


	int curNum = 1, x;
	linkQueue<int> q;
	q.enQueue(0);
	while(!q.isEmpty())
	{
		x = q.deQueue();
		if(leftson[x] != -1)
		{
			q.enQueue(leftson[x]);curNum++;
		}
		if(rightson[x] != -1)
		{
			q.enQueue(rightson[x]);curNum++;
		}

		if(leftson[x] == -1 or rightson[x] == -1) break;
	}

	if(curNum == n) cout<<"true";
	else cout<<"false";


    return 0;
}
