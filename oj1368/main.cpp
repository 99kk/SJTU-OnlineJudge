#include <iostream>

using namespace std;


//AC

#define elemType int

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
	int curLength;
	int lastVistPos;
	node *lastVist;

	node*lastVisit(){ node *tem = lastVist; lastVistPos++; lastVist = lastVist->next; return tem; }

	node* move(int i)
	{
		if(i == 0) return head;
		node *p = head->next;
		for( int k = 1; k < i; k++) p = p->next;
		return p;
	}

public:
	linkStructure(){head = tail = new node();curLength = 0;lastVistPos = 0;lastVist = NULL;}

	//common
	bool isEmpty(){ return head == NULL; }

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


	void create(int n)
	{
		node *p = head;
		for(int i = 1; i <= n; i++)
		{
			node*tem = new node(i);
			p->next = tem;
			p = tem;
		}
	}





	void insert(int i,elemType x)
	{

		node *p;
		p = move(i-1);

		node *tem = new node(x);
		tem->next = p->next;
		p->next = tem;


	}

	void deleteMonkey(int i)
	{
		node* tem = move(i-1);
		tem->next = tem->next->next;
	}

	int sum()
	{
		node *p = head->next;
		int sum = 0;
		while(p != NULL)
		{
			sum += p->data;
			p = p->next;
		}
		return sum;
	}






};



int main()
{
	int n,m;
	cin>>n>>m;

	linkStructure monkeys;
	monkeys.create(n);

	int op, k, w, curPos = 1;



	for(int i = 0; i < m; i++)
	{

		cin>>op;
		if(op == 0)
		{
			cin>>k;
			curPos = (curPos + k - 1) % n; if(curPos == 0) curPos = n;
			monkeys.deleteMonkey(curPos);
			n--;

		}
		else
		{
			cin>>k>>w;
			curPos = (curPos + k ) % n;if(curPos == 0) curPos = n;

			monkeys.insert(curPos, w);
			n++;



		}






	}
	cout<<monkeys.sum();







    return 0;
}
