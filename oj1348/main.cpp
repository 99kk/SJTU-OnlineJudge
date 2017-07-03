#include <iostream>

using namespace std;
#define elemType int

//Wrong answer 题目有问题

class linkStructure
{
private:
	struct node
	{
		elemType data;
		node*next;
		node():next(NULL){}
		node(const elemType &x):data(x),next(NULL){}
	};

	node* head;
	node* tail;

	void swap(node *p, node *q)
	{
		elemType tem = p->data;
		p->data = q->data;
		q->data = tem;
	}

	node *slice(node *low, node *high)
	{
		elemType key = low->data;
		node*p = low, *q = low->next;
		while(q != high)
		{
			if(q->data < key)
			{
				p = p->next;
				swap(p, q);

			}
			q = q->next;
		}
		if(q->data < key) swap(q,p);
		swap(low, p);
		return p;
	}

	void quickSort(node *low, node* high)
	{
		if(low != high and low != NULL and high != NULL)
		{
			node *p = slice(low, high);
			quickSort(low, p);
			quickSort(p->next, high);
		}
	}


public:
	linkStructure(){head = tail = new node();}

	void quickSort(){ quickSort(head->next, tail); }

	//common
	bool isEmpty(){ return head->next == NULL; }

	void print()
	{
		node* p = head->next;
		while(p != NULL)
		{
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}


	//linkStack
	void push(const elemType &x)
	{
		node* tem = new node(x);
		tem->next = head->next;
		head->next = tem;
	}

	elemType pop()
	{
		node*tem = head->next;
		elemType x = tem->data;
		head->next = tem->next;
		delete tem;
		return x;
	}

	elemType top() { return head->next->data; }


	//linkQueue
	void enQueue(const elemType &x)
	{
		node* tem = new node(x);
		tail->next = tem;
		tail = tem;
	}

	elemType deQueue()
	{
		node* tem = head->next;
		head->next = tem->next;
		elemType x = tem->data;
		delete tem;
		return x;
	}

	//linkList

};




int main()
{
    int n, *li, m, gender, t, clock = 0;
    cin>>n;
    li = new int[n];
    for(int i = 0; i < n; i++)
		cin>>li[i];

	cin>>m;

	linkStructure boys, girls;
	int boyWait = 0, girlWait = 0, boyNum = 0, girlNum = 0;

	for(int i = 0; i < m; i++)
	{
		cin>>gender>>t;
		if(gender == 1) {boys.enQueue(t);boyNum++;}
		else {girls.enQueue(t);girlNum++;}
	}

	boys.quickSort();
	girls.quickSort();

	for(int i = 0; i < n; i++)
	{
		while(!boys.isEmpty() and !girls.isEmpty() and boys.top()<=clock and girls.top() <= clock)
		{
			boyWait += clock - boys.deQueue();
			girlWait += clock - girls.deQueue();

		}
		clock += li[i];
	}
/*
	//clock -= li[n-1];
	while(!boys.isEmpty() and !girls.isEmpty())
	{
		boyWait += clock - boys.deQueue();
			girlWait += clock - girls.deQueue();
	}
*/
	float boyAverage, girlAverage;
	boyAverage = float(boyWait) / boyNum;
	girlAverage = float(girlWait) / girlNum;

	cout.precision(2);
	cout.setf(ios::fixed);

	cout<<boyAverage<<" "<<girlAverage;




    return 0;
}
