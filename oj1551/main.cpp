#include <iostream>

using namespace std;


//AC
class linkStack
{
private:
	struct node
	{
		int data;
		node *next;
		node(int x):next(NULL),data(x){}
		node():next(NULL){}
		~node(){}
	};
	node*head;

public:
	linkStack(){head = new node();}
	void push(int x)
	{
		node*tem = new node(x);
		tem->next = head->next;
		head->next = tem;
	}
	int pop()
	{
		node* tem = head->next;
		head->next = tem->next;
		return tem->data;
	}

	int top(){ return head->next->data; }

	bool isEmpty(){ return head->next == NULL; }

	int getNum() {
	node *p = head->next;
	int num = 0;
	while(p != NULL)
	{
		p = p->next;
		num++;
	}
	return num;
	}
};



int main()
{

	int n, p, v;
	cin>>n;
	linkStack run;
	cin>>p>>v;
	run.push(v);
	for(int i = 1; i < n; i++)
	{
		cin>>p>>v;
		while(  !run.isEmpty() and v < run.top() )
		{
			run.pop();
		}
		run.push(v);
	}
	cout<<run.getNum();

    return 0;
}
