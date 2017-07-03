#include <iostream>
#define elemType int

using namespace std;
//AC

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


int main()
{
    int n, p, q, buswait = 0, vanwait = 0, carsUp = 0, time = 0, busUP, vanUP, busNum = 0, vanNum = 0;
    double a, b;
    linkQueue bus, van;

    cin>>n;
    for(int i = 0; i < n; i++)
	{
		cin>>p>>q;
		if(p == 0) {bus.enQueue(q);busNum++;}
		else {van.enQueue(q);vanNum++;}
	}

	int bbbbb, vvvvv;
	for(time = -10; !bus.isEmpty() or !van.isEmpty() ;time+=10)
	{
		carsUp = 0;busUP = 0; vanUP = 0;
		for(int i = 0; i < 4 and !bus.isEmpty() and bus.getHead() <= time +10; i++)
		{	bbbbb = bus.deQueue();   buswait += time + 10 -bbbbb; carsUp ++; busUP++; }

		if(busUP == 4 and !van.isEmpty() and van.getHead() < time +10)
		{	vvvvv = van.deQueue(); vanwait += time + 10 - vvvvv; carsUp++;vanUP++; }
		else
			while(carsUp != 5 and !van.isEmpty() and van.getHead()<= time+10)
			{	vvvvv = van.deQueue(); vanwait += time + 10 - vvvvv; carsUp++;vanUP++; }

		for(int i = 0; i < 4 and !bus.isEmpty() and bus.getHead() <= time +10; i++)
		{	bbbbb = bus.deQueue();   buswait += time + 10 - bbbbb ; carsUp ++;busUP++; }

		if(busUP == 8 and !van.isEmpty() and van.getHead()<= time-10)
		{	vvvvv = van.deQueue(); vanwait += time + 10 - vvvvv; carsUp++;vanUP++; }

		else
			while(carsUp != 10 and !van.isEmpty() and van.getHead()<= time+10)
			{	vvvvv = van.deQueue();vanwait += time + 10 - vvvvv; carsUp++;vanUP++; }
	}

	a = float(buswait)/busNum;
	b = float(vanwait)/vanNum;
	cout.precision(3);
	cout.setf(ios::fixed);
	cout<<a<<endl<<b<<endl;





    return 0;
}
